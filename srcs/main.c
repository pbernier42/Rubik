/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/03 21:28:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_env	g;

int		main(int argc, char **argv)
{
	int			arg_number;
	char		***cube;

	env.i = 0;
	env.buff = NULL;
	arg_number = 0;
	if (argc != 2 || !(arg_number = arg_count(argv[1])))
		error(-1, "error");
	cube = init_tab();
	instructions(cube, arg_number, argv[1]);
	read_tab_tmove(cube, arg_count, env.buff);
	resolve(cube);
	//ungly_display(cube);
	//refine(args, arg_number);
	//DISPLAY(cube, side_null);
	return (0);
}

int		arg_count(char *argv)
{
	size_t	len;
	int		count;

	len = skip_space(0, argv);
	count = 0;
	while (argv[len])
	{
		if (!IS_SIDE(argv[len]))
			return (0);
		if (!argv[++len])
			return (++count);
		if (!IS_MOD(argv[len]) && !IS_SPACE(argv[len]))
			return (0);
		len = skip_space(++len, argv);
		++count;
	}
	return (count);
}

void	instructions(char ***cube, int arg_count, char *argv)
{
	size_t		len;
	int			count;
	t_move		instruction[arg_count];

	len = skip_space(0, argv);
	count = 0;
	while (count < arg_count)
	{
		instruction[count++] = arg_instruction(
			(char[2]){argv[len], argv[len + 1]});
		len += 2;
		len = skip_space(len, argv);
		//printf("[%d] - [%d]\n", instruction[count - 1].side, instruction[count - 1].mod);
	}
	(void)cube;
	//refine(instruction, arg_count);
	// t_binary	b;
	// t_binary	b2;
	// t_side		tab[6];
	// t_side		s[3] = {instruction[0].side, instruction[1].side, instruction[2].side};
	// b = bloc_binary(cube, s);
	// bin(b);
	// b2 = stob(s, 3, b);
	// bin(b2);
	// fill_side_bin(tab, b);
	// int		i = -1;
	// while (++i < 6)
	// 	printf("tab[%d] = %d\n", i, tab[i]);
}

t_move	arg_instruction(char arg[2])
{
	t_move	ret;

	ret.side = side_front;
	while (ret.side != side_null && arg[0] != INITIALS_SIDE[ret.side])
		++ret.side;
	if (!arg[1] || IS_SPACE(arg[1]))
		return ((t_move){ret.side, mod_null});
	ret.mod = mod_twice;
	while (ret.mod != mod_null && arg[1] != INITIALS_MOD[ret.mod])
		++ret.mod;
	return (ret);
}
