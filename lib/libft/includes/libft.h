/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:13 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/24 16:37:21 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 100
# define HEXA "0123456789abcdef"

# define C_RESET "\033[0m"
# define C_RED "\033[38;5;1m"
# define C_RED_MINUS "\033[38;5;9m"
# define C_GREEN "\033[38;5;2m"
# define C_YELLOW "\033[38;5;3m"
# define C_BLUE "\033[38;5;4m"
# define C_PINK "\033[38;5;5m"
# define C_BRIGHT_BLUE "\033[38;5;6m"
# define C_GREY "\033[38;5;8m"
# define C_WHITE "\e[97m"
# define C_ORANGE "\033[38;5;208m"

# define C_BBLACK	"\033[40;01;01;01;01m"
# define C_BPURPLE	"\033[45;01;01;01;01m"
# define C_BCYAN	"\033[46;01;01;01;01m"

# define C_HRED		"\033[41;01;01;01;01m"
# define C_HGREEN	"\033[42;01;01;01;01m"
# define C_HYELLOW	"\033[43;01;01;01;01m"
# define C_HBLUE	"\033[44;01;01;01;01m"
# define C_HORANGE	"\033[48;2;255;165;45;01m"
# define C_HWHITE	"\033[47;01;01;01;01m"

# define C_LRED			"\033[7;49;91m"
# define C_LYELLOW		"\033[7;49;93m"
# define C_LBLUE		"\033[7;49;94m"
# define C_LORANGE		"\033[48;2;245;200;45;30m"
# define C_LWHITE		"\033[7;49;97m"
# define C_LGREEN		"\033[7;49;92m"

# define C_GRED			"\033[7;47;31;01m"
# define C_GYELLOW		"\033[7;49;33;01m"
# define C_GBLUE		"\033[7;49;34;01m"
# define C_GORANGE		"\033[48;2;255;165;01;30;01m"
# define C_GWHITE		"\033[7;49;37;01m"
# define C_GGREEN		"\033[7;49;32;01m"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_gnl
{
	char			*adr;
	char			*head;
	char			*keep;
	int				gol;
	int				ret;
	int				fd;
	struct s_gnl	*before;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_gsml
{
	char			*tmp;
	char			*keep_tmp;
}					t_gsml;

typedef struct		s_clist
{
	void			*content;
	size_t			content_size;
	struct s_clist	*next;
}					t_clist;

typedef struct		s_strsplit
{
	int				count_tab;
	int				*len_by_tab;
}					t_strsplit;

void				ft_putstr(char *str);
void				ft_puttab(char **tab);
void				ft_puttab_fd(char **tab, int fd);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *big, const char *little);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *lil, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_char(char const *s1, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
long				ft_itoo(int value);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_clist				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_clist **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_clist **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_clist **alst, t_clist *newlst);
void				ft_lstiter(t_clist *lst, void (*f)(t_clist *elem));
t_clist				*ft_lstmap(t_clist *lst, t_clist *(*f)(t_clist *elem));
int					ft_sqrt(int nb);
void				ft_swap(void *tab, size_t len);
int					*ft_range(int min, int max);
char				*ft_strrev(char *str);
t_clist				*ft_lstlast(t_clist **alst);
int					get_next_line(const int fd, char **line);
void				ft_strtabdel(char ***tab);
char				*ft_strjoin_clean(char **s1, char **s2);
char				*ft_strjoin_clean_char(char **s, char c);
char				**ft_strsplitstr(char const *s, char c);
int					ft_intlen_base(int nbr, int base);
int					ft_absolute(int nbr);
void				ft_strreset(char **as, char *reset);
size_t				ft_llen(long long nbr);
char				**ft_get_file(char *file);
size_t				ft_tablen(void **tab);
char				*ft_ttoa(char **tab);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_memsub(void *src, unsigned int start, unsigned int len);
int					ft_which_endian(void);
int					ft_max_val(int *tab, int size);
int					ft_c_atoi(char *str);
int					ft_al_exist(void *tab, int nb, int size);
void				ft_putnstr(char *str, size_t len);
int					pdebug(void);

#endif
