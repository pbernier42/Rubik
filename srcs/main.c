/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/03/02 21:58:55 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_env	env;
char	***g_layer;

int		main(int argc, char **argv)
{
	char	***cube;
	t_list	shuffle;
	t_list	res;

	env.nb_move = 0;
	env.next = NULL;
	shuffle.nb_move = 0;
	if (argc != 2 || !(shuffle.nb_move = sizet_count_arg(argv[1])))
		error(-1, ERR_WRONG_ARG_NUMBER, "main(), nb_move");
	cube = init_layer(STR_INITIALS_SIDE);
	g_layer = init_layer(STR_INITIALS_LAYER);

	if (!(shuffle.move = (t_move*)malloc(sizeof(t_move) * shuffle.nb_move)))
		error(-1, ERR_MALLOC, "main(), mix shuffle");
	tab_tmove_conv_str(shuffle, argv[1]);
	find_inverted_res(shuffle);
	//ungly_display(cube);
	read_tab_tmove(cube, shuffle);

	t_color		c[3];

	step_two(cube, c, find_new_color(cube, c));

	//ungly_display(g_layer);
	//res = find_best_resolve(cube, shuffle);
	free(shuffle.move);
	//free cube
	//print_tab_tmove(res);
	free(res.move);
	return (0);
}

void		print_tab_tmove(t_list l)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < l.nb_move)
	{
		write(1, &(STR_INITIALS_SIDE[l.move[i].side]), 1);
		write(1, &(STR_INITIALS_MOD[l.move[i].mod]), 1);
		if (i + 1 != l.nb_move)
			write(1, &(" "), 1);
	}
	if (l.nb_move)
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

void	print_sticker(char c, int hl)
{
	if (hl != -1)
		printf("%s", TAB_COLORS(hl, tside_find_char(c)));
	printf("[%c]" C_RESET, c);
}

void	print_line(char *line, t_side side, short y)
{
	int		hl[3];

	if (side == side_null)
		ft_memset(hl, -1, sizeof(int) * 3);
	else
	{
		hl[0] = g_layer[side][y][side == side_back ? 2 : 0] - '0';
		hl[1] = g_layer[side][y][1] - '0';
		hl[2] = g_layer[side][y][side == side_back ? 0 : 2] - '0';
	}
	if (!line)
		printf("         ");
	else
	{
		print_sticker(line[0], hl[0]);
		print_sticker(line[1], hl[1]);
		print_sticker(line[2], hl[2]);
	}
	printf(" ");
}

void	print_face(char ***side, bool back, t_side s[3]) // rajouter les s[] ainsi que les y[3] pour les coordonnees
{
	print_line(side[0] ? side[0][0] : NULL, s[0], 0);
	if (!back)
		print_line(side[1] ? side[1][0] : NULL, s[1], 0);
	else
		print_line((char[3]){side[1][0][2], side[1][0][1], side[1][0][0]}, s[1], 0);
	print_line(side[2] ? side[2][0] : NULL, s[2], 0);
	printf("\n");

	print_line(side[0] ? side[0][1] : NULL, s[0], 1);
	if (!back)
		print_line(side[1] ? side[1][1] : NULL, s[1], 1);
	else
		print_line((char[3]){side[1][1][2], side[1][1][1], side[1][1][0]}, s[1], 1);
	print_line(side[2] ? side[2][1] : NULL, s[2], 1);
	printf("\n");

	print_line(side[0] ? side[0][2] : NULL, s[0], 2);
	if (!back)
		print_line(side[1] ? side[1][2] : NULL, s[1], 2);
	else
		print_line((char[3]){side[1][2][2], side[1][2][1], side[1][2][0]}, s[1], 2);
	print_line(side[2] ? side[2][2] : NULL, s[2], 2);
	printf("\n\n");
}

void 	ungly_display(char ***cube)
{
	print_face(((char**[3]){NULL, cube[side_back], NULL}), true, (t_side[3]){side_null, side_back, side_null});
	print_face(((char**[3]){NULL, cube[side_up], NULL}), false, (t_side[3]){side_null, side_up, side_null});
	print_face(((char**[3]){cube[side_left], cube[side_front], cube[side_right]}), false, (t_side[3]){side_left, side_front, side_right});
	print_face(((char**[3]){NULL, cube[side_down], NULL}), false, (t_side[3]){side_null, side_down, side_null});
	printf("--------- --------- ---------\n");
}
