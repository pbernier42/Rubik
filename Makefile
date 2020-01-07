PROJECT			=	RUBIK
NAME			=	rubik

NO_TO_BE		=	ON

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra

PROJECT_LIBFT	=	LIBFT
NAME_LIBFT		=	libft.a
LIB				=	libft.h
LIB_MAKE		=	lib/libft/
LIB_PATH		=	lib/libft/$(LIB)
LIB_INCLUDES	=	$(addprefix $(LIB_MAKE),$(DIR_INC))

DIR_OBJ			=	objs/
DIR_SRC			=	srcs/
DIR_INC			=	includes/
INCLUDES		=	-I $(DIR_INC) \
					$(LIB_INCLUDES)

SRC_INCLUDE		=	rubik.h
SRC_FIlE		=	main.c \
					utils.c

INC				=	$(addprefix $(DIR_INC),$(SRC_INCLUDE)) \
					$(addprefix $(LIB_INC),$(LIB))
SRC				=	$(addprefix $(DIR_SRC),$(SRC_FIlE))
OBJ				=	$(addprefix $(DIR_OBJ),$(notdir $(SRC:.c=.o)))

UND				= \033[4m
RES				= \033[0m

all: libft $(NAME)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

help:
	@printf "[$(PROJECT)] make \n"
	@printf "    		-- compile the project '$(NAME)'\n"
	@printf "  $(NAME)		-- compile the project '$(NAME)'\n"
	@printf "  clean		-- remove \'$(DIR_OBJ)\' and all \'.o\' files from it\n"
	@printf "  fclean	-- $(UND)clean$(RES) and remove '$(NAME)'\n"
	@printf "  re		-- $(UND)fclean$(RES) then $(UND)make$(RES)\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "[$(PROJECT)] Objs compilation done.                    \n"
	@$(CC) -o $(NAME) $(FLAGS) $(LIB_PATH) $(OBJ)
	@printf "[$(PROJECT)] "
	@printf "$(NAME) compiled\n"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC) Makefile
	@printf "[$(PROJECT)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

libft:
	@make -C $(LIB_MAKE)

clean_libft:
	@make -C $(LIB_MAKE) clean

fclean_libft:
	@make -C $(LIB_MAKE) fclean

re_libft:
	@make -C $(LIB_MAKE) re

clean:
	@rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(PROJECT)] Shared Objects and symlink removed.\n"

re: fclean $(NAME)

.PHONY: all help flag clean fclean re
