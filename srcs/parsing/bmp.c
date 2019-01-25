#include "display.h"
#include "ram.h"
#include "parser.h"
#include "alloc.h"

unsigned char	*parse_bmp(t_ram *ram, const char *imagepath)
{
	FILE *f;
	unsigned char	*data;
	
	f = fopen(imagepath, "rb");
	data = NULL;
	if (NULL == f)
    	exit_message(ram, EXIT_FAILURE, "Could not open texture file");
	if (54 != fread(ram->parser.bmp_header, 1, 54, f))
    	exit_message(ram, EXIT_FAILURE, "Texture file is not a valid BMP file");
	ram->parser.bmp_pos = *(int *)(ram->parser.bmp_header + 0x0a);
	if (0 == ram->parser.bmp_pos)
	ram->parser.bmp_pos = 54;
	ram->parser.bmp_w = *(int *)(ram->parser.bmp_header + 0x12);
	ram->parser.bmp_h = *(int *)(ram->parser.bmp_header + 0x16);
	ram->parser.bmp_size = *(int *)(ram->parser.bmp_header + 0x22);
	if (0 == ram->parser.bmp_size)
		ram->parser.bmp_size = 3 * ram->parser.bmp_h * ram->parser.bmp_w;
	if (NULL == (data = (unsigned char *)malloc(ram->parser.bmp_size)))
    	exit_message(ram, EXIT_FAILURE, "Could not memalloc for texture data");
	fread(data, 1, ram->parser.bmp_size, f);
	fclose(f);
	return (data);
}