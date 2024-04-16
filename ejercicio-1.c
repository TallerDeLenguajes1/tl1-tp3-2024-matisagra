#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILA 5
#define COLUMNA 12

void cargarGanancia(int m[][COLUMNA], int f, int c);
void mostrarGanancia(int m[][COLUMNA], int f, int c);

int main()
{
    srand(time(NULL));
    int ganancia[FILA][COLUMNA];
    cargarGanancia(ganancia, FILA, COLUMNA);
    mostrarGanancia(ganancia, FILA, COLUMNA);
    return 0;
}

void cargarGanancia(int m[][COLUMNA], int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = rand() % (50000 - 10000 +1) + 10000;
        }
    }
}

void mostrarGanancia(int m[][COLUMNA], int f, int c)
{
     for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\n", m[i][j]);
        }
    }
}