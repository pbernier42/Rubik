/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:41:21 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/27 21:15:46 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

int			mod_range(int a, int b, int n)
{
	if (a > b)
		return ((a - b) % n);
	else
		return ((b - a) % n);
}

int			pdebug(void)
{
	ft_putendl("a");
	return (1);
}

void		print_ins(t_move *tab, size_t nb)
{
	size_t	i;

	i = -1;
	while (++i < nb)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = { ");
		ft_putchar(INITIALS_SIDE[tab[i].side]);
		ft_putstr(", ");
		ft_putchar(INITIALS_MOD[tab[i].mod]);
		ft_putstr(" }\n");
	}
}

t_binary	isolate(t_side side, t_binary binary)
{
	t_binary	ret;

	ret = binary >> (9 * (5 - side));
	return (ret & 511);
}

t_binary	stob(t_side *side, size_t nb_side, t_binary binary)
{
	size_t		i;
	t_binary	ret;

	i = -1;
	ret = 0;
	while (++i < nb_side)
	{
		ret = ret << 9;
		ret += isolate(side[i], binary);
	}
	return (ret);
}
