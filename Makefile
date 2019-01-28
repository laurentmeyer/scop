_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = scop
BUILDDIR = builds/
SOURCEDIR = srcs/
HEADERDIR = includes/

SRCFILES = ""

include files.mk


LIBFT = 		./libft/
GLFW = 		./libs/GLFW
GLEW = 		./libs/GLEW

CCHEADERS = -I./$(HEADERDIR) \
			-I$(GLFW)/include/ \
			-I$(GLEW)/include/ \
			-I$(LIBFT)/libft/includes \

CCLIBS =	-L$(GLFW)/lib -lglfw		\
			-L$(GLEW)/lib -lGLEW		\
		-L$(LIBFT) -lft \

CCFRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

OBJ = $(SRC:%.c=%.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	@$(CC) $(CCHEADERS) $(CCLIBS) $(OBJ) $(CCFRAMEWORKS) -o $(NAME)

%.o : %.c
	@printf "%smaking $@%s\\n" "$(_YELLOW)" "$(_END)"
	@$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: norme
norme:
	@norminette $(SRC) $(HEADERDIR) $(LIBFT)
