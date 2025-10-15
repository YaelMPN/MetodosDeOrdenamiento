/*funcioens.h
Pérez Nava Yael Mauricio
Fecha de Compilacion: 14/10/25
Programa: archivo de cabecera que une el main con el funciones
*/
#ifndef METODOSDEORDENAMIENTO_FUNCIONES_H
#define METODOSDEORDENAMIENTO_FUNCIONES_H




void llenar(int arr[], int tam);
void Mostrar(const int arr[], int tam, const char* titulo); // Añadido un título para claridad

// Funciones de Búsqueda
void BuscarSecuencial(const int arr[], int tam, int valor);
void BuscarBinaria(const int arr[], int tam, int valor);

// Funciones de Ordenamiento (Ahora devuelven el arreglo ordenado)
int* OrdenarBurbuja(const int arr[], int tam);
int* OrdenarSeleccion(const int arr[], int tam);
int* OrdenarInserccion(const int arr[], int tam);

#endif //METODOSDEORDENAMIENTO_FUNCIONES_H