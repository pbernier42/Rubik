/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/14 17:46:40 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>
void 	ungly_display(char ***cube)
{
	printf("          [%c][%c][%c]    \n", cube[side_back][0][0], cube[side_back][0][1], cube[side_back][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_back][1][0], cube[side_back][1][1], cube[side_back][1][2]);
	printf("          [%c][%c][%c]    \n\n", cube[side_back][2][0], cube[side_back][2][1], cube[side_back][2][2]);
	printf("          [%c][%c][%c]    \n", cube[side_up][0][0], cube[side_up][0][1], cube[side_up][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_up][1][0], cube[side_up][1][1], cube[side_up][1][2]);
	printf("          [%c][%c][%c]    \n\n", cube[side_up][2][0], cube[side_up][2][1], cube[side_up][2][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n", cube[side_left][0][0], cube[side_left][0][1], cube[side_left][0][2], cube[side_front][0][0], cube[side_front][0][1], cube[side_front][0][2], cube[side_right][0][0], cube[side_right][0][1], cube[side_right][0][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n", cube[side_left][1][0], cube[side_left][1][1], cube[side_left][1][2], cube[side_front][1][0], cube[side_front][1][1], cube[side_front][1][2], cube[side_right][1][0], cube[side_right][1][1], cube[side_right][1][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n\n", cube[side_left][2][0], cube[side_left][2][1], cube[side_left][2][2], cube[side_front][2][0], cube[side_front][2][1], cube[side_front][2][2], cube[side_right][2][0], cube[side_right][2][1], cube[side_right][2][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][0][0], cube[side_down][0][1], cube[side_down][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][1][0], cube[side_down][1][1], cube[side_down][1][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][2][0], cube[side_down][2][1], cube[side_down][2][2]);
	// printf("\n");
	// printf("          [%c][%c][%c]    \n", cube[side_null][0][0], cube[side_null][0][1], cube[side_null][0][2]);
	// printf("          [%c][%c][%c]    \n", cube[side_null][1][0], cube[side_null][1][1], cube[side_null][1][2]);
	// printf("          [%c][%c][%c]    \n", cube[side_null][2][0], cube[side_null][2][1], cube[side_null][2][2]);
}

int		main(int argc, char **argv)
{
	int			arg_number;
	char		***cube;

	if (argc != 2 || !(arg_number = arg_count(argv[1])))
		return (printf("error\n"));
	cube = init_tab();
	instructions(cube, arg_number, argv[1]);
	//resolve(cube);
	ungly_display(cube);
	DISPLAY(cube, F_NONE);
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
	read_instruction(cube, arg_count, instruction);
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
		turn_side(turn);
		if (instruction[count].mod != mod_null)
			turn_side(turn);
		if (instruction[count].mod == mode_reverse)
			turn_side(turn);
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

	turn = init_turn(cube, AROUND(side));
	turn.front = cube[side];
	return (turn);
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
