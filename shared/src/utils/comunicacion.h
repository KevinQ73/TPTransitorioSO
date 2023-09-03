#ifndef COMUNICACION_H_
#define COMUNICACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <commons/log.h>

typedef enum {
    HAND_KER,
    HAND_CPU,
    HAND_FSM,
} hand_cod;

int realizar_handshakes(char* ip, char* puerto, t_log* logger);
int crear_conexion(char* ip, char* puerto);
int handshake_memoria(char* ip, char* puerto, int codigo_handshake, t_log* logger);

#endif /* COMUNICACION_H_ */