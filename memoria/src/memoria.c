#include <memoria.h>

int main(void) {
    
    /* INICIAR LOGGER*/

    memoria_logger = iniciar_logger("./files/memoria.log", "MEMORIA_LOGGER", 1, LOG_LEVEL_DEBUG);
    log_info(memoria_logger, "Se inició el logger de la MEMORIA");

    /* INICIAR CONFIG*/
    
    iniciar_config_memoria();
    log_info(memoria_logger, "Se cargó el config de la MEMORIA");

    /*INICIAR CLIENTE A FILESYSTEM*/

    conectar_memoria(memoria_config.PUERTO_FILESYSTEM);
    log_info(memoria_logger, "Se conectó a FILESYSTEM");

    /*INICIAR SERVIDOR A CPU*/

    cpu_socket = servidor_kernel(memoria_config.PUERTO_ESCUCHA);
    log_info(memoria_logger, "Se inició el servidor a Kernel");

    /*LIBERAR MEMORIA*/
	log_debug(memoria_logger, "TERMINANDO CPU");
	config_destroy(nuevo_config);
	log_destroy(memoria_logger);
    return EXIT_SUCCESS;
}