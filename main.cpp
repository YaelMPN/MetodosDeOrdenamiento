/*main.c++
Pérez Nava Yael Mauricio
Fecha de Compilacion: 14/10/25
Programa: main del programa de ordenamientos, se llaman a todas las funciones
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>  // Para medir el tiempo
#include <limits>  // Para limpiar el buffer de entrada para que no se rompa el coso este

#include "funciones.h"

using namespace std;

// Función para pausar la ejecución y esperar al usuario en caso de equivocarse
void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.get();
}
int main() {
    srand(time(NULL)); // Inicializar semilla para números aleatorios
    cout << "Perez Nava Yael Mauricio 3NM30" <<endl;
    cout << "Bienvenido al programa de metodos de ordenamiento y busqueda\n";
    int tam;
    cout << "Dame el tamano del arreglo: ";
    cin >> tam;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //para el buffer y que no haga cosas raras

    int* arregloOriginal = new int[tam];  //creacion del arreglo original
    llenar(arregloOriginal, tam);         //se llena el arreglo original con numeros random

    int opcPrincipal;
    do {
        if (tam <= 1000) {
            Mostrar(arregloOriginal, tam, "Arreglo Original");
        } else {
            cout << "--- Arreglo de " << tam << " elementos cargado (visualizacion omitida por practicidad). ---" << endl << endl;
        }

        cout << "--- MENU PRINCIPAL ---" << endl;
        cout << "1. Busqueda Secuencial" << endl;
        cout << "2. Ordenar con Burbuja" << endl;
        cout << "3. Ordenar con Insercion" << endl;
        cout << "4. Ordenar con Seleccion" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcPrincipal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//para el buffer y que no haga cosas raras

        int* arregloOrdenado = nullptr; // Puntero para el arreglo que se ordenará

        switch (opcPrincipal) {
            //Busqueda secuencial
            case 1: {
                system("cls");
                if (tam <= 1000) {
                    Mostrar(arregloOriginal, tam, "Arreglo Original");
                } else {
                    cout << "--- Arreglo de " << tam << " elementos cargado (visualizacion omitida por practicidad). ---" << endl << endl;
                }
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');//para el buffer y que no haga cosas raras

                //se usa dentro de la llamada a la funcion para ver el tiempo de ejecucion de esa parte
                auto start_bs = chrono::high_resolution_clock::now();
                BuscarSecuencial(arregloOriginal, tam, valor);
                auto end_bs = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> duration_bs = end_bs - start_bs;
                cout << ">> Tiempo de busqueda secuencial: " << duration_bs.count() << " ms" << endl;

                int opcSub;
                cout << "\n1. Volver al menu principal" << endl;
                cout << "2. Salir del programa" << endl;
                cout << "Opcion: ";
                cin >> opcSub;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');//para el buffer y que no haga cosas raras
                if (opcSub == 2) {
                    opcPrincipal = 5; // Forzar salida del bucle principal
                }
                break;
            }
            case 2: // Ordenamiento Burbuja
            case 3: // Ordenamiento Inserción
            case 4: { // Ordenamiento Selección
                system("cls");

                auto start = chrono::high_resolution_clock::now(); // Iniciar cronómetro
                //aqui se llaman al resto de funciones de ordenamiento segun sea el caso
                const char* metodoNombre;
                if (opcPrincipal == 2) {
                    arregloOrdenado = OrdenarBurbuja(arregloOriginal, tam);
                    metodoNombre = "Burbuja";
                } else if (opcPrincipal == 3) {
                    arregloOrdenado = OrdenarInserccion(arregloOriginal, tam);
                    metodoNombre = "Insercion";
                } else { // opcPrincipal == 4
                    arregloOrdenado = OrdenarSeleccion(arregloOriginal, tam);
                    metodoNombre = "Seleccion";
                }

                auto end = chrono::high_resolution_clock::now(); // Detener cronómetro
                chrono::duration<double, milli> duration = end - start;

                if (tam <= 1000) {
                    Mostrar(arregloOriginal, tam, "Arreglo Original");
                    Mostrar(arregloOrdenado, tam, "Arreglo Ordenado");
                } else {
                    cout << "--- Arreglo de " << tam << " elementos cargados (visualizacion omitida por practicidad). ---" << endl << endl;
                }



                cout << ">> Tiempo de ejecucion del metodo " << metodoNombre << ": " << duration.count() << " ms" << endl;//se imprime cuanto tardo cualquiera de los 3 metodos

                int opcSub;
                do {
                    cout << "\n--- MENU DE ORDENAMIENTO ---" << endl;
                    cout << "1. Realizar Busqueda Binaria en el arreglo ordenado" << endl;
                    cout << "2. Volver al menu principal" << endl;
                    cout << "3. Salir del programa" << endl;
                    cout << "Opcion: ";
                    cin >> opcSub;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');//para el buffer y que no haga cosas raras

                    if (opcSub == 1) {
                        int valor;
                        cout << "\nIngrese el valor a buscar (busqueda binaria): ";
                        cin >> valor;

                        //se usa dentro de la llamada a la funcion para ver el tiempo de ejecucion de esa parte
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        auto start_bb = chrono::high_resolution_clock::now();
                        BuscarBinaria(arregloOrdenado, tam, valor);
                        auto end_bb = chrono::high_resolution_clock::now();
                        chrono::duration<double, milli> duration_bb = end_bb - start_bb;
                        cout << ">> Tiempo de busqueda binaria: " << duration_bb.count() << " ms" << endl;


                    } else if (opcSub == 3) {
                        opcPrincipal = 5; // Forzar salida del bucle principal
                    }

                } while (opcSub == 1); // El bucle se repite si elige búsqueda binaria

                delete[] arregloOrdenado; // Liberar memoria del arreglo ordenado
                break;
            }
            case 5:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion incorrecta. Intenta de nuevo." << endl;
                pausar();
                break;
        }

    } while (opcPrincipal != 5);

    delete[] arregloOriginal; // Liberar memoria del arreglo original al final
    return 0;
}
