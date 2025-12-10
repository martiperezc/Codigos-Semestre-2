#include <stdio.h>
#include "validaciones.h" // Incluimos nuestro archivo header

int main() {
    char nombre[50];
    int num_entero;

    printf("Validaciones de entradas.c \n");

        //No devuelve un valor hasta que el string sea compuesto de caracteres.
        obtener_texto_valido("Ingrese su String: ", nombre, sizeof(nombre));

        //Funcion que devuelve el numero entero si este es un num entero.
        num_entero = obtener_entero_valido("Ingrese su numero entero: ");

        //Nota: Una vez que pasaron el test de validacion de datos, el valor ingresado se almacena directamente en las variable originales.
        // En este caso "char nombre[50]", y "int edad"


        printf("String: %s\n", nombre);
        printf("Num Entero:   %i\n", num_entero);

    return 0;
}