DIR_ALLOC = $(SOURCEDIR)alloc/
DIR_DISPLAY = $(SOURCEDIR)display/
DIR_GEOMETRY = $(SOURCEDIR)geometry/
DIR_PARSING = $(SOURCEDIR)parsing/
DIR_UTILS = $(SOURCEDIR)utils/

MAIN_FILE = $(SOURCEDIR)main.c

FILES_ALLOC = exit.c			\
			display.c			\
			ram.c				\
			model.c				\
			parser.c			\

FILES_DISPLAY = loop.c						\
				init_context.c				\
				init_vertices.c				\
				init_callbacks.c			\
				init_texture.c				\
				init_matrices.c				\
				init_shader_program.c		\

FILES_PARSING = shader.c			\
				count_elements.c	\
				fill_vertices.c		\
				fill_triangles.c	\
				fill_uv.c			\
				bmp.c				\

FILES_UTILS =	parsing.c			\
				maths.c				\

FILES_GEOMETRY =	matrix.c				\
					matrix2.c				\
					vector.c				\
					projection_matrices.c	\
					movement_matrices.c		\

SRC =		$(MAIN_FILE)									\
			$(addprefix $(DIR_ALLOC), $(FILES_ALLOC))		\
			$(addprefix $(DIR_DISPLAY), $(FILES_DISPLAY))	\
			$(addprefix $(DIR_GEOMETRY), $(FILES_GEOMETRY))		\
			$(addprefix $(DIR_PARSING), $(FILES_PARSING)) \
			$(addprefix $(DIR_UTILS), $(FILES_UTILS))