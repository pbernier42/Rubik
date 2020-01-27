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

void		resolve(char ***cube)
{
	//nb_instruction = 0
	//tmp_instrucyion = NULL;

	//while (tmp_instrcution > atuel)
	//{
		//ACTUEL =
		two_two_bloc(cube, (t_color[3]){color_red, color_yellow, color_blue});
		//
	//}

	//bin(coor_binary(tmp));
	//1000000000000000000000001000000000000010000000
	// 1000000000000000000000001000000000000010000000000000000

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


void	fill_move(t_move ret[#DEFINE], t_move move[#DEFINE])
{
	short	i;

	i = -1;
	while (++i < #DEFINE)
	{
		ret[i].side = move.side[i];
		ret[i].mod = move.mod[i];
	}
}

# define I						i[0]
# define J						i[1]
# define K						i[2]

void	condition(t_move move[#DEFINE], t_binary binary, t_condition *conditions)
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

void	execute_move(char ***cube, t_move move[#DEFINE])
{
	short	i;

	i = 0;
	while (i < #DEFINE && move[i].side != side_null)
	{
		turn_multiple(instruction_turn(cube, move[i].side), move[i].mod);
		++i;
	}
}


# define FACE_NULL				{side_null, {-1, -1}}

# define BIN_FRONT_UP_LEFT		{{side_front, {0, 0}}, {side_up, {2, 0}}, {side_left, {0, 2}}}
# define BIN_FRONT_UP_RIGHT		{{side_front, {0, 2}}, {side_up, {2, 2}}, {side_right, {0, 0}}}
# define BIN_FRONT_DOWN_RIGHT	{{side_front, {2, 2}}, {side_down, {0, 2}}, {side_right, {2, 0}}}
# define BIN_FRONT_DOWN_LEFT	{{side_front, {2, 0}}, {side_down, {0, 0}}, {side_left, {2, 2}}}

# define BIN_BACK_DOWN_RIGHT	{{side_back, {2, 0}}, {side_down, {2, 2}}, {side_right, {2, 2}}}
# define BIN_BACK_DOWN_LEFT		{{side_back, {2, 2}}, {side_down, {2, 0}}, {side_left, {2, 0}}}
# define BIN_BACK_UP_LEFT		{{side_back, {0, 2}}, {side_up, {0, 0}}, {side_left, {0, 0}}}
# define BIN_BACK_UP_RIGHT		{{side_back, {0, 0}}, {side_up, {0, 2}}, {side_right, {0, 2}}}

# define TAB_BIN_FRONT_CORNER	BIN_FRONT_UP_LEFT, BIN_FRONT_UP_RIGHT, BIN_FRONT_DOWN_RIGHT, BIN_FRONT_DOWN_LEFT
# define TAB_BIN_BACK_CORNER	BIN_BACK_DOWN_RIGHT, BIN_BACK_DOWN_LEFT, BIN_BACK_UP_LEFT, BIN_BACK_UP_RIGHT

# define TAB_BIN_CORNER			((t_face[8][3]){TAB_BIN_FRONT_CORNER, TAB_BIN_BACK_CORNER})

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

# define BIN_CUBE 				(binary[0])
# define BIN_CORNER				(binary[1])
# define BIN_EDGE				(binary[2])
# define BIN_EXTREMITY_EDGE		(binary[3])
# define BIN_CORNER_LESS		(binary[4])


# define EDGE_OPPOSITE			(edge[0])
# define EDGE_NEAR				(edge[1])

# define side_of(around_side, reference_side)	AROUND(reference_side)[around_side].side

# define ROTATE_AROUND(around_side, nb)		((around_side + nb) % 3)
# define ROTATE_DNUORA(around_side, nb)		((around_side - nb) % 3)

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[3];
	bool		found;
	t_binary	edge[2][3];
	t_binary	binary[5];
	t_action	action;
	t_move		move[#DEFINE];

	I = -1;
	found = false;
	BIN_CORNER = 0;
	BIN_CUBE = bloc_binary(cube, (t_side*)corner);
	while (!found && ++I < 8)
	{
		BIN_CORNER = coor_binary(TAB_BIN_CORNER[I]);
		found = (BIN_CORNER == (BIN_CUBE & BIN_CORNER));
	}
	BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	edge_corner(EDGE_OPPOSITE, TAB_BIN_CORNER[(I + 4) % 8]);
	J = -1;
	found = false;
	while (!found && ++J < 3)
		found = (EDGE_OPPOSITE[J] == (BIN_CUBE & EDGE_OPPOSITE[J]));
	if (found)
	{
		//(TAB_BIN_CORNER[(I + 4) % 8][J].side, mod_null)
		fill_move(move, );
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
			action = commun_side(BIN_CORNER | BIN_EDGE);
			//ICI
			condition(move, action.binary,
				(t_condition[8]){
					{0b100001000, side_of(around_up, action.side), mod_reverse},
					{0b100000010, side_of(around_left, action.side), mod_null},
					{0b001100000, side_of(around_up, action.side), mod_null},
					{0b001000010, side_of(around_right, action.side), mod_reverse},
					{0b010000100, side_of(around_left, action.side), mod_reverse},
					{0b000001100, side_of(around_down, action.side), mod_null},
					{0b010000001, side_of(around_right, action.side), mod_null},
					{0b000100001, side_of(around_down, action.side), mod_reverse}
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

		if ((I = bin_comp_and_tab(action.binary, (t_binary[4]){
			0b011000000, 0b100100000, 0b000000110, 0b000001001}) != -1)
			action.side = side_of(ROTATE_DNUORA(around_up, I);

			fill_move(move,
				{side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse}
				{side_of(ROTATE_DNUORA(around_right, I), action.side), mod_reverse}
				{side_of(ROTATE_DNUORA(around_down, I), action.side), mod_null}
				{side_of(ROTATE_DNUORA(around_right, I), action.side), mod_null}
				{side_of(ROTATE_DNUORA(around_down,  I), action.side), mod_null}
				{action.side, mod_null}
			});
		else if ((I = bin_comp_and_tab(action.binary, (t_binary[4]){
			0b110000000, 0b000100100, 0b000000011, 0b001001000}) != -1))
			action.side = side_of(ROTATE_DNUORA(around_up, I);
			fill_move(move,
				{side_of(ROTATE_DNUORA(around_down, I), action.side), mod_null}
				{side_of(ROTATE_DNUORA(around_left, I), action.side), mod_null}
				{side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse}
				{side_of(ROTATE_DNUORA(around_left, I), action.side), mod_reverse}
				{side_of(ROTATE_DNUORA(around_down, I), action.side), mod_reverse}
				{action.side, mod_reverse}
			});
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

# define FACE(face)		(bloc[face])

t_face	find_sticker(t_face bloc[2])
{
	t_line		line;
	bool		found;
	short		i;

	i = -1;
	found = false;


	while (!found)
	{
		line = AROUND(FACE(0).side)[++i];
		if (line.side == FACE(1).side)
			found = true;
	}
	return ((t_face){line.side, {line.coo[1][0], line.coo[1][1]}});
}

void	edge_corner(t_binary edge_linked[3], t_face bloc[3])
{
	t_face		sticker[2];


	sticker[0] = find_sticker((t_face[2]){FACE(0), FACE(1)});
	sticker[1] = find_sticker((t_face[2]){FACE(1), FACE(0)});
	// printf("\n");
	// printf(".[%d] -> [%d][%d]\n", sticker[0].side, sticker[0].coo[0], sticker[0].coo[1]);
	// printf(".[%d] -> [%d][%d]\n", sticker[1].side, sticker[1].coo[0], sticker[1].coo[1]);
	// printf("\n");
	edge_linked[0] = coor_binary((t_face[3]){sticker[0], sticker[1], {side_null, {0, 0}}});
	sticker[0] = find_sticker((t_face[2]){FACE(1), FACE(2)});
	sticker[1] = find_sticker((t_face[2]){FACE(2), FACE(1)});
	edge_linked[1] = coor_binary((t_face[3]){sticker[0], sticker[1], {side_null, {0, 0}}});
	sticker[0] = find_sticker((t_face[2]){FACE(2), FACE(0)});
	sticker[1] = find_sticker((t_face[2]){FACE(0), FACE(2)});
	edge_linked[2] = coor_binary((t_face[3]){sticker[0], sticker[1], {side_null, {0, 0}}});
}

# define SEL_SIDE	(side_len[1])

t_binary	bloc_binary(char ***cube, t_side side[3])
{
	t_side		side_len;
	short		side_select;
	t_binary	binary;

	side_len = side_front;
	binary = 0;
	while (side_len != side_null)
	{
		binary = binary << 9;
		side_select = -1;
		while (++side_select < 3)
			binary += side_binary(cube[side_len], side[side_select]);
		++side_len;
	}
	return (binary);
}

# define Y	coo[0]
# define X	coo[1]

t_binary	side_binary(char **cube_side, t_side side)
{
	short		coo[2];
	t_binary	binary;

	Y = -1;
	binary = 0;
	while (side != side_null && ++Y != 3)
	{
		X = -1;
		while (++X != 3)
		{
			binary = binary << 1;
			if (cube_side[Y][X] == INITIALS_SIDE[side])
				++binary;
		}
	}
	return (binary);
}


# define SIDE_TAB	((t_side[3]){bloc[0].side, bloc[1].side, bloc[2].side})
# define POS_COO	(((bloc[i].Y * 3) + bloc[i].X) + 1)

t_binary	coor_binary(t_face bloc[3])
{
	t_binary	binary;
	t_side		side;
	short		i;

	side = side_front;
	binary = 0;
	while (side != side_null)
	{
		if ((i = in_side_tab(side, SIDE_TAB, 3)) != -1)
		{
			binary = binary << POS_COO;
		 	binary += 1;
		 	binary = binary << (9 - POS_COO);
		}
		else
			binary = binary << 9;
		++side;
	}
	return (binary);
};
