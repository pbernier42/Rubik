/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:04:09 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/13 19:04:11 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		two_two_bloc(char ***cube, t_color corner[3]);
t_binary	bloc_binary(char ***cube, t_side side[3]);
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

t_move		condition(t_binary binary, t_condition *conditions)
{
	short	i;

	i = -1;
	while ((conditions) && (conditions[++i].side != side_null))
	{
		if (conditions[i].binary == (binary & conditions[i].binary))
			return ((t_move){conditions[i].side, conditions[i].mod});
	}
	return ((t_move){side_null, mod_null});
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


# define EDGE_OPPOSITE			(edge[0])
# define EDGE_NEAR				(edge[1])


# define TURN_SIDE(side, mod)	turn_multiple(instruction_turn(cube, side), mod)

# define I						i[0]
# define J						i[1]
# define K						i[2]

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[3];
	bool		found;
	t_binary	edge[2][3];
	t_binary	binary[4];
	t_action	action;

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
		TURN_SIDE(TAB_BIN_CORNER[(I + 4) % 8][J].side, mod_null);
	BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
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

			t_move	tmp;


			tmp = condition(action.binary,
				(t_condition[8]){
					{0b100001000, AROUND(action.side)[3].side, mod_reverse},
					{0b100000010, AROUND(action.side)[2].side, mod_null},
					{0b001100000, AROUND(action.side)[3].side, mod_null},
					{0b001000010, AROUND(action.side)[0].side, mod_reverse},
					{0b010000100, AROUND(action.side)[2].side, mod_reverse},
					{0b000001100, AROUND(action.side)[1].side, mod_null},
					{0b010000001, AROUND(action.side)[0].side, mod_null},
					{0b000100001, AROUND(action.side)[1].side, mod_reverse}
				});
			TURN_SIDE(tmp.side, tmp.mod);
			//bin(action.binary);
			//printf("%d...\n", commun_side(BIN_CORNER + BIN_EDGE));
			//printf("%d\n", commun_side(BIN_CORNER + BIN_EDGE));
			//	printf("%d - %d\n", TAB_BIN_EDGE[K][0].side, TAB_BIN_EDGE[K][1].side);
			//	printf("%d - %d - %d\n", TAB_BIN_CORNER[I][0].side,
			//	TAB_BIN_CORNER[I][1].side, TAB_BIN_CORNER[I][2].side);
		}
	}
	//bin(BIN_EXTREMITY_EDGE);

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
