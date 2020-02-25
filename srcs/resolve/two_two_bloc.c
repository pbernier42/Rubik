/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_two_bloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:28:26 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/19 20:42:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[2];
	t_binary	binary[6];
	t_binary	edge[2][3];
	t_move		move[NB_MOVE_MAX];

	//if (!(corner[0] == 2 && corner[1] == 0 && corner[2] == 4))
	  // 	return ;

	I = INDEX_CORNER(corner);
	//printf("%d\n", I);
	printf("!!!!!!\n[%c][%c][%c]\n", STR_INITIALS_SIDE[corner[0]], STR_INITIALS_SIDE[corner[1]], STR_INITIALS_SIDE[corner[2]]);
	//ungly_display(cube);
	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]), edge, I);
	//ungly_display(cube);

	//ungly_display(cube);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]));
	tab_tbin_find_edge(TAB_BIN_EDGE_NEAR, TAB_TSTICKERS_CORNER[I]);
	BIN_EDGE_EXTREMITY = BIN_EDGES_NEAR | BIN_EDGES_OPPOSITE;
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[I]);
	I = index_tab_tstickers(BIN_CUBE ^ (BIN_CUBE & BIN_EDGE_EXTREMITY),
		TAB_TSTICKERS_EDGE, 12);
	NB_MOVE = tab_tmove_edge_middle(move, I, BIN_CORNER);
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_corner_less | arg_edge));
	NB_MOVE = tab_tmove_edge_near(move, binary);
	//print_tab_tmove((t_list){NB_MOVE, move});
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_edge | arg_corner_less | arg_cube_one));
	NB_MOVE = tab_tmove_twist_edge(move, binary, &BIN_EDGE);
	//print_tab_tmove((t_list){NB_MOVE, move});
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	I = INDEX_CORNER(corner);
	bring_edge_opposite(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[2]), edge, I);
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_edge | arg_edge_prim));
	I = INDEX_CORNER(corner);
	NB_MOVE = tab_tmove_edge_two(move, binary, I);
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//print_tab_tmove((t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_edge | arg_edge_prim | arg_cube_one));
	NB_MOVE = tab_tmove_rotate_prim(move, binary);
	//print_tab_tmove((t_list){NB_MOVE, move});
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_corner_less_prim | arg_edge_prim | arg_cube_one));
	NB_MOVE = tab_tmove_twist_edge(move, binary, &BIN_EDGE_PRIM);
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//print_tab_tmove((t_list){NB_MOVE, move});
	//ungly_display(cube);

	//ungly_display(cube);
	tbin_update(cube, binary, corner,
		(arg_corner | arg_edge_prim | arg_edge | arg_cube_one));
	NB_MOVE = tab_tmove_right_angle(move, binary, (t_side)corner[0]);
	read_tab_tmove(cube, (t_list){NB_MOVE, move});
	//print_tab_tmove((t_list){NB_MOVE, move});
	ungly_display(cube);
}

short		bring_edge_opposite(char ***cube, t_side color[3],
				t_binary edge[2][3], short index_corner)
{
	short		nb_move;
	t_binary	binary[2];
	t_move		move[NB_MOVE_MAX];


	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(color[0], color[1]));
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	tab_tbin_find_edge(TAB_BIN_EDGE_OPPOSITE, TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	nb_move = tab_tmove_edge_opposite(move, binary, TAB_BIN_EDGE_OPPOSITE,
	 	TAB_TSTICKERS_CORNER[(index_corner + 4) % 8]);
	return (read_tab_tmove(cube, (t_list){nb_move, move}));
}

