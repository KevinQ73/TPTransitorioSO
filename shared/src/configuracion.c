#include "configuracion.h"

t_config* iniciar_config(char* path_config) {

	t_config* config = config_create(path_config);

	if (config == NULL) {
		error_show("ERROR AL CREAR EL ARCHIVO .CONFIG");
		exit(EXIT_FAILURE);
	}

	return config;
}

void eliminar_config(t_config* config) {
	free(config);
	config_destroy(config);
}
