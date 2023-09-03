#include <utils_memoria.h>

void iniciar_config_memoria(){
    nuevo_config = config_create("./files/memoria.config");
	log_info(memoria_logger, "memoria.config leído");

	memoria_config.PUERTO_ESCUCHA = config_get_int_value(nuevo_config, "PUERTO_ESCUCHA");
	memoria_config.IP_FILESYSTEM = config_get_string_value(nuevo_config, "IP_FILESYSTEM");
	memoria_config.PUERTO_FILESYSTEM = config_get_int_value(nuevo_config, "PUERTO_FILESYSTEM");
	memoria_config.TAM_MEMORIA = config_get_int_value(nuevo_config, "TAM_MEMORIA");
    memoria_config.TAM_PAGINA = config_get_int_value(nuevo_config, "TAM_PAGINA");
	memoria_config.PATH_INSTRUCCIONES = config_get_string_value(nuevo_config, "PATH_INSTRUCCIONES");
	memoria_config.RETARDO_RESPUESTA = config_get_int_value(nuevo_config, "RETARDO_RESPUESTA");
	memoria_config.ALGORITMO_REEMPLAZO = config_get_string_value(nuevo_config, "ALGORITMO_REEMPLAZO");

	log_info(memoria_logger, "Se cargo la configuración con los siguientes valores: \n PUERTO_ESCUCHA: %d \n IP_FILESYSTEM: %s \n PUERTO_FILESYSTEM: %d \n TAM_MEMORIA: %d \n TAM_PAGINA: %d \n PATH_INSTRUCCIONES: %s \n RETARDO_RESPUESTA: %d \n ALGORITMO_REEMPLAZO: %s", memoria_config.PUERTO_ESCUCHA, memoria_config.IP_FILESYSTEM, memoria_config.PUERTO_FILESYSTEM, memoria_config.TAM_MEMORIA, memoria_config.TAM_PAGINA, memoria_config.PATH_INSTRUCCIONES, memoria_config.RETARDO_RESPUESTA, memoria_config.ALGORITMO_REEMPLAZO);
}

void realizar_handshakes_con_memoria() {

	uint32_t resultOk = 0;
    uint32_t resultError = -1;

	memoria_config.SOCKET_CPU = 0;
	memoria_config.SOCKET_KERNEL = 0;
	memoria_config.SOCKET_FILESYSTEM = 0;

	while (memoria_config.SOCKET_CPU == 0 || memoria_config.SOCKET_KERNEL == 0 || memoria_config.SOCKET_FILESYSTEM == 0){
		
		int socket_cliente = accept(memoria_config.SOCKET_MEMORIA, NULL, NULL);
		int codigo;

		log_info(memoria_logger, "Esperando los handshakes de CPU, KERNEL Y FILESYSTEM");
		recv(socket_cliente, &codigo, sizeof(int), MSG_WAITALL);

		switch (codigo)
		{
		case HAND_CPU:
			memoria_config.SOCKET_CPU = socket_cliente;
            send(memoria_config.SOCKET_CPU, &resultOk, sizeof(uint32_t), 0);
            log_info(memoria_logger, "Se realizó el handshake con CPU");
			break;
		
		case HAND_KER:
			memoria_config.SOCKET_KERNEL = socket_cliente;
            send(memoria_config.SOCKET_KERNEL, &resultOk, sizeof(uint32_t), 0);
            log_info(memoria_logger, "Se realizó el handshake con Kernel");
			break;

		case HAND_FSM:
			memoria_config.SOCKET_FILESYSTEM = socket_cliente;
            send(memoria_config.SOCKET_FILESYSTEM, &resultOk, sizeof(uint32_t), 0);
            log_info(memoria_logger, "Se realizó el handshake con Filesystem");
			break;
		
		default:
			send(socket_cliente, &resultError, sizeof(uint32_t), 0);
            log_warning(memoria_logger, "Se recibió un handshake con un código erroneo");
			break;
		}
	}
}

void finalizar_memoria(){
	
	if (memoria_config.SOCKET_MEMORIA != 0){
    log_debug(memoria_logger, "Cerrando el socket del módulo MEMORIA...");
    close(memoria_config.SOCKET_MEMORIA);
    }

    if (memoria_logger != NULL){
    log_debug(memoria_logger, "Finalizando instancia del logger de MEMORIA...");
    log_destroy(memoria_logger);
    }
}