short		tab_tmove_edge_opposite(t_move move[NB_MOVE_MAX], t_binary binary[2],
				t_binary tab_bin_edge_opposite[3],  t_sticker corner[3])
{
	short		i[2];
	t_binary	bin_reference;

	I = -1;
	while (++I < 3)
		if (tab_bin_edge_opposite[I] == (BIN_CUBE & tab_bin_edge_opposite[I]))
		{
			bin_reference = TBIN_CONV_TSIDE(corner[I].side,
				(tab_bin_edge_opposite[I] | BIN_CORNER));
			if ((J = index_tab_tbin(bin_reference,
				(t_binary[4]){0b000000011, 0b000100100, 0b110000000, 0b001001000}, 4)) != -1)
				return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move){corner[I].side, mod_null})), 1));
			else if ((J = index_tab_tbin(bin_reference,
				(t_binary[4]){0b011000000, 0b000001001, 0b000000110, 0b100100000}, 4)) != -1)
				return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move){corner[I].side, mod_reverse})), 1));
	}
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
		})), 1));
}

short		tab_tmove_edge_near(t_move move[NB_MOVE_MAX], t_binary binary[5])
{
	short		i;
	t_side		side_problem;
	t_side		side_reference;
	t_binary	bin_problem;

	side_problem = tside_find_biggest_weight(BIN_CORNER ^ BIN_CORNER_LESS);
	//bin(BIN_CORNER ^ BIN_CORNER_LESS);
	// if (!TBIN_CONV_TSIDE(side_problem, (BIN_CORNER_LESS | BIN_EDGE)))
	// 	return (0);
	bin_problem = TBIN_CONV_TSIDE(side_problem, (BIN_CORNER | BIN_EDGE));
	if ((i = index_tab_tbin(bin_problem,
		(t_binary[4]){0b011000000, 0b100100000, 0b000000110, 0b000001001}, 4)) != -1)
	{
		side_reference = TSIDE_AROUND(TAROUND_ETATOR(around_up, i), side_problem);
		copy_tab_tmove(move, (t_move[6]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_right, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down,  i), side_reference), mod_null},
			{side_reference, mod_null}
		}, 6);
	}
	else if ((i = index_tab_tbin(bin_problem,
		(t_binary[4]){0b110000000, 0b000100100, 0b000000011, 0b001001000}, 4)) != -1)
	{
		side_reference = TSIDE_AROUND(TAROUND_ETATOR(around_up, i), side_problem);
		copy_tab_tmove(move, (t_move[6]){
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_left, i), side_reference), mod_null},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_left, i), side_reference), mod_reverse},
			{TSIDE_AROUND(TAROUND_ETATOR(around_down, i), side_reference), mod_reverse},
			{side_reference, mod_reverse}
		}, 6);
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

	//corner_less
	if ((tside_find_biggest_weight((*edge | BIN_CORNER_LESS) & BIN_CUBE)) != side_null)
		return (0);
	TAB_TSIDE_NULL(tab_side_edge);
	tab_tside_find_filled(tab_side_edge, *edge & BIN_CUBE);
	//bin ((*edge | BIN_CORNER_LESS) & BIN_CUBE);
	bin_problem = TBIN_CONV_TSIDE(TSIDE_BIGGEST, (*edge | BIN_CORNER_LESS) & BIN_CUBE);
	I = index_tab_tbin(bin_problem, (t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4);

	//bin(TBIN_CONV_TSIDE(TSIDE_BIGGEST, (*edge | BIN_CORNER_LESS)));
	J = index_tab_tbin(bin_problem | TBIN_CONV_TSIDE(TSIDE_BIGGEST, (*edge | BIN_CORNER_LESS)),
	 		(t_binary[8]){
	 			0b001001000, 0b000000011, 0b000100100, 0b110000000,
	 			0b000001001, 0b000000110, 0b100100000, 0b011000000}, 8);

	//bin(bin_problem);
	//printf("%s\n", STR_SIDE(TSIDE_BIGGEST));
	//printf("%i, %i\n", I, J);
	//printf("%d %d %s\n", I, J, STR_SIDE(TSIDE_BIGGEST));
	move[0] = (t_move){TSIDE_AROUND(TAROUND_ROTATE((J < 4) ? around_up : around_down, J % 4), TSIDE_BIGGEST), mod_twice};
	move[1] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_right, I), TSIDE_BIGGEST), mod_reverse};
	move[2] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_down, I), TSIDE_BIGGEST), mod_reverse};
	move[3] = (t_move){TSIDE_BIGGEST, mod_reverse};
	move[4].side = TSIDE_AROUND(TAROUND_ROTATE((J < 4) ? around_up : around_down, J % 4), TSIDE_BIGGEST);
	move[4].mod = move[0].side == move[2].side ? mod_reverse : mod_twice;
	return (5);
}

