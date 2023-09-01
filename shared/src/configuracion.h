#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <commons/config.h>
#include <stdlib.h>
#include <commons/error.h>

t_config* iniciar_config(char*);
void eliminar_config(t_config*);

#endif /* CONFIGURATION_H_ */