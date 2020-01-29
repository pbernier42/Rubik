/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_two_bloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:28:26 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 17:28:27 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[2];
	t_binary	binary[4];
	t_binary	edge[2][3];
	t_move		move[NB_MOVE_MAX];

	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	I = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_CORNER, 8);
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner));
	tab_tbin_find_edge(TAB_BIN_EDGE_OPPOSITE, TAB_TSTICKERS_CORNER[(I + 4) % 8]);
	NB_MOVE = tab_tmove_edge_opposite(move, BIN_CUBE, TAB_BIN_EDGE_OPPOSITE,
		TAB_TSTICKERS_CORNER[(I + 4) % 8]);
	if ((read_tab_tmove(cube, NB_MOVE, move)))
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner));
	tab_tbin_find_edge(TAB_BIN_EDGE_NEAR, TAB_TSTICKERS_CORNER[I]);
	BIN_EDGE_EXTREMITY = BIN_EDGES_NEAR | BIN_EDGES_OPPOSITE;
	I = index_tab_tstickers(BIN_CUBE ^ (BIN_CUBE & BIN_EDGE_EXTREMITY),
		TAB_TSTICKERS_EDGE, 12);
	NB_MOVE = tab_tmove_edge_middle(move, I, BIN_CORNER);

	//bin(BIN_EDGE | BIN_CORNER);
	//bin(BIN_EDGE_EXTREMITY);
}

short		tab_tmove_edge_opposite(t_move move[NB_MOVE_MAX], t_binary bin_cube,
				t_binary tab_bin_edge_opposite[3],  t_sticker corner[3])
{
	short		i;

	i = -1;
	while (++i < 3)
		if (tab_bin_edge_opposite[i] == (bin_cube & tab_bin_edge_opposite[i]))
			return (copy_tab_tmove(move,
				TAB_TMOVE_ONE(((t_move){corner[i].side, mod_null}))));
	return (0);
}

short		tab_tmove_edge_middle(t_move move[NB_MOVE_MAX], short i,
				t_binary bin_corner)
{
	short		ii;
	t_binary	bin_edge;
	t_side		side_common;
	t_binary	bin_side;

	if (i < 0)
		return (0);
	bin_edge = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[i]);
	side_common = tside_find_biggest_weight(bin_edge | bin_corner);
	bin_side = TBIN_CONV_TSIDE(side_common, bin_edge | bin_corner);

	bin(bin_side);
	(void)move;
	return (0);
}

//short	index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab)
























//
