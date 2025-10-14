



#include "funciones.h"
#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>


using namespace std;

int* crearCopia(const int arr[], int size) {
    int* copia = new int[size];
    for (int i = 0; i < size; ++i) {
        copia[i] = arr[i];
    }
    return copia;
}



void llenar(int arr [], int tam) {
    for (int i = 0;i < tam; ++i) {
        arr[i] = rand() % 100 + 1;
    }
}
void Mostrar(const int arr [], int tam) {

    cout << "El contenido del arreglo de tamano "<< tam << " es:" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << i+1 << ".- " << arr[i] << endl;
    }
    cout << endl;
}

void BuscarSecuencial(const int arr [], int tam, int valor) {
    bool encontrado = false;
    int posicion = -1;
    for (int i = 0; i < tam; ++i) {
        if (arr[i] == valor) {
            encontrado = true;
            posicion = i;
        }
    }
    if (encontrado) {
        cout << "El valor " << valor << " fue encontrado en la posicion " << posicion+1 << "." << endl;
    } else {
        cout << "El valor " << valor << " no se encuentra en el arreglo." << endl;
    }
}

void OrdenarBurbuja(const int arr [], int tam) {
    int* copia = crearCopia(arr, tam);

    for (int i = 0; i < tam - 1; ++i) {
        for (int j = 0; j < tam - i - 1; ++j) {
            if (copia[j] > copia[j + 1]) {
                swap(copia[j], copia[j + 1]);
            }
        }
    }
    Mostrar(copia, tam);
    delete[] copia;
}
void OrdenarInserccion(const int arr [], int tam) {
    int* copia = crearCopia(arr, tam);

    for (int i = 1; i < tam; ++i) {
        int clave = copia[i];
        int j = i - 1;
        while (j >= 0 && copia[j] > clave) {
            copia[j + 1] = copia[j];
            j = j - 1;
        }
        copia[j + 1] = clave;
    }
    Mostrar(copia, tam);
    delete[] copia;
}

void OrdenarSeleccion(const int arr [], int tam) {
    int* copia = crearCopia(arr, tam);

    for (int i = 0; i < tam - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < tam; ++j) {
            if (copia[j] < copia[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(copia[min_idx], copia[i]);
        }
    }
    Mostrar(copia, tam);
    delete[] copia;

}


