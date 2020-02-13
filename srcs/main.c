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
	size_t		arg_number;
	char		***cube;
	t_move		*moves;

	env.nb_move = 0;
	env.next = NULL;
	arg_number = 0;
	if (argc != 2 || !(arg_number = sizet_count_arg(argv[1])))
		error(-1, ERR_WRONG_ARG_NUMBER, "main(), arg_number");
	cube = init_cube();
	if (!(moves = (t_move*)malloc(sizeof(t_move) * arg_number)))
		error(-1, ERR_MALLOC, "main(), mix moves");
	tab_tmove_conv_str(moves, arg_number, argv[1]);
	read_tab_tmove(cube, arg_number, moves);

	free(moves);
	find_best_resolve(cube, &arg_number);
	//free cube
	//print_tab_tmove(moves, arg_number);
	//free(moves);
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
		ft_putchar(STR_INITIALS_SIDE[tab[i].side]);
		ft_putchar(STR_INITIALS_MOD[tab[i].mod]);
		if (i + 1 != nb)
		ft_putchar(' ');
	}
	if (nb)
		ft_putchar('\n');
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
