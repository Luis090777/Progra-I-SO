#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <comuna.h>

int parseDirectorio(char* nombre_de_directorio, Accion* acciones);
void remover_substring(char *s, const char *toremove, char *result);
void registrar_accion(FILE* log_file, Accion accion, int tiempo);