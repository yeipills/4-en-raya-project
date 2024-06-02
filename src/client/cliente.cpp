#include <iostream>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/common/game_logic.h"

using namespace std;

int obtenerEntradaValida()
{
    string entrada;
    int columna;
    while (true)
    {
        cout << "Elige un número del 1 al 7: ";
        cin >> entrada;

        // Validar que la entrada sea un número
        try
        {
            columna = stoi(entrada);
        }
        catch (invalid_argument &)
        {
            cout << "Entrada inválida. ";
            continue;
        }

        // Validar que la columna esté en el rango permitido
        if (columna >= 1 && columna <= 7)
        {
            return columna - 1;
        }
        cout << "Entrada inválida. ";
    }
}

void recibirTablero(int sock, vector<vector<int>> &tablero)
{
    for (auto &fila : tablero)
    {
        read(sock, fila.data(), fila.size() * sizeof(int));
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cerr << "Uso: " << argv[0] << " <direccion IP> <puerto>" << endl;
        return 1;
    }

    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << "Error al crear el socket" << endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        cout << "Dirección IP inválida/No soportada" << endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << "Conexión fallida" << endl;
        return -1;
    }

    vector<vector<int>> tablero(N, vector<int>(M, 0));
    bool hayGanador = false;

    while (!hayGanador)
    {
        int jugador;
        read(sock, &jugador, sizeof(jugador));
        cout << "Turno del jugador " << (jugador == 1 ? "Servidor" : "Cliente") << endl;

        if (jugador == 2)
        { // Turno del cliente
            int colocarColumna = obtenerEntradaValida();
            send(sock, &colocarColumna, sizeof(colocarColumna), 0);
        }

        recibirTablero(sock, tablero);
        imprimirTablero(tablero);

        int resultado;
        read(sock, &resultado, sizeof(resultado));
        if (resultado == 1 || resultado == 2)
        {
            cout << "Gana el jugador " << (resultado == 1 ? "Servidor" : "Cliente") << endl;
            hayGanador = true;
        }
        else if (resultado == -1)
        {
            cout << "No hay espacio para colocar la ficha en la columna seleccionada. Inténtalo de nuevo." << endl;
            continue;
        }
    }

    close(sock);
    return 0;
}
