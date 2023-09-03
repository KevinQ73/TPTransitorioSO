#include <utils_cpu.h>

void iniciar_config_cpu(){
    nuevo_config = config_create("./files/cpu.config");
	log_info(cpu_logger, "cpu.config leído");

	cpu_config.IP_MEMORIA = config_get_string_value(nuevo_config, "IP_MEMORIA");
	cpu_config.PUERTO_MEMORIA = config_get_int_value(nuevo_config, "PUERTO_MEMORIA");
	cpu_config.PUERTO_ESCUCHA_DISPATCH = config_get_int_value(nuevo_config, "PUERTO_ESCUCHA");
	cpu_config.PUERTO_ESCUCHA_INTERRUPT = config_get_int_value(nuevo_config, "PATH_SUPERBLOQUE");

	log_info(cpu_logger, "Se cargo la configuración con los siguientes valores: \n IP_MEMORIA: %s \n PUERTO_MEMORIA: %d \n PUERTO_ESCUCHA: %d \n PATH_SUPERBLOQUE: %d", cpu_config.IP_MEMORIA, cpu_config.PUERTO_MEMORIA, cpu_config.PUERTO_ESCUCHA_DISPATCH, cpu_config.PUERTO_ESCUCHA_INTERRUPT);
}

void conectar_memoria(t_cpu_config data){
	conexion_memoria = handshake_memoria(data.IP_MEMORIA, data.PUERTO_ESCUCHA_DISPATCH, HAND_CPU, cpu_logger);

	if (conexion_memoria == 0){
		log_info(cpu_logger, "Hubo un error al conectarse a MEMORIA");
		exit(1);
	}
}