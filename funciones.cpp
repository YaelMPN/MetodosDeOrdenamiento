//
// Created by yayo-lin on 9/10/25.
//



#include "funciones.h" // Incluimos nuestra propia cabecera
#include <random>      // Para la generación de números aleatorios
#include <ctime>       // Para inicializar la semilla del generador

// Definición (implementación) de la función
void llenarArregloAleatorio(std::vector<int>& arr) {
    // 1. Creamos un generador de números aleatorios.
    // Usamos static para que no se cree cada vez que se llama a la función
    // y lo inicializamos con la hora actual para que no genere siempre la misma secuencia.
    static std::mt19937 generador(time(0));

    // 2. Definimos el rango de los números (de 1 a 10).
    std::uniform_int_distribution<int> distribucion(1, 10);

    // 3. Llenamos cada espacio del vector con un número aleatorio.
    // Usamos un bucle for de rango para mayor simplicidad.
    for (int& elemento : arr) {
        elemento = distribucion(generador);
    }
}