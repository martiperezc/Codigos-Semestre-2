#include "Validaciones.h"

// Implementación de la función auxiliar
void eliminar_salto_linea(char *cadena) {
    cadena[strcspn(cadena, "\n")] = 0;
}

// 1. Implementación para validar TEXTO (Solo letras)
void obtener_texto_valido(const char *mensaje, char *destino, int tamano) {
    char buffer[256]; // Buffer temporal
    int es_valido;

    do {
        es_valido = 1; // Asumimos que es válido al iniciar el ciclo
        
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue; // Error de lectura, reintentar
        }
        
        eliminar_salto_linea(buffer);

        // Validación: Cadena vacía
        if (strlen(buffer) == 0) {
            printf(">> Error: El dato no puede estar vacio.\n");
            es_valido = 0;
            continue; // Vuelve al inicio del do-while
        }

        // Validación: Carácter por carácter
        for (int i = 0; buffer[i] != '\0'; i++) {
            // Si NO es letra Y NO es espacio
            if (!isalpha(buffer[i]) && !isspace(buffer[i])) {
                printf(">> Error: '%c' no es valido. Ingrese solo letras.\n", buffer[i]);
                es_valido = 0;
                break; // Sale del for, pero sigue en el do-while
            }
        }

    } while (es_valido == 0); // Si es_valido es 0 (Falso), repite

    // Si llegamos aquí, todo está bien. Copiamos al destino final.
    strncpy(destino, buffer, tamano - 1);
    destino[tamano - 1] = '\0'; // Asegurar terminador nulo
}


// 2. Implementación para validar ENTEROS
int obtener_entero_valido(const char *mensaje) {
    char buffer[100];
    int es_valido;
    int resultado = 0;

    do {
        es_valido = 1;
        printf("%s", mensaje);
        fgets(buffer, sizeof(buffer), stdin);
        eliminar_salto_linea(buffer);

        // Validación: Cadena vacía
        if (strlen(buffer) == 0) {
            es_valido = 0;
        }

        // Validación: Revisar si es número
        for (int i = 0; buffer[i] != '\0'; i++) {
            // Permitimos el signo negativo '-' solo en la primera posición
            if (i == 0 && buffer[i] == '-') {
                continue;
            }
            // Si no es un dígito
            if (!isdigit(buffer[i])) {
                printf(">> Error: '%s' no es un numero entero valido.\n", buffer);
                es_valido = 0;
                break;
            }
        }
        
        // Si estaba vacío tras chequear
        if(es_valido && strlen(buffer) == 0) {
             printf(">> Error: Debe ingresar un valor.\n");
             es_valido = 0;
        }

    } while (es_valido == 0);

    // Convertir la cadena validada a entero
    resultado = atoi(buffer);
    return resultado;
}

