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







# define ROTATE_AROUND(around_side, nb)		((around_side + nb) % 3)
# define ROTATE_DNUORA(around_side, nb)		((around_side - nb) % 3)

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

	if ((stob((t_side[1]){action.side}, 1, BIN_CORNER_LESS | BIN_EDGE)))
	{
		action.binary = stob((t_side[1]){action.side}, 1, BIN_CORNER | BIN_EDGE);
		RESET_MOVE(move);
		if ((I = bin_comp_and_tab(action.binary, (t_binary[4]){
			0b011000000, 0b100100000, 0b000000110, 0b000001001}) != -1)
		{
			// FRONT"F R U B L D"
			// RIGHT"R U B L D F"
			// {"UD2", "FRDL"}
			// "UD2R2DRD"
			// f(REVERSE_EDGE)
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
