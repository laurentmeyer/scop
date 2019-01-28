#include "display.h"
#include "ram.h"
#include "scop.h"
#include <libc.h>

void init_texture(t_ram *ram, const char *path)
{
	unsigned char	*texture;

	texture = parse_bmp(ram, path);
	glGenTextures(1, &ram->display.texture_id);
	glBindTexture(GL_TEXTURE_2D, ram->display.texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ram->parser.bmp_w, ram->parser.bmp_h,
		0, GL_BGR, GL_UNSIGNED_BYTE, texture);
	free(texture);

	glUseProgram(ram->display.program);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ram->display.texture_id);
	glUniform1i(ram->display.texture_id, 1);
	glUseProgram(0);
}
