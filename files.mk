DIR_ALLOC = $(SOURCEDIR)alloc/
DIR_DISPLAY = $(SOURCEDIR)display/
# DIR_PARSING = $(SOURCEDIR)parsing/
# DIR_RENDER = $(SOURCEDIR)render/
# DIR_UTILS = $(SOURCEDIR)utils/

MAIN_FILE = $(SOURCEDIR)main.c

FILES_ALLOC = exit.c			\
			display.c			\
			ram.c				\

FILES_DISPLAY = callbacks.c		\
				init.c			\
				loop.c			\
				# glad.c			\

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

# FILES_UTILS = \
# 			color.c \
# 			geometry.c \
# 			geometry2.c \
# 			math.c \
# 			transformations.c \

SRC =		$(MAIN_FILE)									\
			$(addprefix $(DIR_ALLOC), $(FILES_ALLOC))		\
			$(addprefix $(DIR_DISPLAY), $(FILES_DISPLAY))	\
			# $(addprefix $(DIR_PARSING), $(FILES_PARSING)) \
			# $(addprefix $(DIR_RENDER), $(FILES_RENDER)) \
			# $(addprefix $(DIR_UTILS), $(FILES_UTILS))
