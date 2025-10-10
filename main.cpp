
#include <iostream>
#include <cstdlib>
#include "funciones.h"

int main() {
    using namespace std;
    srand(time(NULL));

    cout << "Bienvenido al programa de metodos de ordenamiento\n";

    int tam;
    int opc;
    cout << "Dame el tamaño del arreglo\n";
    cin >> tam;

    int arreglo[tam];

    llenarArregloAleatorio(arreglo, tam);


    cout << "El contenido del arreglo generado es: \n";
    for (int i = 0; i < tam; ++i) {
        cout << arreglo[i] << endl;
    }
    cout << endl;

    cout << "seleccione una opcion para ordenar la matriz generada" << endl;
    cout << "Busqueda secuencial" <<endl;
    cout << "Busqueda Binaria" << endl;

    cin >> opc;

    switch (opc) {
        case 1:
            cout << "hola1" << endl;
            break;
        case 2:
            cout << "hola2" << endl;
            break;
    }


    return 0;
}
