#include <memoria.h>

int main(void) {
    
    /* INICIAR LOGGER*/

    memoria_logger = iniciar_logger("./files/memoria.log", "MEMORIA_LOGGER", 1, LOG_LEVEL_DEBUG);
    log_info(memoria_logger, "Se inició el logger de la MEMORIA");

    /* INICIAR CONFIG*/
    
    iniciar_config_memoria();
    log_info(memoria_logger, "Se cargó el config de la MEMORIA");

    /*INICIAR CLIENTE A FILESYSTEM*/

    conectar_filesystem(memoria_config.PUERTO_FILESYSTEM);
    log_info(memoria_logger, "Se conectó a FILESYSTEM");

    /*INICIAR SERVIDOR A CPU - KERNEL - FILESYSTEM*/

    realizar_handshakes_con_memoria();
    log_info(memoria_logger, "Se inició el servidor a CPU, Kernel y Filesystem");

    /*LIBERAR MEMORIA*/
	log_debug(memoria_logger, "TERMINANDO MEMORIA");
    finalizar_memoria();
	config_destroy(nuevo_config);
    return EXIT_SUCCESS;
}