short		tab_tmove_edge_two(t_move move[NB_MOVE_MAX], t_binary binary[6],
				short index_corner)
{
	short	i[2];

	I = -1;
	//bin();
	// printf("[%d]\n", index_corner);
	// printf("[%s][%s][%s]\n", STR_SIDE(TSIDE_CORNER(index_corner, 0)),
	// 	STR_SIDE(TSIDE_CORNER(index_corner, 1)),
	// 	STR_SIDE(TSIDE_CORNER(index_corner, 2)));

	//bin((BIN_CORNER | BIN_EDGE | BIN_EDGE_PRIM));
	while (++I < 3)
		if ((J = index_tab_tbin(
			TBIN_CONV_TSIDE(TSIDE_CORNER(index_corner, I), (BIN_CORNER | BIN_EDGE | BIN_EDGE_PRIM)),
				(t_binary[24]){
					0b100001000, 0b100000010, 0b001000010, 0b001100000, 0b000100001, 0b010000001, 0b010000100, 0b000001100,

					0b110001000, 0b100100010, 0b001001010, 0b011100000, 0b000100011, 0b010001001, 0b010100100, 0b000011100,

					0b100101000, 0b011000010, 0b000101001, 0b010000110,
					0b000101100, 0b110000010, 0b001101000, 0b010000011
				}, 24)) != -1)
		{
			if (J < 16)
				return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move[2]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_up, ((J % 8) / 2)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, ((J % 8) / 2)), TSIDE_CORNER(index_corner, I)), mod_null}
				})[J % 2]), 1));
			else if (J < 20)
				return (copy_tab_tmove(move, ((t_move[4]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_right, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_up, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse}
				}), 4));
			else
				return (copy_tab_tmove(move, ((t_move[4]){
					{TSIDE_AROUND(TAROUND_ROTATE(around_right, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_down, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_reverse},
					{TSIDE_AROUND(TAROUND_ROTATE(around_left, (J % 8)), TSIDE_CORNER(index_corner, I)), mod_null}
				}), 4));
	}
	return (0);
}

short		tab_tmove_rotate_prim(t_move move[NB_MOVE_MAX], t_binary binary[6])
{
	t_side		side_angle;
	t_binary	bin_angle;
	short		rotate;

	side_angle = tside_find_biggest_weight(BIN_RIGHT_ANGLE & BIN_CUBE);
	bin_angle = TBIN_CONV_TSIDE(side_angle, BIN_RIGHT_ANGLE & BIN_CUBE);
	if (nb_byte_tbin(TBIN_CONV_TSIDE(side_angle, BIN_RIGHT_ANGLE), 9) == 3)
		return (0);

	// printf("[%s]\n", STR_SIDE(TSIDE_ANGLE));
	// bin((BIN_CORNER | BIN_EDGE | BIN_EDGE_PRIM) & BIN_CUBE);
	// bin(bin_angle);

	// bin(BIN_RIGHT_ANGLE & BIN_CUBE);
	// printf("[%s]\n", STR_SIDE(side_angle));
	// bin(bin_angle);
	if ((rotate = index_tab_tbin(bin_angle, (t_binary[4]){
		0b000000011, 0b000100100, 0b110000000, 0b001001000}, 4)) != -1)
	{
		move[0] = (t_move){side_angle, mod_null};
		move[1] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_right, rotate % 4), side_angle), mod_twice};
		move[2] = (t_move){side_angle, mod_reverse};
		move[3] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_down, rotate % 4), side_angle), mod_reverse};
		move[4] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_right, rotate % 4), side_angle), mod_reverse};
		move[5] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_down, rotate % 4), side_angle), mod_null};
	}
	else if ((rotate = index_tab_tbin(bin_angle, (t_binary[4]){
		0b011000000, 0b000001001, 0b000000110, 0b100100000}, 4)) != -1)
	{
		move[0] = (t_move){side_angle, mod_reverse};
		move[1] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_right, rotate % 4), side_angle), mod_twice};
		move[2] = (t_move){side_angle, mod_null};
		move[3] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_up, rotate % 4), side_angle), mod_null};
		move[4] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_right, rotate % 4), side_angle), mod_null};
		move[5] = (t_move){TSIDE_AROUND(TAROUND_ROTATE(around_up, rotate % 4), side_angle), mod_reverse};
	}
	else
		return (0);
	return (6);
}

