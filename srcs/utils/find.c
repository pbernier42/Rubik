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

void	tbin_tab_find_edge(t_binary edge_linked[3], t_sticker corner[3])
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
		line = TLINE_TAB_AROUND(edge[0].side)[++i];
		if (line.side == edge[1].side)
			found = true;
	}
	return ((t_sticker){line.side, {line.coo[1][0], line.coo[1][1]}});
}
