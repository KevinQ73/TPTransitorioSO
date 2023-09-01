#include <cpu.h>

int main(void) {
    
    /* INICIAR LOGGER*/

    cpu_logger = iniciar_logger("./files/logger.log", "CPU_LOGGER", 1, LOG_LEVEL_DEBUG);
    log_info(cpu_logger, "Se inició el logger de la CPU");

    /* INICIAR CONFIG*/
    
    cpu_config = config_create("./files/cpu.config");
	log_info(cpu_logger, "Se leyo la config de la CPU");

}
