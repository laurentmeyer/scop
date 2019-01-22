#include "model.h"
#include "ram.h"
#include <libc.h>

void init_model(t_ram *ram)
{
	bzero(&(ram->model), sizeof(t_model));
}

void destroy_model(t_model *model)
{
	if (NULL != model->vertices)
	{
		free(model->vertices);
		model->vertices = NULL;
	}
}