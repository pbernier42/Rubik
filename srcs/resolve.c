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
	two_two_bloc(cube, (t_color[3]){color_red, color_yellow, color_blue});


	//bin(coor_binary(tmp));
	//1000000000000000000000001000000000000010000000
	// 1000000000000000000000001000000000000010000000000000000

}


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

# define BIN_CUBE 				(binary[0])
# define BIN_CORNER				(binary[1])

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i;
	bool		found;
	t_binary	edge[3];
	t_binary	binary[2];

	i = -1;
	found = false;
	BIN_CORNER = 0;
	BIN_CUBE = bloc_binary(cube, (t_side*)corner);
	while (!found && ++i < 8)
	{
		BIN_CORNER = coor_binary(TAB_BIN_CORNER[i]);
		found = (BIN_CORNER == (BIN_CUBE & BIN_CORNER));
	}

	//printf("{%d}{%d}{%d}[%d]\n", corner[0], corner[1], corner[2], i);
	BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[1], (t_side)corner[2], side_null});
	edge_corner(edge, TAB_BIN_CORNER[(i + 4) % 8]);

	bin(edge[0]);
	bin(edge[1]);
	bin(edge[2]);
	//bin(BIN_CUBE);

	//bin(BIN_CORNER);
	// (void)move;
}


void	edge_corner(t_binary edge_linked[3], t_face bloc[3])
{
	t_line	line[2];
	bool	found[2];
	short	i[2];

	found[0] = false;
	found[1] = false;
	i[0] = -1;
	while (++i[0] < 3)
	{
		i[1] = -1;
		while (!found[0])
		{
			line[0] = AROUND(bloc[i[0]].side)[++i[1]];
			found[0] = (line[0].side == bloc[1].side);
		}
		i[1] = -1;
		while (!found[1])
		{
			line[1] = AROUND(bloc[(i[0] + 1) % 2].side)[++i[1]];
			found[1] = (line[1].side == bloc[2].side);
		}

		edge_linked[i[0]] = coor_binary((t_face[3]){
			{bloc[i[0]].side, {line[0].coo[1][0], line[0].coo[1][1]}},
			{bloc[(i[0] + 1) % 2].side, {line[1].coo[1][0], line[1].coo[1][1]}},
			{side_null, {0, 0}}});
	}
	//printf("[%d][%d]\n[%d][%d]\n", bloc[0].side, bloc[1].side, line.coo[1][0], line.coo[1][1]);

	(void)edge_linked;
	(void)bloc;
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
