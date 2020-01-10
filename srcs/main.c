/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/08 20:03:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

int		main(int argc, char **argv)
{
	int			arg_number;
	char		***cube;

	if (argc != 2 || !(arg_number = arg_count(argv[1])))
		return (printf("error\n"));
	cube = init_tab();
	//display(cube, NONE, NULL);
	instructions(cube, arg_number, argv[1]);
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
		//si reverse changer turn
		turn_side(turn);
		if (instruction[count++].mod == mod_twice)
			turn_side(turn);
		printf("[%c][%c][%c]\n", cube[instruction[count - 1].side][0][0], cube[instruction[count - 1].side][0][1], cube[instruction[count - 1].side][0][2]);
		printf("[%c][%c][%c]\n", cube[instruction[count - 1].side][1][0], cube[instruction[count - 1].side][1][1], cube[instruction[count - 1].side][1][2]);
		printf("[%c][%c][%c]\n\n", cube[instruction[count - 1].side][2][0], cube[instruction[count - 1].side][2][1], cube[instruction[count - 1].side][2][2]);
	}
}

# define L_LEFT		((int[3][2]){{0, 0}, {1, 0}, {2, 0}})
# define L_UP		((int[3][2]){{0, 0}, {0, 1}, {0, 2}})
# define L_RIGHT	((int[3][2]){{0, 2}, {1, 2}, {2, 2}})
# define L_DOWN		((int[3][2]){{2, 0}, {2, 1}, {2, 2}})


void	init_line(char ***cube, char *line[3], t_side side, int coor[3][2])
{
	line[0] = (&cube[side][coor[0][0]][coor[0][1]]);
	line[1] = (&cube[side][coor[1][0]][coor[1][1]]);
	line[2] = (&cube[side][coor[2][0]][coor[2][1]]);
}

t_turn	instruction_turn(char ***cube, t_side side)
{
	t_turn	turn;

	if (side == side_front)
	{
		turn.front = cube[side_front];
		init_line(cube, turn.right, side_right, L_LEFT);
		init_line(cube, turn.down, side_down, L_UP);
		init_line(cube, turn.left, side_left, L_RIGHT);
		init_line(cube, turn.up, side_up, L_DOWN);
	}
	else
		turn.front = NULL;

	(void)side;
	(void)cube;
	return (turn);
}

void	turn_side(t_turn turn)
{
	char	swap;

	if (!turn.front)
		return ;

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

	//printf("%c %c %c\n", *turn.right[0], *turn.right[1], *turn.right[2]);
	//printf("{%p}\n", &(*turn.down[0]));


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

	(void)swap;
	(void)turn;
	return;
}
