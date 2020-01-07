PROJECT			=	RUBIK
NAME			=	rubik

NO_TO_BE		=	ON

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra

DIR_OBJ			=	objs/
DIR_SRC			=	srcs/
DIR_INC			=	includes/
INCLUDES		=	-I $(DIR_INC)

SRC_INCLUDE		=	rubik.h
SRC_FIlE		=	main.c \
					utils.c

INC				=	$(addprefix $(DIR_INC),$(SRC_INCLUDE))
SRC				=	$(addprefix $(DIR_SRC),$(SRC_FIlE))
OBJ				=	$(addprefix $(DIR_OBJ),$(notdir $(SRC:.c=.o)))

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
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ)
	@printf "[$(PROJECT)] "
	@printf "$(NAME) compiled\n"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC) Makefile
	@printf "[$(PROJECT)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean:
	@rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(PROJECT)] Shared Objects and symlink removed.\n"

re: fclean $(NAME)

.PHONY: all help flag clean fclean re
