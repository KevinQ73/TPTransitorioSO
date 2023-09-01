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
    int PUERTO_ESCUCHA_DISPATCH;
    int PUERTO_ESCUCHA_INTERRUPT;
} t_cpu_config;

void cargar_config();