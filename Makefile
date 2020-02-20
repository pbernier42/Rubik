PROJECT			=	RUBIK
NAME			=	rubik

NO_TO_BE		=	ON

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra $(DFLAGS)
DFLAGS			=	-g -fsanitize=address

# DIR_LIB			=	lib/
# NAME_LIB		=	libft

DIR_OBJ			=	objs/
DIR_SRC			=	srcs/
DIR_INC			=	includes/
INCLUDES		=	-I $(DIR_INC)

SRC_INCLUDE		=	rubik.h \
					define.h \
					prototype.h \
					variable.h

SRC_FIlE		=	main.c \
					error.c \
					display.c \
					resolve/resolve.c \
					resolve/two_two_bloc.c \
					refine.c \
					utils/find.c \
					utils/converter.c \
					utils/parsing.c \
					utils/fill.c \
					argument.c \
					env.c \
					turn.c \
					layer.c

INC				=	$(addprefix $(DIR_INC),$(SRC_INCLUDE)) \
					lib/libft/includes/libft.h
SRC				=	$(addprefix $(DIR_SRC),$(SRC_FIlE))
OBJ				=	$(addprefix $(DIR_OBJ),$(SRC_FIlE:.c=.o))
# LIB				= 	$(foreach L,$(addprefix $(DIR_LIB),$(NAME_LIB)),$(L)/$(lastword $(subst /, ,$(L))).a)

UND				= \033[4m
RES				= \033[0m

all: $(NAME)
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
	@$(CC) -o $(NAME) $(FLAGS) lib/libft/libft.a $(OBJ)
	@printf "[$(PROJECT)] "
	@printf "$(NAME) compiled\n"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC) Makefile
	@printf "[$(PROJECT)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)/resolve
	@mkdir -p $(DIR_OBJ)/utils

# $(LIB):
# 	@echo "ddd\n"
# 	@make -C $(dir $@)

clean:
	@rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(PROJECT)] Shared Objects and symlink removed.\n"

re: fclean $(NAME)

.PHONY: all help flag clean fclean re
