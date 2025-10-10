
#include <iostream>
#include <cstdlib>
#include "funciones.h"

int main() {
    using namespace std;
    srand(time(NULL));

    cout << "Bienvenido al programa de metodos de ordenamiento\n";

    int tam;
    cout << "Dame el tamaño del arreglo\n";
    cin >> tam;

    int arreglo[tam];

    llenarArregloAleatorio(arreglo, tam);


    cout << "El contenido del arreglo generado es: \n";
    for (int i = 0; i < tam; ++i) {
        cout << arreglo[i] << endl;
    }
    cout << endl;



    return 0;
}
