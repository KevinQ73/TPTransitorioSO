#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <commons/config.h>
#include "../../shared/src/utils/comunicacion.h"
#include "../../shared/src/utils/server.h"

typedef struct{
    int SOCKET_MEMORIA;
    int SOCKET_CPU;
    int SOCKET_KERNEL;
    int SOCKET_FILESYSTEM;
    int PUERTO_ESCUCHA;
    char* IP_FILESYSTEM;
    int PUERTO_FILESYSTEM;
    u_int32_t TAM_MEMORIA;
    u_int32_t TAM_PAGINA;
    char* PATH_INSTRUCCIONES;
    int RETARDO_RESPUESTA;
    char* ALGORITMO_REEMPLAZO;
} t_memoria_config;

extern t_memoria_config memoria_config;
extern t_config* nuevo_config;
extern t_log* memoria_logger;

void iniciar_config_memoria();
void realizar_handshakes_con_memoria();
void finalizar_memoria();
void conectar_filesystem();