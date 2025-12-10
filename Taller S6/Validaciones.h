#ifndef Validaciones.h
#define Validaciones.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void eliminar_salto_linea(char *cadena);
int obtener_entero_valido(const char *mensaje);
void obtener_texto_valido(const char *mensaje, char *destino, int tamano);


#endif


