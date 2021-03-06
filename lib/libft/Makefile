PROJECT		=	LIBFT
NAME		=	libft.a
OBJDIR		=	objs/
SRCDIR		=	srcs/
INC			=	includes/libft.h
SRC			=	ft_putstr.c \
				ft_putchar.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strstr.c \
				ft_strcmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strsplit.c \
				ft_strlcat.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_sqrt.c \
				ft_swap.c \
				ft_range.c \
				ft_strrev.c \
				ft_lstlast.c \
				ft_strjoin_char.c \
				ft_strjoin_clean.c \
				ft_strjoin_clean_char.c \
				ft_absolute.c \
				ft_intlen_base.c \
				ft_puttab.c \
				ft_strtabdel.c \
				ft_itoa_base.c \
				ft_strsplitstr.c \
				ft_intlen_base.c \
				ft_strreset.c \
				ft_llen.c \
				get_next_line.c \
				ft_puttab_fd.c \
				ft_get_file.c \
				ft_tablen.c \
				ft_ttoa.c \
				ft_realloc.c \
				ft_memsub.c \
				ft_which_endian.c \
				ft_max_val.c \
				ft_c_atoi.c \
				ft_al_exist.c \
				ft_putnstr.c \
				pdebug.c

OBJ			=	$(addprefix $(OBJDIR),$(SRC:.c=.o))
CC			=	gcc
WFLAGS		=	-Wall -Werror -Wextra
DFLAGS		=	$(WFLAGS) -fsanitize=address -g
FLAGS		=	$(WFLAGS)
INCLUDES	=	-I includes/

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJDIR) $(OBJ)
	@printf "[$(PROJECT)] Objs compilation done.                                                   \n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[$(PROJECT)] "
ifeq ($(FLAGS),$(DFLAGS))
	@printf "(lldb mode) "
endif
	@printf "$(NAME) compiled.\n"

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC) Makefile
	@printf "\r[$(PROJECT)] Compiling $(notdir $<) to $(notdir $@)                                 \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	@mkdir objs

lldb:
ifeq ($(FLAGS),$(WFLAGS))
	@sed '/^FLAGS/ s/WFLAGS/DFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT)] Swap to lldb mode.\n"
	@make
else
	@printf "[$(PROJECT)] Already in lldb mode.\n"
endif
	@echo > /dev/null

normal:
ifeq ($(FLAGS),$(DFLAGS))
	@sed '/^FLAGS/ s/DFLAGS/WFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT)] Swap to normal mode.\n"
	@make
else
	@printf "[$(PROJECT)] Already in normal mode.\n"
endif
	@echo > /dev/null

flag:
	@printf "[$(PROJECT)] "
ifeq ($(FLAGS),$(WFLAGS))
	@printf "Normal mode activated {$(FLAGS)}.\n"
else
	@printf "Lldb mode activated {$(FLAGS)}.\n"
endif

clean:
	@rm -rf $(OBJDIR)
	@printf "[$(PROJECT)] Obj removed.\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re
