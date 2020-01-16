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

void		two_two_bloc(char ***cube);
t_binary	bloc_binary(char ***cube, t_side side[3]);
t_binary	side_binary(char **cube_side, t_side side);
t_binary	coor_binary(t_face bloc[3]);

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
	two_two_bloc(cube);


	//bin(coor_binary(tmp));
	//1000000000000000000000001000000000000010000000
	// 1000000000000000000000001000000000000010000000000000000

}
# define TOP_RIGT 0b100 000 000 000 000 000 000 000 100 000 000 000 001 000 000 000 000 000

void		two_two_bloc(char ***cube)
{
	t_binary	binary;

	binary = bloc_binary(cube, (t_side[3]){side_front, side_left, side_up});
	coor_binary((t_face[3])({side_front, {0, 0}});

	// (void)move;
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
