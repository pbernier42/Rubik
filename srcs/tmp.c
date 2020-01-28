/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:04:09 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/24 18:58:06 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		two_two_bloc(char ***cube, t_color corner[3]);
t_binary	side_binary(char **cube_side, t_side side);
t_binary	coor_binary(t_face bloc[3]);
void		edge_corner(t_binary edge_linked[3], t_face bloc[3]);

void		bin(t_binary nbr)
{
	int		i;
	char	cube[54];

	i = 54;
	printf("[%llu]\n", nbr);
	while (--i != -1)
	{
		if (nbr)
		{
			cube[i] = (nbr % 2) + '0';
			nbr /= 2;
		}
		else
			cube[i] = '0';
	}
	if ((nbr))
		printf("[%llu]\n", nbr);
	printf("F %.3s %.3s %.3s\n", &cube[0], &cube[3], &cube[6]);
	printf("R %.3s %.3s %.3s\n", &cube[9], &cube[12], &cube[15]);
	printf("U %.3s %.3s %.3s\n", &cube[18], &cube[21], &cube[24]);
	printf("B %.3s %.3s %.3s\n", &cube[27], &cube[30], &cube[33]);
	printf("L %.3s %.3s %.3s\n", &cube[36], &cube[39], &cube[42]);
	printf("D %.3s %.3s %.3s\n", &cube[45], &cube[48], &cube[51]);
}

t_action	commun_side(t_binary corner_edge)
{
	t_side		side;
	bool		found;
	short		i;
	t_binary	ret;

	side = side_front;
	while (side != side_null)
	{
		found = false;
		i = -1;
		ret = corner_edge;
		while (++i < 9)
		{
			if ((corner_edge % 2))
			{
				if (found)
					return ((t_action){(5 - side), (ret & 511)});
				found = true;
			}
			corner_edge = corner_edge >> 1;
		}
		++side;
	}
	return ((t_action){side, 0});
}


void	fill_move(t_move ret[NB_ITER], t_move move[NB_ITER])
{
	short	i;

	i = -1;
	while (++i < NB_ITER)
	{
		ret[i].side = move.side[i];
		ret[i].mod = move.mod[i];
	}
}

# define I						i[0]
# define J						i[1]
# define K						i[2]

void	condition(t_move move[NB_ITER], t_binary binary, t_condition *conditions)
{
	short	i[2];

	I = -1;
	while ((conditions) && (conditions[++I].side != side_null))
	{
		if (conditions[I].binary == (binary & conditions[I].binary))
		{
			fill_move(move[J], conditions[I]);
			return ;
		}
	}
}

short	bin_comp_and_tab(t_binary binary, t_binary *tab_binary)
{
	short	i;

	i = -1;
	while ((tab_binary) && (tab_binary[++i]))
	{
		if (tab_binary[i] == (binary & tab_binary[i]))
			return (i);
	}
	return (i);
}

void	execute_move(char ***cube, t_move move[NB_ITER])
{
	short	i;

	i = 0;
	while (i < NB_ITER && move[i].side != side_null)
	{
		turn_multiple(instruction_turn(cube, move[i].side), move[i].mod);
		++i;
	}
}




# define BIN_FRONT_UP			{{side_front, {0, 1}}, {side_up, {2, 1}}, FACE_NULL}
# define BIN_FRONT_RIGHT		{{side_front, {1, 2}}, {side_right, {1, 0}}, FACE_NULL}
# define BIN_FRONT_DOWN			{{side_front, {2, 1}}, {side_down, {0, 1}}, FACE_NULL}
# define BIN_FRONT_LEFT			{{side_front, {1, 0}}, {side_left, {1, 2}}, FACE_NULL}

# define BIN_LEFT_UP			{{side_left, {0, 1}}, {side_up, {1, 0}}, FACE_NULL}
# define BIN_RIGHT_UP			{{side_right, {0, 1}}, {side_up, {1, 2}}, FACE_NULL}

# define BIN_BACK_DOWN			{{side_back, {2, 1}}, {side_down, {2, 1}}, FACE_NULL}
# define BIN_BACK_LEFT			{{side_back, {1, 0}}, {side_left, {1, 0}}, FACE_NULL}
# define BIN_BACK_UP			{{side_back, {0, 1}}, {side_up, {0, 1}}, FACE_NULL}
# define BIN_BACK_RIGHT			{{side_back, {1, 2}}, {side_right, {1, 2}}, FACE_NULL}

