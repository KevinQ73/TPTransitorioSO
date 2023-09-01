#include "comunicacion.h"

int crear_conexion(char *ip, char* puerto)
{
	struct addrinfo hints;
	struct addrinfo *server_info;
	int socket_cliente = 0;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(ip, puerto, &hints, &server_info);

	// Ahora vamos a crear el socket.
	socket_cliente = socket(server_info->ai_family,
							server_info->ai_socktype,
							server_info->ai_protocol);

	// Ahora que tenemos el socket, vamos a conectarlo
	uint32_t result;
	uint32_t handshake = 1;

	connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen);

	send(socket_cliente, &handshake, sizeof(uint32_t), NULL);
	recv(socket_cliente, &result, sizeof(uint32_t), MSG_WAITALL);

	int i = 0;
	while (result != 0 && i < 3) {
		send(socket_cliente, &handshake, sizeof(uint32_t), NULL);
		recv(socket_cliente, &result, sizeof(uint32_t), MSG_WAITALL);
		i++;
	}

	freeaddrinfo(server_info);

	return socket_cliente;
}

int realizar_handshakes(char* ip, char* puerto, t_log* logger){
	int socket_cliente = crear_conexion(ip, puerto);

	if (socket_cliente == 0){
		log_error(logger, "No se pudo realizar el handshake");
		exit(1);
	}
	else{
		log_info(logger, "Se realizó el handshake");
		return socket_cliente;
	}
}