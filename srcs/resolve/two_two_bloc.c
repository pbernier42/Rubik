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

short		tab_tmove_twist_edge(t_move move[NB_MOVE_MAX], t_binary	binary[5])
{
	t_side 		tab_side_edge[6];
	t_binary	bin_problem;


	//if ((tside_find_biggest_weight((BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE)) != side_null)
	//	return (0);
	TAB_TSIDE_NULL(tab_side_edge);
	tab_tside_find_filled(tab_side_edge, (BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE);
	bin_problem = TBIN_CONV_TSIDE(tab_side_edge[0], (BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE);
	i = index_tab_tbin(bin_problem, (t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4)) != -1)
	return (
		copy_tab_tmove(move, (t_move[NB_MOVE_MAX]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), tab_side_edge[0]), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_front, i), tab_side_edge[0]), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), tab_side_edge[0]), mod_reverse},
			TMOVE_PAD_TREE}));
}

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[2];
	t_binary	binary[5];
	t_binary	edge[2][3];
	t_move		move[NB_MOVE_MAX];

	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	//bin(BIN_CUBE);
	//bin(tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner)));
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
	read_tab_tmove(cube, NB_MOVE, move);

	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	I = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_CORNER, 8);
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner));
	BIN_CORNER_LESS = BIN_CUBE & BIN_CORNER;
	J = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_EDGE, 12);
	BIN_EDGE = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[J]);

	NB_MOVE = tab_tmove_edge_near(move, binary);
	if ((read_tab_tmove(cube, NB_MOVE, move)))
	{
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
		I = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_CORNER, 8);
		BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner));
		BIN_CORNER_LESS = BIN_CUBE & BIN_CORNER;
		J = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_EDGE, 12);
		BIN_EDGE = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[J]);
	}
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner));
	tab_tmove_twist_edge(move, binary);

	// printf("\nCUBE\n");
	// bin(BIN_CUBE);
	// printf("\nTOTAL\n");
	// bin((BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE);

	//bin(BIN_CUBE);
	// BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner));
	// bin(BIN_CUBE);
	//
	// bin((BIN_EDGE | BIN_CORNER_LESS));
	//bin(BIN_EDGE);


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

short		tab_tmove_edge_middle(t_move move[NB_MOVE_MAX], short index_edge,
				t_binary bin_corner)
{
	short		i;
	t_binary	bin_edge;
	t_side		side_common;
	t_binary	bin_side;

	if (index_edge < 0)
		return (0);
	bin_edge = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[index_edge]);
	side_common = tside_find_biggest_weight(bin_edge | bin_corner);
	bin_side = TBIN_CONV_TSIDE(side_common, bin_edge | bin_corner);
	i = index_tab_tbin(bin_side,
		(t_binary[8]){
			0b100001000, 0b100000010, 0b001100000, 0b001000010,
			0b010000100, 0b000001100, 0b010000001, 0b000100001}, 8);
	return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move){
		((t_side[8]){
			TSIDE_AROUND(around_up, side_common),
			TSIDE_AROUND(around_left, side_common),
			TSIDE_AROUND(around_up, side_common),
			TSIDE_AROUND(around_right, side_common),
			TSIDE_AROUND(around_left, side_common),
			TSIDE_AROUND(around_down, side_common),
			TSIDE_AROUND(around_right, side_common),
			TSIDE_AROUND(around_down, side_common)
			})[i],
		((t_mod[8]){
			mod_reverse, mod_null, mod_null, mod_reverse,
			mod_reverse, mod_null, mod_null, mod_reverse
			})[i]
		}))));
}

short		tab_tmove_edge_near(t_move move[NB_MOVE_MAX], t_binary binary[5])
{
	short		i;
	t_side		side_problem;
	t_side		side_reference;
	t_binary	bin_problem;

	side_problem = tside_find_biggest_weight(BIN_CORNER ^ BIN_CORNER_LESS);
	// if (!TBIN_CONV_TSIDE(side_problem, (BIN_CORNER_LESS | BIN_EDGE)))
	// 	return (0);
	bin_problem = TBIN_CONV_TSIDE(side_problem, (BIN_CORNER | BIN_EDGE));
	if ((i = index_tab_tbin(bin_problem,
		(t_binary[4]){0b011000000, 0b100100000, 0b000000110, 0b000001001}, 4)) != -1)
	{
		side_reference = TSIDE_AROUND(TAROUND_ETATOR(around_up, i), side_problem);
		copy_tab_tmove(move, (t_move[NB_MOVE_MAX]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down,  i), side_reference), mod_null},
			{side_reference, mod_null}
		});
	}
	else if ((i = index_tab_tbin(bin_problem,
		(t_binary[4]){0b110000000, 0b000100100, 0b000000011, 0b001001000}, 4)) != -1)
	{
		side_reference = TSIDE_AROUND(TAROUND_ETATOR(around_up, i), side_problem);
		copy_tab_tmove(move, (t_move[NB_MOVE_MAX]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_left, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_left, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{side_reference, mod_reverse}
		});
	}
	else
		return (0);
	return (6);
}
























//
