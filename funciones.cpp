



#include "funciones.h"
#include <random>
#include <ctime>


void llenarArregloAleatorio(int arr [], int tam) {
    for (int i = 0;i < tam; ++i) {
        arr[i] = rand() % 1000000 + 1;
    }
}