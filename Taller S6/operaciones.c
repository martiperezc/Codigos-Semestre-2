#include <stdio.h>
#include <string.h>
#include "operaciones.h"
#include "Validaciones.h"


void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        //Implementamos funcion que valida el nombre de un producto.
        obtener_texto_valido("Ingrese el nombre de su producto: \n", nombres[i], sizeof(MAX_NOMBRE));
        printf("precio del producto %i: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += precios[i];
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

int indiceMasCaro(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] > precios[indice])
            indice = i;
    return indice;
}

int indiceMasBarato(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] < precios[indice])
            indice = i;
    return indice;
}

int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0)
            return i;
    }
    return -1;
}
