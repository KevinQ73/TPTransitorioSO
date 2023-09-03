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

extern t_cpu_config cpu_config;
extern t_config* nuevo_config;
extern t_log* cpu_logger;
int conexion_memoria;

void iniciar_config_cpu();
void conectar_memoria();