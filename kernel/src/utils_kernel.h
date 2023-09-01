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
    char* IP_FILESYSTEM;
    int PUERTO_FILESYSTEM;
    char* IP_CPU;
    int PUERTO_CPU_DISPATCH;
    int PUERTO_CPU_INTERRUPT;
    char* ALGORITMO_PLANIFICACION;
    int QUANTUM;
    t_list RECURSOS;
    t_list INSTANCIA_RECURSOS;
    int GRADO_MULTIPROGRAMACION_INI;
} t_kernel_config;

