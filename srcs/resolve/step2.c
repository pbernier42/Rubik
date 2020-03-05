/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:13:53 by rlecart           #+#    #+#             */
/*   Updated: 2020/03/05 20:00:03 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	orient_corner(char ***cube, t_color new[3])
{
	t_sticker	corner[3];

	(void)cube;
	(void)new;
	(void)corner;
}

void	find_square(char ***cube, t_color c[3], t_color new[3], int rot[2])
{
	int			i;
	int			j;
	t_binary	binary;

	i = -1;
	while (++i < side_null)
	{
		binary = tbin_conv_char(cube[i], i);
		if ((j = index_tab_tbin(binary, (t_binary[4]){0b110110000, 0b000110110, 0b000011011, 0b011011000}, 4)) != -1)
		{
			// H/V
			// F 00 10 20 30
			// R 01 11 21 31
			// U 00 01 20 
			printf("j = %d\n", j);
		}
			//return (copy_tab_tmove(move, TAB_TMOVE_ONE(((t_move){corner[I].side, mod_null})), 1));
		bin(binary);
	}
	(void)cube;
	(void)rot;
	(void)c;
	(void)new;
}

void	step_two(char ***cube, t_color c[3])
{
	int			rot[2];
	t_color		new[3] = {c[1], color_red, c[2]};

	//find_square(cube, c, new, rot);
	//place_corner(cube, new);
	//bin(tbin_conv_tstickers(new), true);
	orient_corner(cube, new);
	(void)rot;
}
