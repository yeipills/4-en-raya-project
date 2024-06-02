#include "../include/common/game_logic.h"
#include <iostream>

bool sobranEspaciosLibres(const std::vector<std::vector<int>> &tablero)
{
    for (const auto &fila : tablero)
    {
        for (int celda : fila)
        {
            if (celda == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void imprimirTablero(const std::vector<std::vector<int>> &tablero)
{
    for (const auto &fila : tablero)
    {
        for (int celda : fila)
        {
            if (celda == 1)
            {
                std::cout << " S ";
            }
            else if (celda == 2)
            {
                std::cout << " C ";
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}

int colocarFichaEn(std::vector<std::vector<int>> &tablero, int columna)
{
    for (int i = 0; i < N; i++)
    {
        if ((i + 1 >= N) || (tablero[i][columna] == 0 && tablero[i + 1][columna] != 0))
        {
            return i;
        }
    }
    return -1;
}

bool columnaATope(const std::vector<std::vector<int>> &tablero, int columna)
{
    if (tablero[0][columna] != 0)
    {
        std::cout << "No hay espacio para colocar la ficha ahí" << std::endl;
        return true;
    }
    return false;
}

bool ganador(const std::vector<std::vector<int>> &tablero, int fila, int columna, int jugador)
{
    auto contarFichas = [&](int df, int dc)
    {
        int total = 0;
        for (int i = -3; i <= 3; i++)
        {
            int ni = fila + i * df, nj = columna + i * dc;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && tablero[ni][nj] == jugador)
            {
                total++;
                if (total == 4)
                    return true;
            }
            else
            {
                total = 0;
            }
        }
        return false;
    };

    return contarFichas(1, 0) || contarFichas(0, 1) || contarFichas(1, 1) || contarFichas(1, -1);
}
