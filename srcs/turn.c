/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:36:45 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/29 14:36:46 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

short	read_tab_tmove(char ***cube, int nb_move, t_move *move)
{
	short	i;

	i = -1;
	while (++i < nb_move)
	{
		if (move[i].side == side_null)
			return (i);
		// print_ins((t_move[1]){move[i]}, 1);
		turn_modifier(tturn_conv_tside(cube, move[i].side), move[i].mod);
		//ungly_display(cube);
	}
	//add
	return (i);
}

t_turn	tturn_conv_tside(char ***cube, t_side side)
{
	t_turn		turn;

	tab_char_find_around(turn.right, cube, TAB_TLINE_AROUND(side)[around_right]);
	//printf("[%c][%c][%c]\n", *turn.right[0], *turn.right[1], *turn.right[2]);
	tab_char_find_around(turn.down, cube, TAB_TLINE_AROUND(side)[around_down]);
	//printf("[%c][%c][%c]\n", *turn.down[0], *turn.down[1], *turn.down[2]);
	tab_char_find_around(turn.left, cube, TAB_TLINE_AROUND(side)[around_left]);
	//printf("[%c][%c][%c]\n", *turn.left[0], *turn.left[1], *turn.left[2]);
	tab_char_find_around(turn.up, cube, TAB_TLINE_AROUND(side)[around_up]);
	//printf("[%c][%c][%c]\n", *turn.up[0], *turn.up[1], *turn.up[2]);

	// t_line	tmp;
	//
	// tmp = TAB_TLINE_AROUND(side)[around_up];
	// printf("[%d]{%d %d}{%d %d}{%d %d}\n", tmp.side,
	// 	tmp.coo[0][0], tmp.coo[0][1],
	// 	tmp.coo[1][0], tmp.coo[1][1],
	// 	tmp.coo[2][0], tmp.coo[2][1]);
	//
	turn.front = cube[side];
	return (turn);
}

void	tab_char_find_around(char *data[3], char ***cube, t_line line)
{

	data[0] = (&cube[line.side][line.coo[0][0]][line.coo[0][1]]);
	//printf("side = %d - {%d %d} = [%c]\n", line.side, line.coo[0][0], line.coo[0][1], *data[0]);
	data[1] = (&cube[line.side][line.coo[1][0]][line.coo[1][1]]);
	//printf("side = %d - {%d %d} = [%c]\n", line.side, line.coo[1][0], line.coo[1][1], *data[1]);
	data[2] = (&cube[line.side][line.coo[2][0]][line.coo[2][1]]);
	//printf("side = %d - {%d %d} = [%c]\n", line.side, line.coo[2][0], line.coo[2][1], *data[2]);
}

void	turn_modifier(t_turn turn, t_mod mod)
{
	short	i;

	i = -1;
	while (++i < NB_TURN(mod))
		turn_once(turn);
}

void	turn_once(t_turn turn)
{
	char	swap;

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
}
