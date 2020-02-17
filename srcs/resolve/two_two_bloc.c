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
	t_binary	binary[6];
	t_binary	edge[2][3];
	t_move		move[NB_MOVE_MAX];

	//bin(tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner)));
	I = INDEX_CORNER(corner);
	if (I == -1)
	{
		printf("corner notfound\n");
		printf("!!!!!!\n[%s][%s][%s]\n", STR_SIDE(corner[0]), STR_SIDE(corner[1]), STR_SIDE(corner[2]));
		ungly_display(cube);
	}
	else
//	printf("([%s][%s][%s])\n", STR_SIDE(corner[0]), STR_SIDE(corner[1]), STR_SIDE(corner[2]));
	//ungly_display(cube);


	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]), edge, I); // Du coup segfault ici avec I
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
	read_tab_tmove(cube, NB_MOVE, move);
	tbin_update(cube, binary, corner,
		(arg_edge | arg_corner_less | arg_cube_one));
	tab_tmove_twist_edge(move, binary, &BIN_EDGE);
	read_tab_tmove(cube, NB_MOVE, move);
	I = INDEX_CORNER(corner);
	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[2]), edge, I);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_edge | arg_edge_prim));
	I = INDEX_CORNER(corner);
	NB_MOVE = tab_tmove_edge_two(move, binary, I);
	read_tab_tmove(cube, NB_MOVE, move);
	tbin_update(cube, binary, corner,
		(arg_corner_less | arg_edge_prim | arg_cube_one));
	NB_MOVE = tab_tmove_twist_edge(move, binary, &BIN_EDGE_PRIM);
	read_tab_tmove(cube, NB_MOVE, move);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_edge_prim | arg_edge | arg_cube_one));
	NB_MOVE = tab_tmove_right_angle(move, binary, (t_side)corner[0]);
	read_tab_tmove(cube, NB_MOVE, move);
}

short		bring_edge_opposite(char ***cube, t_side color[3],
				t_binary edge[2][3], short index_corner)
{
	short		nb_move;
	t_binary	binary[2];
	t_move		move[NB_MOVE_MAX];

	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[index_corner]); // ici
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(color[0], color[1]));
	tab_tbin_find_edge(TAB_BIN_EDGE_OPPOSITE, TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	nb_move = tab_tmove_edge_opposite(move, BIN_CUBE, TAB_BIN_EDGE_OPPOSITE,
	 	TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	return (read_tab_tmove(cube, nb_move, move));
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

short		tab_tmove_twist_edge(t_move move[NB_MOVE_MAX], t_binary	binary[5], t_binary *edge)
{
	short		i[3];
	t_side 		tab_side_edge[6];
	t_binary	bin_problem;

	if ((tside_find_biggest_weight((*edge | BIN_CORNER_LESS) & BIN_CUBE)) != side_null)
		return (0);
	TAB_TSIDE_NULL(tab_side_edge);
	tab_tside_find_filled(tab_side_edge, (*edge | BIN_CORNER_LESS) & BIN_CUBE);
	bin_problem = TBIN_CONV_TSIDE(TSIDE_BIGGEST, (*edge | BIN_CORNER_LESS) & BIN_CUBE);
	I = index_tab_tbin(bin_problem, (t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4);
	J = -1;
	if (edge ==  &BIN_EDGE_PRIM)
	{
		K = index_tab_tbin(bin_problem | TBIN_CONV_TSIDE(TSIDE_BIGGEST, (BIN_EDGE | BIN_CORNER_LESS)),
				(t_binary[8]){
					0b000001011, 0b000100110, 0b110100000, 0b011001000,
					0b011001000, 0b000001011, 0b000100110, 0b110100000}, 8);
		move[++J] = (K < 4) ?
			(t_move){TSIDE_AROUND(TAROUND_ETATOR(around_down, K % 4), TSIDE_BIGGEST), mod_twice} :
			(t_move){TSIDE_AROUND(TAROUND_ETATOR(around_up, K % 4), TSIDE_BIGGEST), mod_twice};
	}
	move[++J] = (t_move){TSIDE_AROUND(TAROUND_ETATOR(around_right, I), TSIDE_BIGGEST), mod_reverse};
	move[++J] = (t_move){TSIDE_BIGGEST, mod_null};
	move[++J] = (t_move){TSIDE_AROUND(TAROUND_ETATOR(around_down, I), TSIDE_BIGGEST), mod_reverse};
	if (edge ==  &BIN_EDGE_PRIM)
		move[++J] = (K < 4) ?
			(t_move){TSIDE_AROUND(TAROUND_ETATOR(around_down, K % 4), TSIDE_BIGGEST), mod_reverse} :
			(t_move){TSIDE_AROUND(TAROUND_ETATOR(around_up, K % 4), TSIDE_BIGGEST), mod_twice};
	return (J);
}

short		tab_tmove_edge_two(t_move move[NB_MOVE_MAX], t_binary binary[6],
				short index_corner)
{
	short	i[2];

	I = -1;
	while (++I < 3)
		if ((J = index_tab_tbin(
			TBIN_CONV_TSIDE(TSIDE_CORNER(index_corner, I), (BIN_CORNER | BIN_EDGE | BIN_EDGE_PRIM)),
				(t_binary[24]){
					0b100001000, 0b100000010, 0b001000010, 0b001100000, 0b000100001, 0b010000001, 0b010000100, 0b000001100,
					0b110001000, 0b100100010, 0b001001010, 0b011100000, 0b000100011, 0b010001001, 0b010100100, 0b000011100,
					0b100101000, 0b011000010, 0b000101001, 0b010000110, 0b000101100, 0b110000010, 0b001101000, 0b010000011
				}, 24) % 8) != -1)
		{
			if (J < 16)
				return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move[2]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_up, ((J % 8) / 2)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, ((J % 8) / 2)), TSIDE_CORNER(index_corner, I)), mod_null}
				})[J % 2])));
			else if (J < 20)
				return (copy_tab_tmove(move, ((t_move[4]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_right, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_up, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
				})));
			else
				return (copy_tab_tmove(move, ((t_move[4]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_right, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_down, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
				})));
	}
	return (0);
}

