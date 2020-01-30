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

// t_action	commun_side(t_binary corner_edge)
// {
// 	t_side		side;
// 	bool		found;
// 	short		i;
// 	t_binary	ret;
//
// 	side = side_front;
// 	while (side != side_null)
// 	{
// 		found = false;
// 		i = -1;
// 		ret = corner_edge;
// 		while (++i < 9)
// 		{
// 			if ((corner_edge % 2))
// 			{
// 				if (found)
// 					return ((t_action){(5 - side), (ret & 511)});
// 				found = true;
// 			}
// 			corner_edge = corner_edge >> 1;
// 		}
// 		++side;
// 	}
// 	return ((t_action){side, 0});
// }





// # define K						i[2]
//
// void	condition(t_move move[NB_ITER], t_binary binary, t_condition *conditions)
// {
// 	short	i[2];
//
// 	I = -1;
// 	while ((conditions) && (conditions[++I].side != side_null))
// 	{
// 		if (conditions[I].binary == (binary & conditions[I].binary))
// 		{
// 			fill_move(move[J], conditions[I]);
// 			return ;
// 		}
// 	}
// }

// # define T_MOVE_NULL			{side_null, mod_null}
// # define PAD_FIVE_MOVE			T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL, T_MOVE_NULL
// # define RESET_MOVE(move)    	fill_move(move, t_move[NB_ITER]({PAD_FIVE_MOVE}))
// # define PAD_FOUR_SIDE			side_null, side_null, side_null, side_null
// # define PAD_FOUR_MOD			mod_null, mod_null, mod_null, mod_null

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i[3];
	bool		found;
	t_binary	edge[2][3];
	t_binary	binary[5];
	t_action	action;
	t_move		move[NB_ITER];

	// action.side = side_front;
	// while (!found && action.side != side_null)
	// {
	// 	if (stob((t_side[1]){action.side}, 1, BIN_CORNER ^ BIN_CORNER_LESS))
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
	// edge_corner(EDGE_NEAR, TAB_BIN_CORNER[I]);
	// BIN_CUBE = bloc_binary(cube, (t_side[3]){(t_side)corner[0], (t_side)corner[1], side_null});
	//BIN_CORNER_LESS = (BIN_CUBE & BIN_CORNER);

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
