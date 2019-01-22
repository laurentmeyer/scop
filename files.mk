DIR_ALLOC = $(SOURCEDIR)alloc/
DIR_DISPLAY = $(SOURCEDIR)display/
DIR_GEOMETRY = $(SOURCEDIR)geometry/
# DIR_PARSING = $(SOURCEDIR)parsing/
# DIR_RENDER = $(SOURCEDIR)render/
# DIR_UTILS = $(SOURCEDIR)utils/

MAIN_FILE = $(SOURCEDIR)main.c

FILES_ALLOC = exit.c			\
			display.c			\
			ram.c				\

FILES_DISPLAY = loop.c				\
				init_context.c		\
				init_shaders.c		\
				init_buffers.c		\
				init_callbacks.c	\
				init_program.c		\

# FILES_PARSING = \
# 			parsing.c \
# 			parse_object.c \
# 			parse_light.c \
# 			parse_camera.c \

# FILES_RENDER = \
# 			object.c \
# 			object_cone.c \
# 			object_sphere.c \
# 			object_cylinder.c \
# 			object_plane.c \
# 			render.c \
# 			shading.c \

FILES_GEOMETRY =	matrix.c				\
					projection_matrices.c	\
# 			geometry.c \
# 			geometry2.c \
# 			math.c \
# 			transformations.c \

SRC =		$(MAIN_FILE)									\
			$(addprefix $(DIR_ALLOC), $(FILES_ALLOC))		\
			$(addprefix $(DIR_DISPLAY), $(FILES_DISPLAY))	\
			$(addprefix $(DIR_GEOMETRY), $(FILES_GEOMETRY))		\
			# $(addprefix $(DIR_UTILS), $(FILES_UTILS))		\
			# $(addprefix $(DIR_PARSING), $(FILES_PARSING)) \
			# $(addprefix $(DIR_RENDER), $(FILES_RENDER)) \
