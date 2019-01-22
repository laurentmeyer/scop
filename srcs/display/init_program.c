#include "scop.h"
#include "alloc.h"

void init_program(t_ram *ram)
{
	ram->display.program = glCreateProgram();
	if (0 == ram->display.program)
		exit_message(ram, EXIT_FAILURE, "Could not init proram");
	init_shaders(ram);
	glAttachShader(ram->display.program, ram->display.vertex_shader);
	glAttachShader(ram->display.program, ram->display.fragment_shader);
	glLinkProgram(ram->display.program);
	// check for linking errors ??
	ram->display.pMatID = glGetUniformLocation(ram->display.program, "projMatrix");
	printf("pID = %d\n", ram->display.pMatID); //ajouter un logfile
}