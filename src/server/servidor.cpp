#include <iostream>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <signal.h>
#include "../include/common/game_logic.h"

using namespace std;

const int MAX_CLIENTS = 10;

void enviarTablero(int client_socket, const vector<vector<int>> &tablero)
{
    for (const auto &fila : tablero)
    {
        send(client_socket, fila.data(), fila.size() * sizeof(int), 0);
    }
}

void handleClient(int client_socket, struct sockaddr_in client_addr)
{
    vector<vector<int>> matriz(N, vector<int>(M, 0));
    int jugador = 0, ultimo = 0;
    bool hayGanador = false;
    bool hayEmpate = false;
    srand(time(0));
    jugador = rand() % 2 + 1; // Elegir al azar quién comienza

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    int client_port = ntohs(client_addr.sin_port);
    cout << "Juego nuevo[" << client_ip << ":" << client_port << "]" << endl;

    while (!hayGanador && sobranEspaciosLibres(matriz))
    {
        int colocarColumna = -1;

        // Enviar turno al cliente
        send(client_socket, &jugador, sizeof(jugador), 0);

        if (jugador == 2)
        { // Turno del cliente
            int n = recv(client_socket, &colocarColumna, sizeof(colocarColumna), 0);
            if (n <= 0)
            {
                cout << "El jugador [" << client_ip << ":" << client_port << "] se ha retirado." << endl;
                close(client_socket);
                exit(0);
            }
        }
        else
        { // Turno del servidor
            do
            {
                colocarColumna = rand() % M;
            } while (columnaATope(matriz, colocarColumna));
            cout << "Turno del servidor, elige columna: " << (colocarColumna + 1) << endl;
        }

        if (columnaATope(matriz, colocarColumna))
        {
            int error = -1;
            send(client_socket, &error, sizeof(error), 0);
            continue;
        }

        int colocarFila = colocarFichaEn(matriz, colocarColumna);
        matriz[colocarFila][colocarColumna] = jugador;
        enviarTablero(client_socket, matriz);

        if (ganador(matriz, colocarFila, colocarColumna, jugador))
        {
            int resultado = jugador;
            send(client_socket, &resultado, sizeof(resultado), 0);
            cout << "El jugador " << jugador << " gana!" << endl;
            hayGanador = true;
            break;
        }
        else if (!sobranEspaciosLibres(matriz))
        {
            hayEmpate = true;
            break;
        }
        else
        {
            int resultado = 0;
            send(client_socket, &resultado, sizeof(resultado), 0);
        }

        ultimo = jugador;
        jugador = (jugador == 1) ? 2 : 1; // Alternar turnos
    }

    if (hayEmpate)
    {
        int resultado = 3; // Código para empate
        send(client_socket, &resultado, sizeof(resultado), 0);
        cout << "El juego ha terminado en empate." << endl;
    }

    close(client_socket);
    exit(0);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Uso: " << argv[0] << " <puerto>" << endl;
        return 1;
    }

    int server_fd, new_socket;
    struct sockaddr_in address, client_addr;
    int opt = 1;
    int addrlen = sizeof(address);
    int client_addrlen = sizeof(client_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    cout << "Esperando conexiones ..." << endl;

    while (true)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == 0)
        {
            close(server_fd);
            handleClient(new_socket, client_addr);
        }
        else if (pid < 0)
        {
            perror("fork failed");
        }

        close(new_socket);
    }

    return 0;
}
