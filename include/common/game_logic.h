#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <vector>

const int N = 6; // Número de filas del tablero
const int M = 7; // Número de columnas del tablero

// Verifica si hay espacios libres en el tablero
bool sobranEspaciosLibres(const std::vector<std::vector<int>> &tablero);

// Imprime el estado actual del tablero
void imprimirTablero(const std::vector<std::vector<int>> &tablero);

// Coloca una ficha en la columna especificada y devuelve la fila donde cayó la ficha
int colocarFichaEn(std::vector<std::vector<int>> &tablero, int columna);

// Verifica si una columna está llena
bool columnaATope(const std::vector<std::vector<int>> &tablero, int columna);

// Verifica si hay un ganador después de la última jugada
bool ganador(const std::vector<std::vector<int>> &tablero, int fila, int columna, int jugador);

#endif // GAME_LOGIC_H
