/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/13 16:29:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_env	env;

int		main(int argc, char **argv)
{
	char		***cube;
	t_instruct	shuffle;
	t_instruct	res;

	env.nb_move = 0;
	env.next = NULL;
	shuffle.nb_move = 0;
	if (argc != 2 || !(shuffle.nb_move = sizet_count_arg(argv[1])))
		error(-1, ERR_WRONG_ARG_NUMBER, "main(), nb_move");
	cube = init_cube();

	if (!(shuffle.move = (t_move*)malloc(sizeof(t_move) * shuffle.nb_move)))
		error(-1, ERR_MALLOC, "main(), mix shuffle");
	tab_tmove_conv_str(shuffle.move, shuffle.nb_move, argv[1]);

	res = find_best_resolve(cube, shuffle);
	free(shuffle.move);
	//free cube
	print_tab_tmove(res.move, res.nb_move);
	free(res.move);
	return (0);
}



void		print_tab_tmove(t_move *tab, size_t nb)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < nb)
	{
		write(1, &(STR_INITIALS_SIDE[tab[i].side]), 1);
		write(1, &(STR_INITIALS_MOD[tab[i].mod]), 1);
		if (i + 1 != nb)
			write(1, &(" "), 1);
	}
	if (nb)
		write(1, &("\n"), 1);
}

void		bin(t_binary nbr)
{
	int		i;
	char	cube[54];

	i = 54;
	printf("[%llu]\n", nbr);
	while (--i != -1)
	{
		if (nbr)
		{
			cube[i] = (nbr % 2) + '0';
			nbr /= 2;
		}
		else
			cube[i] = '0';
	}
	if ((nbr))
		printf("[%llu]\n", nbr);
	printf("F %.3s %.3s %.3s\n", &cube[0], &cube[3], &cube[6]);
	printf("R %.3s %.3s %.3s\n", &cube[9], &cube[12], &cube[15]);
	printf("U %.3s %.3s %.3s\n", &cube[18], &cube[21], &cube[24]);
	printf("B %.3s %.3s %.3s\n", &cube[27], &cube[30], &cube[33]);
	printf("L %.3s %.3s %.3s\n", &cube[36], &cube[39], &cube[42]);
	printf("D %.3s %.3s %.3s\n", &cube[45], &cube[48], &cube[51]);
}


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
# define C_BRED		"\033[41;01;01;01;01m"
# define C_BGREEN	"\033[42;01;01;01;01m"
# define C_BYELLOW	"\033[43;01;01;01;01m"
# define C_BBLUE	"\033[44;01;01;01;01m"
# define C_BPURPLE	"\033[45;01;01;01;01m"
# define C_BORANGE	"\033[48;2;255;165;1m"
# define C_BCYAN	"\033[46;01;01;01;01m"
# define C_BWHITE	"\033[47;01;01;01;01m"

void	print_sticker(char c)
{
	if (c == 'F')
		printf("%s", C_BRED);
	else if (c == 'R')
		printf("%s", C_BYELLOW);
	else if (c == 'U')
		printf("%s", C_BBLUE);
	else if (c == 'B')
		printf("%s", C_BORANGE);
	else if (c == 'L')
		printf("%s", C_BWHITE);
	else if (c == 'D')
		printf("%s", C_BGREEN);
	printf("[%c]" C_RESET, c);
}

void	print_line(char *line)
{
	if (!line)
		printf("         ");
	else
	{
		print_sticker(line[0]);
		print_sticker(line[1]);
		print_sticker(line[2]);
	}
	printf(" ");
}

void	print_face(char ***side, bool back)
{
	print_line(side[0] ? side[0][0] : NULL);
	if (!back)
		print_line(side[1] ? side[1][0] : NULL);
	else
		print_line((char[3]){side[1][0][2], side[1][0][1], side[1][0][0]});
	print_line(side[2] ? side[2][0] : NULL);
	printf("\n");


	print_line(side[0] ? side[0][1] : NULL);
	if (!back)
		print_line(side[1] ? side[1][1] : NULL);
	else
		print_line((char[3]){side[1][1][2], side[1][1][1], side[1][1][0]});
	print_line(side[2] ? side[2][1] : NULL);
	printf("\n");

	print_line(side[0] ? side[0][2] : NULL);
	if (!back)
		print_line(side[1] ? side[1][2] : NULL);
	else
		print_line((char[3]){side[1][2][2], side[1][2][1], side[1][2][0]});
	print_line(side[2] ? side[2][2] : NULL);
	printf("\n\n");
}

void 	ungly_display(char ***cube)
{
	print_face(((char**[3]){NULL, cube[side_back], NULL}), true);
	print_face(((char**[3]){NULL, cube[side_up], NULL}), false);
	print_face(((char**[3]){cube[side_left], cube[side_front], cube[side_right]}), false);
	print_face(((char**[3]){NULL, cube[side_down], NULL}), false);
}
