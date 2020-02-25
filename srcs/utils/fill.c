/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:58:56 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/19 17:56:57 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

short	copy_tab_tmove(t_move *dest, t_move *from, short size_tab)
{
	short	i[2];

	I = -1;
	NB_MOVE = 0;
	while (++I < size_tab)
	{
		if (from[I].side != side_null)
			NB_MOVE = (I + 1);
		copy_tmove(&dest[I], from[I].side, from[I].mod);
	}
	return (NB_MOVE);
}

short	copy_tab_tside(t_side *dest, t_side *from, short size_tab)
{
	short	i[2];

	I = -1;
	NB_SIDE = 0;
	while (++I < size_tab)
	{
		if (from[I] != side_null)
			NB_SIDE = (I + 1);
		dest[I] = from[I];
	}
	return (NB_SIDE);
}

void	copy_tmove(t_move *dest, t_side side, t_mod mod)
{
	(*dest).side = side;
	(*dest).mod = mod;
}
