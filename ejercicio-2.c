#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILA 5
#define COLUMNA 12

void cargarGanancia(int m[][COLUMNA], int f, int c);
void mostrarGanancia(int m[][COLUMNA], int f, int c);
void promedioPorAnio(int m[][COLUMNA], int f, int c);
void minMax(int m[][COLUMNA], int f, int c);

int main()
{
    srand(time(NULL));
    int ganancia[FILA][COLUMNA];
    cargarGanancia(ganancia, FILA, COLUMNA);
    mostrarGanancia(ganancia, FILA, COLUMNA);
    promedioPorAnio(ganancia, FILA, COLUMNA);
    minMax(ganancia, FILA, COLUMNA);
    return 0;
}

void cargarGanancia(int m[][COLUMNA], int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = rand() % (50000 - 10000 + 1) + 10000;
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

void promedioPorAnio(int m[][COLUMNA], int f, int c)
{
    int sum = 0;
    float result;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += m[i][j];
        }
        result = sum / c;
        sum = 0;
        printf("promedio del anio %d: %.2f\n", i + 1, result);
    }
}

void minMax(int m[][COLUMNA], int f, int c)
{
    int min = 50000;
    int max = 10000;
    int mesMin;
    int anioMin;
    int mesMax;
    int anioMax;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (max < m[i][j])
            {
                max = m[i][j];
                anioMax = i+1;
                mesMax = j+1;
            }

            if (min > m[i][j])
            {
                min = m[i][j];
                anioMin = i+1;
                mesMin = j+1;
            }
        }
    }

    printf("el minimo es: %d en el anio %d en el mes %d\n", min, anioMin, mesMin);
    printf("el maximo es: %d en el anio %d en el mes %d\n", max, anioMax, mesMax);
}