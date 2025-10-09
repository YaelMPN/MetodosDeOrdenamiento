//
// Created by yayo-lin on 9/10/25.
//







#include <iostream>
#include <vector>       // Para poder usar std::vector
#include "funciones.h"  // Incluimos el archivo con nuestras declaraciones

int main() {
    using namespace std;

    cout << "Bienvenido al programa de metodos de ordenamiento\n";

    int tam;
    cout << "Dame el tamaño del arreglo\n";
    cin >> tam;

    // Creamos un vector del tamaño que el usuario indicó.
    // Es más seguro y flexible que un arreglo C-style.
    vector<int> arreglo(tam);

    // Llamamos a la función para que llene nuestro vector con números aleatorios.
    llenarArregloAleatorio(arreglo);

    // Imprimimos el contenido del vector para verificar.
    cout << "El contenido del arreglo generado es: \n";
    for (int i = 0; i < arreglo.size(); ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl; // Para un salto de línea al final

    // cout << "Eliga "; // Aquí continuarías con el resto de tu programa

    return 0;
}
