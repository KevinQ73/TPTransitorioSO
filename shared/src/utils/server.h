#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/error.h>

int iniciar_servidor(char*);
int esperar_cliente(int);

#endif /* SERVER_H_ */