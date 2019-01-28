DIR_ALLOC = $(SOURCEDIR)alloc/
DIR_DISPLAY = $(SOURCEDIR)display/
DIR_GEOMETRY = $(SOURCEDIR)geometry/
DIR_PARSING = $(SOURCEDIR)parsing/
DIR_UTILS = $(SOURCEDIR)utils/
# DIR_RENDER = $(SOURCEDIR)render/

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
# 			parse_object.c \
# 			parse_light.c \
# 			parse_camera.c \

FILES_UTILS =	parsing.c			\
				maths.c				\
# 			object_cone.c \
# 			object_sphere.c \
# 			object_cylinder.c \
# 			object_plane.c \
# 			render.c \
# 			shading.c \

FILES_GEOMETRY =	matrix.c				\
					vector.c				\
					projection_matrices.c	\
					movement_matrices.c		\
# 			geometry.c \
# 			geometry2.c \
# 			math.c \
# 			transformations.c \

SRC =		$(MAIN_FILE)									\
			$(addprefix $(DIR_ALLOC), $(FILES_ALLOC))		\
			$(addprefix $(DIR_DISPLAY), $(FILES_DISPLAY))	\
			$(addprefix $(DIR_GEOMETRY), $(FILES_GEOMETRY))		\
			$(addprefix $(DIR_PARSING), $(FILES_PARSING)) \
			$(addprefix $(DIR_UTILS), $(FILES_UTILS))		\
			# $(addprefix $(DIR_RENDER), $(FILES_RENDER)) \
