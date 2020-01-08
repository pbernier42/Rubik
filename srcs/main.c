/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/08 17:01:37 by rlecart          ###   ########.fr       */
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
	//display(cube, 0, NULL);
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
		turn = instruction_turn(cube, instruction[count++].side);
		//si reverse changer turn
		turn_side(turn);
		if (instruction[count].mod == mod_twice)
			turn_side(turn);
	}
}

t_turn	instruction_turn(char ***cube, t_side side)
{
	t_turn	turn;

	// printf("[%c]\n", cube[6][0][0]);
	if (side == side_front)
	{
		turn = ((t_turn){
			cube[side_front],
			NULL,
			&(cube[side_down][0]),
			NULL,
			&(cube[side_up][0])
		});
		// printf("[%p]\n", turn.turn);
		// printf("[%p]\n", turn.right);
		// printf("[%p][%c]\n", turn.down, turn.down[0][0]);
		// printf("[%p]\n", turn.left);
		// printf("[%p]\n\n", turn.up);
	}
	// 	turn = ((t_turn){cube[side_front],
	// 		((char**){&(cube[side_right][0][0]), &(cube[side_right][1][0]), &(cube[side_right][2][0])}),
	// 		&(cube[side_down][0]),
	// 		((char**){&(cube[side_left][0][2]), &(cube[side_left][1][2]), &(cube[side_left][2][2])}),
	// 		&(cube[side_up][2])
	// 	});

	(void)side;
	turn.front = NULL;
	(void)cube;
	return (turn);
}

void	turn_side(t_turn turn)
{
	char	swap;

	// swap = turn.front[0][0];
	// turn.front[0][0] = turn.front[2][0];
	// turn.front[2][0] = turn.front[2][2];
	// turn.front[2][2] = turn.front[0][2];
	// turn.front[0][2] = swap;

	(void)swap;
	(void)turn;
	return;
}