# define BIN_RIGHT_DOWN			{{side_right, {0, 1}}, {side_down, {1, 2}}, FACE_NULL}
# define BIN_LEFT_DOWN			{{side_left, {2, 1}}, {side_down, {1, 0}}, FACE_NULL}

# define TAB_BIN_FRONT_EDGE		BIN_FRONT_UP, BIN_FRONT_RIGHT, BIN_FRONT_DOWN, BIN_FRONT_LEFT
# define TAB_BIN_TOP_EDGE		BIN_LEFT_UP, BIN_RIGHT_UP
# define TAB_BIN_BACK_EDGE		BIN_BACK_DOWN, BIN_BACK_LEFT, BIN_BACK_UP, BIN_BACK_RIGHT
# define TAB_BIN_DOWN_EDGE		BIN_RIGHT_DOWN, BIN_LEFT_DOWN

# define TAB_BIN_EDGE			((t_face[12][3]){TAB_BIN_FRONT_EDGE, TAB_BIN_TOP_EDGE, TAB_BIN_BACK_EDGE, TAB_BIN_DOWN_EDGE})


# define BIN_EDGE				(binary[2])
# define BIN_EXTREMITY_EDGE		(binary[3])
# define BIN_CORNER_LESS		(binary[4])


# define EDGE_OPPOSITE			(edge[0])
# define EDGE_NEAR				(edge[1])

# define side_of(around_side, reference_side)	AROUND(reference_side)[around_side].side

# define ROTATE_AROUND(around_side, nb)		((around_side + nb) % 3)
# define ROTATE_DNUORA(around_side, nb)		((around_side - nb) % 3)

