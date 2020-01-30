/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:29:24 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 19:29:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>

short	index_tab_tside(t_side side, t_side *tab_side, short size_tab)
{
	short	i;

	i = -1;
	while (tab_side && ++i < size_tab)
		if (side == tab_side[i])
			return (i);
	return (-1);
}

short	index_tab_tstickers(t_binary bin_cube, t_sticker (*tab_stickers)[3],
			short size_tab)
{
	short 		i;
	t_binary	tmp;

	i = -1;
	tmp = 0;
	while (++i < size_tab)
	{
		tmp = tbin_conv_tstickers(tab_stickers[i]);
		if (tmp == (bin_cube & tmp))
			return (i);
	}
	return (-1);
}

short	index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab)
{
	short	i;

	i = -1;
	while (tab_binary && ++i < size_tab)
		if (!(binary ^ tab_binary[i]))
			return (i);
	return (-1);
}

short	nb_byte_tbinary(t_binary binary, short spectrum)
{
	short		i[2];

	I = -1;
	NB_BYTE = 0;
	while (++I < spectrum)
	{
		if (binary & 1)
			NB_BYTE++;
		binary = binary >> 1;
	}
	return (NB_BYTE);
}

short	copy_tab_tmove(t_move dest[NB_MOVE_MAX], t_move from[NB_MOVE_MAX])
{
	short	i[2];

	//printf("?\n");
	I = -1;
	NB_MOVE = 0;
	while (++I < NB_MOVE_MAX)
	{
		if (from[I].side != side_null)
			NB_MOVE = (I + 1);
		dest[I].side = from[I].side;
		dest[I].mod = from[I].mod;
	}
	return (NB_MOVE);
}

short	copy_tab_tside(t_side dest[side_null], t_side from[side_null])
{
	short	i[2];

	I = -1;
	NB_SIDE = 0;
	while (++I < side_null)
	{
		if (from[I] != side_null)
			NB_SIDE = (I + 1);
		dest[I] = from[I];
	}
	return (NB_SIDE);
}
