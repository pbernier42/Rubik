/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:22:17 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 18:22:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>

t_binary	tbin_conv_tstickers(t_sticker bloc[3])
{
	t_binary	binary;
	t_side		side;
	short		i;

	side = side_front;
	binary = 0;
	while (side != side_null)
	{
		if ((i = index_tab_tside(side,
			((t_side[3]){bloc[0].side, bloc[1].side, bloc[2].side}), 3)) != -1)
		{
			binary = binary << (((bloc[i].COO_Y * 3) + bloc[i].COO_X) + 1);
		 	binary += 1;
		 	binary = binary << (9 - (((bloc[i].COO_Y * 3) + bloc[i].COO_X) + 1));
		}
		else
			binary = binary << 9;
		++side;
	}
	return (binary);
};

t_binary	tbin_conv_tsides(char ***cube, t_side side[3])
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
			binary += tbin_conv_char(cube[side_len], side[side_select]);
		++side_len;
	}
	return (binary);
}


t_binary	tbin_conv_char(char **cube_side, t_side side)
{
	short		coo[2];
	t_binary	binary;

	COO_Y = -1;
	binary = 0;
	while (side != side_null && ++COO_Y != 3)
	{
		COO_X = -1;
		while (++COO_X != 3)
		{
			binary = binary << 1;
			if (cube_side[COO_Y][COO_X] == INITIALS_SIDE[side])
				++binary;
		}
	}
	return (binary);
}
