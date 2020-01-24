/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/22 21:10:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

int		main(int argc, char **argv)
{
	int			arg_number;
	char		***cube;
	//t_move		*args;

	arg_number = 0;
	if (argc != 2 || !(arg_number = arg_count(argv[1])))
		error(-1, "error");
	cube = init_tab();
	instructions(cube, arg_number, argv[1]);
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
	refine(instruction, arg_count);
	//read_instruction(cube, arg_count, instruction);
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

void	read_instruction(char ***cube, int arg_count, t_move *instruction)
{
	int			count;
	t_turn		turn;

	count = 0;
	while (count < arg_count)
	{
		turn = instruction_turn(cube, instruction[count].side);
		turn_multiple(turn, instruction[count].mod);
		++count;
	}
}

void	init_line(char ***cube, char *data[3], t_line line)
{
	data[0] = (&cube[line.side][line.coo[0][0]][line.coo[0][1]]);
	data[1] = (&cube[line.side][line.coo[1][0]][line.coo[1][1]]);
	data[2] = (&cube[line.side][line.coo[2][0]][line.coo[2][1]]);
}

t_turn	init_turn(char ***cube, t_line line[4])
{
	t_turn		turn;

	init_line(cube, turn.right, line[0]);
	init_line(cube, turn.down, line[1]);
	init_line(cube, turn.left, line[2]);
	init_line(cube, turn.up, line[3]);
	return (turn);
}

t_turn	instruction_turn(char ***cube, t_side side)
{
	t_turn	turn;

	printf("side = [%d]\n", side);
	turn = init_turn(cube, AROUND(side));
	turn.front = cube[side];
	return (turn);
}

void	turn_multiple(t_turn turn, t_mod mod)
{
	printf("mod = [%d]\n\n", mod);
	turn_side(turn);
	if (mod != mod_null)
		turn_side(turn);
	if (mod == mod_reverse)
		turn_side(turn);
}

void	turn_side(t_turn turn)
{
	char	swap;

	// printf("    [%c][%c][%c]    \n", *(turn.up[0]), *(turn.up[1]), *(turn.up[2]));
	// printf("[%c]            [%c]\n", *(turn.left[0]), *(turn.right[0]));
	// printf("[%c]            [%c]\n", *(turn.left[1]), *(turn.right[1]));
	// printf("[%c]            [%c]\n", *(turn.left[2]), *(turn.right[2]));
	// printf("    [%c][%c][%c]    \n", *(turn.down[0]), *(turn.down[1]), *(turn.down[2]));



	swap = turn.front[0][0];
	turn.front[0][0] = turn.front[2][0];
	turn.front[2][0] = turn.front[2][2];
	turn.front[2][2] = turn.front[0][2];
	turn.front[0][2] = swap;

	swap = turn.front[0][1];
	turn.front[0][1] = turn.front[1][0];
	turn.front[1][0] = turn.front[2][1];
	turn.front[2][1] = turn.front[1][2];
	turn.front[1][2] = swap;

	swap = *(turn.down[0]);
	*(turn.down[0]) = *(turn.right[2]);
	*(turn.right[2]) = *(turn.up[2]);
	*(turn.up[2]) = *(turn.left[0]);
	*(turn.left[0]) = swap;

	swap = *(turn.down[1]);
	*(turn.down[1]) = *(turn.right[1]);
	*(turn.right[1]) = *(turn.up[1]);
	*(turn.up[1]) = *(turn.left[1]);
	*(turn.left[1]) = swap;

	swap = *(turn.down[2]);
	*(turn.down[2]) = *(turn.right[0]);
	*(turn.right[0]) = *(turn.up[0]);
	*(turn.up[0]) = *(turn.left[2]);
	*(turn.left[2]) = swap;

	return;
}
