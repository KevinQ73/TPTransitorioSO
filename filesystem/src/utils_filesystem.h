#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <commons/config.h>
#include "../../shared/src/utils/comunicacion.h"
#include "../../shared/src/utils/server.h"

typedef struct{
    char* IP_MEMORIA;
    int PUERTO_MEMORIA;
    int PUERTO_ESCUCHA;
    char* PATH_FAT;
    char* PATH_BLOQUES;
    char* PATH_FCB;
    int CANT_BLOQUES_TOTAL;
    int CANT_BLOQUES_SWAP;
    int TAM_BLOQUE;
    int RETARDO_ACCESO_BLOQUE;
    int RETARDO_ACCESO_FAT;
} t_filesystem_config;