short		tab_tmove_right_angle(t_move move[NB_MOVE_MAX], t_binary binary[6],
				t_side side_destination)
{
	short		i[2];
	t_around	rotate;
	t_side 		side_angle;
	t_binary	binary_angle[2];

	//printf("%s\n", STR_SIDE(side_destination));
	//bin(BIN_RIGHT_ANGLE);
	side_angle = tside_find_biggest_weight(BIN_RIGHT_ANGLE);
	if (side_angle == side_destination)
	 	return (0);

	//printf("%s\n", STR_SIDE(side_destination));
	// printf("(%d) %d\n", side_destination, tab_side_edge[0]);
	// bin(BIN_RIGHT_ANGLE);
	BIN_ORIGIN = TBIN_CONV_TSIDE(side_angle, BIN_RIGHT_ANGLE);

	rotate = around_right;
	while (rotate != around_null && TSIDE_AROUND(rotate, side_angle) != side_destination)
	 	++rotate;

	//printf("{%s}\n", STR_SIDE(TSIDE_AROUND(rotate, side_angle)));

	BIN_LAYER = ((t_binary[2]){0b010000010, 0b000101000})[rotate % 2];


	// move[0] = (t_move)TMOVE_NULL;
	// move[1] = (t_move)TMOVE_NULL;
	// move[2] = (t_move)TMOVE_NULL;

	//bin(((BIN_ORIGIN & BIN_LAYER) ^ BIN_ORIGIN));

	if ((I = index_tab_tbin(((BIN_ORIGIN & BIN_LAYER) ^ BIN_ORIGIN),
		(t_binary[8]){0b001001000, 0b000001001, 0b000000011, 0b000000110,
			0b000100100, 0b100100000, 0b110000000, 0b011000000}, 8)) != -1)
		copy_tmove(&move[0], TSIDE_AROUND((I / 2), side_angle), !(I % 2) ? mod_null : mod_reverse);

	//bin((BIN_ORIGIN & BIN_LAYER));
	J = index_tab_tbin((BIN_ORIGIN & BIN_LAYER), // print bin_origin et bin_layer
		(t_binary[4]){0b000001000, 0b000000010, 0b000100000, 0b010000000}, 4); // Ici J = -1
	move[1].side = TSIDE_AROUND(J, side_angle); // Segfault ici a cause de J
	if (rotate != around_null)
		move[1].mod = TSIDE_AROUND(TAROUND_ROTATE(J, 1), side_angle) == side_destination ?
			mod_reverse : mod_null;
	else
		move[1].mod = mod_twice;
	copy_tmove(&move[2], TSIDE_AROUND((I / 2), side_destination), (move[0].mod != mod_null) ? mod_null : mod_reverse);
	return (3);
}