# define T_MOVE_NULL			{side_null, mod_null}
# define PAD_FIVE_MOVE			T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL
# define RESET_MOVE(move)    	fill_move(move, t_move[NB_ITER]({PAD_FIVE_MOVE}))
# define PAD_FOUR_SIDE			side_null, side_null, side_null, side_null
# define PAD_FOUR_MOD			mod_null, mod_null, mod_null, mod_null

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[3];
	bool		found;
	t_binary	edge[2][3];
	t_binary	binary[5];
	t_action	action;
	t_move		move[NB_ITER];

	J = -1;
	found = false;
	while (!found && ++J < 3)
		found = (EDGE_OPPOSITE[J] == (BIN_CUBE & EDGE_OPPOSITE[J]));
	if (found)
	{
		RESET_MOVE(move);
		move[0] = ((t_move){TAB_BIN_CORNER[(I + 4) % 8][J].side, mod_null});
		execute_move(cube, move);
		BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	}
	edge_corner(EDGE_NEAR, TAB_BIN_CORNER[I]);

	BIN_EXTREMITY_EDGE = combine_binary((t_binary[6]){
		EDGE_OPPOSITE[0], EDGE_OPPOSITE[1], EDGE_OPPOSITE[2],
		EDGE_NEAR[0], EDGE_NEAR[1], EDGE_NEAR[2]}, 6);

	K = -1;
	found = false;
	while (!found && ++K < 12)
	{
		BIN_EDGE = coor_binary(TAB_BIN_EDGE[K]);
		if (BIN_EDGE != (BIN_EXTREMITY_EDGE & BIN_EDGE) &&
			BIN_EDGE == (BIN_CUBE & BIN_EDGE))
		{
			RESET_MOVE(move);
			action = commun_side(BIN_CORNER | BIN_EDGE);
			//ICI
			condition(move, action.binary,
				(t_condition[8]){
					{0b100001000,
						((t_side[NB_ITER]){side_of(around_up, action.side), PAD_FOUR_SIDE}),
						((t_mod[NB_ITER]){mod_reverse, PAD_FOUR_MOD})},
					{0b100000010,
						((t_side[NB_ITER]){side_of(around_left, action.side), PAD_FOUR_SIDE}),
						 mod_null},
					{0b001100000,
						((t_side[NB_ITER]){side_of(around_up, action.side), PAD_FOUR_SIDE}),
						 mod_null},
					{0b001000010,
						((t_side[NB_ITER]){side_of(around_right, action.side), PAD_FOUR_SIDE}),
						mod_reverse},
					{0b010000100,
						((t_side[NB_ITER]){side_of(around_left, action.side), mod_reverse},
					{0b000001100,
						((t_side[NB_ITER]){side_of(around_down, action.side), mod_null},
					{0b010000001,
						((t_side[NB_ITER]){side_of(around_right, action.side), mod_null},
					{0b000100001,
						((t_side[NB_ITER]){side_of(around_down, action.side), mod_reverse}
				});
			execute_move(cube, move);
			found = true;
		}
	}

	I = -1;
	found = false;
	BIN_CUBE = bloc_binary(cube, (t_side*)corner);
	while (!found && ++I < 8)
	{
		BIN_CORNER = coor_binary(TAB_BIN_CORNER[I]);
		found = (BIN_CORNER == (BIN_CUBE & BIN_CORNER));
	}
	BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	BIN_CORNER_LESS = (BIN_CUBE & BIN_CORNER);
	found = false;


	action.side = side_front;
	while (!found && action.side != side_null)
	{
		if (stob((t_side[1]){action.side}, 1, BIN_CORNER ^ BIN_CORNER_LESS))
			found = true;
		else
			++action.side;
	}
	if ((stob((t_side[1]){action.side}, 1, BIN_CORNER_LESS | BIN_EDGE)))
	{
		action.binary = stob((t_side[1]){action.side}, 1, BIN_CORNER | BIN_EDGE);
		RESET_MOVE(move);
		if ((I = bin_comp_and_tab(action.binary, (t_binary[4]){
			0b011000000, 0b100100000, 0b000000110, 0b000001001}) != -1)
		{
			action.side = side_of(ROTATE_DNUORA(around_up, I);
			move[0] = ((t_move){side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse});
			move[1] = ((t_move){side_of(ROTATE_DNUORA(around_right, I), action.side), mod_reverse});
			move[2] = ((t_move){side_of(ROTATE_DNUORA(around_down, I), action.side), mod_null});
			move[3] = ((t_move){side_of(ROTATE_DNUORA(around_right, I), action.side), mod_null});
			move[4] = ((t_move){side_of(ROTATE_DNUORA(around_down,  I), action.side), mod_null});
			move[5] = ((t_move){action.side, mod_null});
		}
		else if ((I = bin_comp_and_tab(action.binary, (t_binary[4]){
			0b110000000, 0b000100100, 0b000000011, 0b001001000}) != -1))
		{
			action.side = side_of(ROTATE_DNUORA(around_up, I);
			move[0] = ((t_move){side_of(ROTATE_DNUORA(around_down, I), action.side), mod_null});
			move[1] = ((t_move){side_of(ROTATE_DNUORA(around_left, I), action.side), mod_null});
			move[2] = ((t_move){side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse});
			move[3] = ((t_move){side_of(ROTATE_DNUORA(around_left, I), action.side), mod_reverse});
			move[4] = ((t_move){side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse});
			move[5] = ((t_move){action.side, mod_reverse});
		}
		execute_move(cube, move);
	}


	I = -1;
	found = false;
	BIN_CUBE = bloc_binary(cube, (t_side*)corner);
	while (!found && ++I < 8)
	{
		BIN_CORNER = coor_binary(TAB_BIN_CORNER[I]);
		found = (BIN_CORNER == (BIN_CUBE & BIN_CORNER));
	}
	edge_corner(EDGE_NEAR, TAB_BIN_CORNER[I]);
	BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	BIN_CORNER_LESS = (BIN_CUBE & BIN_CORNER);

	// J = -1;
	// found = false;
	// while (!found && ++J < 3)
	// 	found = (EDGE_NEAR[J] == (BIN_CUBE & EDGE_NEAR[J]));
	//
	// found = false;
	// action.side = side_front;
	// while (!found && action.side != side_null)
	// {
	// 	if (stob((t_side[1]){action.side}, 1, EDGE_NEAR[J] & BIN_CORNER_LESS))
	// 		found = true;
	// 	else
	// 		++action.side;
	// }


	// I = -1;
	// found = false;
	// BIN_CUBE = bloc_binary(cube, (t_side*)corner);
	// while (!found && ++I < 8)
	// {
	// 	BIN_CORNER = coor_binary(TAB_BIN_CORNER[I]);
	// 	found = (BIN_CORNER == (BIN_CUBE & BIN_CORNER));
	// }
	// BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	// BIN_CORNER_LESS = (BIN_CUBE & BIN_CORNER);
	// found = false;


	//bin(BIN_CORNER_LESS | BIN_EDGE);
	//bin(BIN_CUBE);
	//BIN_CORNER_LESS = (BIN_CUBE & BIN_CORNER);

	//EDGE_NEAR
	//EDGE_OPOSIT




	//1 coup
}




//# define SEL_SIDE	(side_len[1])