short		tab_tmove_right_angle(t_move move[NB_MOVE_MAX], t_binary binary[6],
				t_side side_destination)
{
	short		i[2];
	t_around	rotate;
	t_side 		tab_side_edge[6];
	t_binary	binary_angle[2];

	TAB_TSIDE_NULL(&TSIDE_BIGGEST);
	tab_tside_find_filled(&TSIDE_BIGGEST, BIN_RIGHT_ANGLE);
	if (TSIDE_BIGGEST == side_destination)
	 	return (0);
	BIN_ORIGIN = TBIN_CONV_TSIDE(TSIDE_BIGGEST, BIN_RIGHT_ANGLE);
	rotate = around_right;
	while (rotate != around_null && TSIDE_AROUND(rotate, TSIDE_BIGGEST) != side_destination)
	 	++rotate;
	BIN_LAYER = ((t_binary[2]){0b010000010, 0b000101000})[rotate % 2];
	if ((I = index_tab_tbin(((BIN_ORIGIN & BIN_LAYER) ^ BIN_ORIGIN),
		(t_binary[8]){0b001001000, 0b000001001, 0b000000011, 0b000000110,
			0b000100100, 0b100100000, 0b110000000, 0b011000000}, 8)) != -1)
		copy_tmove(&move[0], TSIDE_AROUND((I / 2), TSIDE_BIGGEST), !(I % 2) ? mod_null : mod_reverse);
	J = index_tab_tbin((BIN_ORIGIN & BIN_LAYER), // print bin_origin et bin_layer
		(t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4); // Ici J = -1
	move[1].side = TSIDE_AROUND(J, TSIDE_BIGGEST); // Segfault ici a cause de J
	if (rotate != around_null)
		move[1].mod = TSIDE_AROUND(TAROUND_ROTATE(J, 1), TSIDE_BIGGEST) == side_destination ?
			mod_reverse : mod_null;
	else
		move[1].mod = mod_twice;
	copy_tmove(&move[0], TSIDE_AROUND((I / 2), side_destination), (move[0].mod != mod_null) ? mod_null : mod_reverse);
	return (3);
}
