/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:56:01 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/25 17:10:30 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	change_mod(t_move *move, size_t i)
{
	if (move[i].mod == mod_reverse)
		move[i].mod = mod_null;
	else if (move[i].mod == mod_null)
		move[i].mod = mod_reverse;
}

void	fill_move(t_move *src, t_move *tmp, size_t nb_move)
{
	size_t	i;

	i = -1;
	while (++i < nb_move)
		src[i] = tmp[i];
}

void	find_inverted_res(t_list src)
{
	size_t	i;
	t_move	tmp[src.nb_move];

	i = -1;
	while (++i < src.nb_move)
	{
		tmp[i] = src.move[src.nb_move - i - 1];
		change_mod(tmp, i);
	}
	fill_move(src.move, tmp, src.nb_move);
}

bool	is_valid(t_color c[3], bool need)
{
	size_t	i;
	bool	ret;

	i = -1;
	ret = false;
	while (++i < 8)
	{
		if (c[0] == VALID_PATTERN(i)[0] &&
			c[1] == VALID_PATTERN(i)[1] &&
			c[2] == VALID_PATTERN(i)[2])
			ret = true;
	}
	if ((ret && need) || (!ret && !need))
		return (true);
	return (false);
}
