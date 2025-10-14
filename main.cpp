
#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include <algorithm>


int main() {
    using namespace std;

    srand(time(NULL));

    cout << "Bienvenido al programa de metodos de ordenamiento\n";

    int tam;
    int opc;
    cout << "Dame el tamano del arreglo\n";
    cin >> tam;

    int* arreglo = new int[tam];

    llenar(arreglo, tam);

    do {
        Mostrar(arreglo, tam);




        cout << "seleccione una opcion" << endl;
        cout << "1. Buscar Secuencial" << endl;
        cout << "2. Ordenar Burbuja" << endl;
        cout << "3. Ordenar Inserccion" << endl;
        cout << "4. Ordenar Seleccion" << endl;




        cin >> opc;
        int valor;

        switch (opc) {

            case 1:
                cout << "Ingrese el valor a buscar" << endl;
                cin >> valor;

                BuscarSecuencial(arreglo, tam, valor);


                break;

            case 2:
                cout << "el valor del nuevo arreglo ordenado por burbuja es" << endl;
                OrdenarBurbuja(arreglo, tam);
                break;
            case 3:
                cout << "el valor del nuevo arreglo ordenado por inserccion es" << endl;
                OrdenarInserccion(arreglo, tam);

                break;
            case 4:
                cout << "el valor del nuevo arreglo ordenado por Seleccion es" << endl;
                OrdenarSeleccion(arreglo, tam);
                break;
        }
    }while(opc != 0);
    delete[] arreglo;

    return 0;
}
