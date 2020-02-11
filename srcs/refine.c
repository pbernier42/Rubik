/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:51:47 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/11 17:37:39 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_move	stash_ins(t_move *tmp, size_t *count, size_t *j)
{
	size_t	ctmp;
	t_move	ret;

	ctmp = *count % 4;
	ret.side = tmp->side;
	if (ctmp == 0)
	{
		ret.side = side_null;
		ret.mod = mod_null;
	}
	else if (ctmp == 1)
		ret.mod = mod_null;
	else if (ctmp == 2)
		ret.mod = mod_twice;
	else
		ret.mod = mod_reverse;
	if (ctmp != 0)
		(*j)++;
	tmp->side = side_null;
	tmp->mod = mod_null;
	*count = 0;
	return (ret);
}

size_t	refine(t_move *tab, size_t nb)
{
	size_t	i;
	size_t	j;
	int		sw;
	size_t	count[2];
	t_move	tmp[2];
	t_move	ret[nb];

	i = 0;
	j = 0;
	sw = 0;
	tmp[0].side = side_null;
	tmp[1].side = side_null;
	count[0] = 0;
	count[1] = 0;
	while (tab && i <= nb)
	{
		if (i > 0)
		{
			if (i < nb && !(mod_range(tmp[sw].side, tab[i].side, 3)) && tab[i].side != tmp[sw].side)
				sw = (sw + 1) % 2;
			else if ((i < nb && tab[i].side != tmp[sw].side) || i == nb)
			{
				ret[j] = stash_ins(&tmp[sw], &count[sw], &j);
				if (tmp[(sw + 1) % 2].side != side_null)
				{
					sw = (sw + 1) % 2;
					ret[j] = stash_ins(&tmp[sw], &count[sw], &j);
				}
			}
			if (i == nb)
				break ;
		}
		if (tmp[sw].side == side_null)
			tmp[sw] = tab[i];
		if (tab[i].mod == mod_null)
			count[sw] += 1;
		else
			count[sw] += tab[i].mod + 2;
		i++;
	}
	//stash_ret(ret, );
	print_ins(ret, j);
	return (j);
}
