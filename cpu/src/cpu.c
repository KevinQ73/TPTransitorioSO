#include <cpu.h>

int main(void) {
    
    /* INICIAR LOGGER*/

    cpu_logger = iniciar_logger("./files/memoria.log", "MEMORIA_LOGGER", 1, LOG_LEVEL_DEBUG);
    log_info(cpu_logger, "Se inició el logger de la MEMORIA");

    /* INICIAR CONFIG*/
    
    iniciar_config_memoria();
    log_info(cpu_logger, "Se cargó el config de la MEMORIA");

    /*INICIAR CLIENTE A MEMORIA*/

    conectar_memoria(cpu_config.PUERTO_MEMORIA);
    log_info(cpu_logger, "Se conectó a FILESYSTEM");

    /*INICIAR SERVIDOR A KERNEL*/

    kernel_socket = servidor_kernel(cpu_config.PUERTO_ESCUCHA_DISPATCH);
    log_info(cpu_logger, "Se inició el servidor a Kernel");

    /*LIBERAR MEMORIA*/
	log_debug(cpu_logger, "TERMINANDO CPU");
	config_destroy(nuevo_config);
	log_destroy(cpu_logger);
    return EXIT_SUCCESS;

}