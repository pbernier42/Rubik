/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:53:05 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 17:53:07 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>

void		tab_tbin_find_edge(t_binary edge_linked[3], t_sticker corner[3])
{
	t_sticker		sticker[2];

	sticker[0] = tsticker_find_edge((t_sticker[2]){corner[0], corner[1]});
	sticker[1] = tsticker_find_edge((t_sticker[2]){corner[1], corner[0]});
	edge_linked[0] = tbin_conv_tstickers((t_sticker[3]){sticker[0], sticker[1], TSTICKER_NULL});
	sticker[0] = tsticker_find_edge((t_sticker[2]){corner[1], corner[2]});
	sticker[1] = tsticker_find_edge((t_sticker[2]){corner[2], corner[1]});
	edge_linked[1] = tbin_conv_tstickers((t_sticker[3]){sticker[0], sticker[1], TSTICKER_NULL});
	sticker[0] = tsticker_find_edge((t_sticker[2]){corner[2], corner[0]});
	sticker[1] = tsticker_find_edge((t_sticker[2]){corner[0], corner[2]});
	edge_linked[2] = tbin_conv_tstickers((t_sticker[3]){sticker[0], sticker[1], TSTICKER_NULL});
}

t_sticker	tsticker_find_edge(t_sticker edge[2])
{
	t_line		line;
	bool		found;
	short		i;

	i = -1;
	found = false;
	while (!found)
	{
		line = TAB_TLINE_AROUND(edge[0].side)[++i];
		if (line.side == edge[1].side)
			found = true;
	}
	return ((t_sticker){line.side, {line.coo[1][0], line.coo[1][1]}});
}

t_side		tside_find_biggest_weight(t_binary binary)
{
	t_side		side[2];
	short		i[0];
	bool		same;

	TSIDE_SIDE = side_front;
	TSIDE_SAVE = side_null;
	NB_BYTE = -1;
	same = false;
	while (TSIDE_SIDE != side_null)
	{
		I = nb_byte_tbinary(TBIN_CONV_TSIDE(TSIDE_SIDE, binary), 9);
		if (I > NB_BYTE)
		{
			same = false;
			NB_BYTE = I;
			TSIDE_SAVE = TSIDE_SIDE;
		}
		else if (I == NB_BYTE)
			same = true;
		++TSIDE_SIDE;
	}
	return (same ? side_null : TSIDE_SAVE);
}
