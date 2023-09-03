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