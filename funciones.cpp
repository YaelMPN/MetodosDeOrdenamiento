/*funciones.c++
Pérez Nava Yael Mauricio
Fecha de Compilacion: 14/10/25
Programa: logica de las funciones llamadas en main
*/
#include "funciones.h"
#include <iostream>
#include <chrono> // Para medir el tiempo
#include <algorithm> // Para std::swap

using namespace std;



// Crea una copia dinámica del arreglo original
int* crearCopia(const int arr[], int size) {
    int* copia = new int[size];
    for (int i = 0; i < size; ++i) {
        copia[i] = arr[i];
    }
    return copia;
}

// Llena el arreglo con números aleatorios del 1 al 100
void llenar(int arr [], int tam) {
    for (int i = 0; i < tam; ++i) {
        arr[i] = rand() % 100 + 1;
    }
}

// Muestra el contenido del arreglo con un título
void Mostrar(const int arr[], int tam, const char* titulo) {
    cout << "--- " << titulo << " ---" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl << endl;
}


// --- Funciones de Búsqueda ---

void BuscarSecuencial(const int arr[], int tam, int valor) {
    bool encontrado = false;
    int posicion = -1;
    for (int i = 0; i < tam; ++i) {
        if (arr[i] == valor) {
            encontrado = true;
            posicion = i;
            break; // Salimos del bucle al encontrarlo
        }
    }
    if (encontrado) {
        cout << "\n>> Resultado: El valor " << valor << " fue encontrado en la posicion " << posicion << "." << endl;
    } else {
        cout << "\n>> Resultado: El valor " << valor << " no se encuentra en el arreglo." << endl;
    }
}

void BuscarBinaria(const int arr[], int tam, int valor) {
    int izquierda = 0;
    int derecha = tam - 1;
    bool encontrado = false;
    int posicion = -1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == valor) {
            encontrado = true;
            posicion = medio;
            break;
        }
        if (arr[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    if (encontrado) {
        cout << "\n>> Resultado: El valor " << valor << " fue encontrado en la posicion " << posicion << "." << endl;
    } else {
        cout << "\n>> Resultado: El valor " << valor << " no se encuentra en el arreglo." << endl;
    }
}


// --- Funciones de Ordenamiento ---

int* OrdenarBurbuja(const int arr[], int tam, long long &comparaciones, long long &intercambios) {
    int* copia = crearCopia(arr, tam);
    for (int i = 0; i < tam - 1; ++i) {
        for (int j = 0; j < tam - i - 1; ++j) {
            // CADA VEZ que se ejecuta el if, es una comparación.
            comparaciones++;
            if (copia[j] > copia[j + 1]) {
                // Si entramos aquí, hacemos un intercambio.
                intercambios++;
                swap(copia[j], copia[j + 1]);
            }
        }
    }
    return copia;
}

int* OrdenarInserccion(const int arr[], int tam, long long &comparaciones, long long &movimientos) {
    int* copia = crearCopia(arr, tam);
    for (int i = 1; i < tam; ++i) {
        int clave = copia[i];
        int j = i - 1;

        // El while realiza comparaciones para encontrar la posición correcta.
        while (j >= 0) {
            comparaciones++;
            if (copia[j] > clave) {
                // Esto no es un intercambio, es un "movimiento" o "desplazamiento".
                movimientos++;
                copia[j + 1] = copia[j];
                j = j - 1;
            } else {
                // Si no es mayor, ya no necesitamos seguir comparando en este ciclo.
                break;
            }
        }
        copia[j + 1] = clave;
        // La inserción final también puede considerarse un movimiento.
        movimientos++;
    }
    return copia;
}

int* OrdenarSeleccion(const int arr[], int tam, long long &comparaciones, long long &intercambios) {
    int* copia = crearCopia(arr, tam);
    for (int i = 0; i < tam - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < tam; ++j) {
            // Cada vez que buscamos el mínimo, hacemos una comparación.
            comparaciones++;
            if (copia[j] < copia[min_idx]) {
                min_idx = j;
            }
        }
        // El intercambio solo se hace UNA VEZ por cada ciclo principal.
        if (min_idx != i) {
            intercambios++;
            swap(copia[min_idx], copia[i]);
        }
    }
    return copia;
}


