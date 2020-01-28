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
	short	len_tab;

	len_tab = -1;
	while (tab_side && ++len_tab < size_tab)
		if (side == tab_side[len_tab])
			return (len_tab);
	return (-1);
}

short	index_tab_around(t_binary bin_cube)
{
	short 		i;
	t_binary	tmp;

	i = -1;
	tmp = 0;
	while (++i < 8)
	{
		tmp = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[i]);
		if (tmp == (bin_cube & tmp))
			return (i);
	}
	return (-1);
}
