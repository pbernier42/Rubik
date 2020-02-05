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
	t_binary	binary[5];
	t_binary	edge[2][3];
	t_move		move[NB_MOVE_MAX];

	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	I = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_CORNER, 8);
	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]), edge, I);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]));
	tab_tbin_find_edge(TAB_BIN_EDGE_NEAR, TAB_TSTICKERS_CORNER[I]);
	BIN_EDGE_EXTREMITY = BIN_EDGES_NEAR | BIN_EDGES_OPPOSITE;
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
	I = index_tab_tstickers(BIN_CUBE ^ (BIN_CUBE & BIN_EDGE_EXTREMITY),
		TAB_TSTICKERS_EDGE, 12);
	NB_MOVE = tab_tmove_edge_middle(move, I, BIN_CORNER);
	read_tab_tmove(cube, NB_MOVE, move);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_corner_less | arg_edge));
	NB_MOVE = tab_tmove_edge_near(move, binary);
	if ((read_tab_tmove(cube, NB_MOVE, move)))
		tbin_update(cube, binary, corner,
			(arg_edge | arg_corner_less | arg_corner));
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner[0]));
	tab_tmove_twist_edge(move, binary);
	if ((read_tab_tmove(cube, NB_MOVE, move)))
		tbin_update(cube, binary, corner,
			(arg_corner | arg_edge | arg_corner));

	bin(BIN_CORNER | BIN_EDGE);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	I = index_tab_tstickers(BIN_CUBE, TAB_TSTICKERS_CORNER, 8);
	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[2]), edge, I);


	// tbin_update(cube, binary, corner,
	// 	(arg_corner | arg_edge));
	//bin(BIN_CORNER | BIN_EDGE);

}

short		bring_edge_opposite(char ***cube, t_side color[3],
				t_binary edge[2][3], short index_corner)
{
	short		nb_move;
	t_binary	binary[2];
	t_move		move[NB_MOVE_MAX];

	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[index_corner]);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(color[0], color[1]));
	tab_tbin_find_edge(TAB_BIN_EDGE_OPPOSITE, TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	nb_move = tab_tmove_edge_opposite(move, BIN_CUBE, TAB_BIN_EDGE_OPPOSITE,
	 	TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	return (read_tab_tmove(cube, nb_move, move));
	// (void)edge;
	// (void)nb_move;
	// (void)move;
}

void		tbin_update(char ***cube, t_binary binary[5], t_color corner[3],
				t_argument argument)
{
	short		i[2];
	t_binary	binary_update[5];

	BIN_UPDATE_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	if ((argument & arg_cube_all))
		BIN_CUBE = BIN_UPDATE_CUBE;
	I = index_tab_tstickers(BIN_UPDATE_CUBE, TAB_TSTICKERS_CORNER, 8);
	BIN_UPDATE_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
	if ((argument & arg_corner))
		BIN_CORNER = BIN_UPDATE_CORNER;
	BIN_UPDATE_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]));
	if ((argument & arg_cube_two))
		BIN_CUBE = BIN_UPDATE_CUBE;
	BIN_UPDATE_CORNER_LESS = BIN_UPDATE_CUBE & BIN_UPDATE_CORNER;
	if ((argument & arg_corner_less))
		BIN_CORNER_LESS = BIN_UPDATE_CORNER_LESS;
	J = index_tab_tstickers(BIN_UPDATE_CUBE, TAB_TSTICKERS_EDGE, 12);
	BIN_UPDATE_EDGE = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[J]);
	if ((argument & arg_edge))
		BIN_EDGE = BIN_UPDATE_EDGE;
	BIN_UPDATE_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner[0]));
	if ((argument & arg_cube_one))
		BIN_CUBE = BIN_UPDATE_CUBE;
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
	//bin(bin_corner);
	side_common = tside_find_biggest_weight(bin_edge | bin_corner);
	bin_side = TBIN_CONV_TSIDE(side_common, bin_edge | bin_corner);
	i = index_tab_tbin(bin_side,
		(t_binary[8]){
			0b100001000, 0b100000010, 0b001100000, 0b001000010,
			0b010000100, 0b000001100, 0b010000001, 0b000100001}, 8);
	//printf("[%d %d]\n", move[0].side, move[0].mod);
	// printf("[%d]\n", i);
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

short		tab_tmove_twist_edge(t_move move[NB_MOVE_MAX], t_binary	binary[5])
{
	short		i;
	t_side 		tab_side_edge[6];
	t_binary	bin_problem;

	//if ((tside_find_biggest_weight((BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE)) != side_null)
	//	return (0);
	TAB_TSIDE_NULL(tab_side_edge);
	tab_tside_find_filled(tab_side_edge, (BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE);
	bin_problem = TBIN_CONV_TSIDE(tab_side_edge[0], (BIN_EDGE | BIN_CORNER_LESS) & BIN_CUBE);
	i = index_tab_tbin(bin_problem, (t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4);
	return (
		copy_tab_tmove(move, (t_move[NB_MOVE_MAX]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), tab_side_edge[0]), mod_reverse},
			{tab_side_edge[0], mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), tab_side_edge[0]), mod_reverse},
			TMOVE_PAD_TREE}));
}




















//
