/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:41:21 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/06 19:52:40 by rlecart          ###   ########.fr       */
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

void		print_env(void)
{
	size_t	i;
	size_t	j;
	t_env	*h;

	i = 0;
	j = 0;
	h = &env;
	while (i < env.nb_move)
	{
		if (!(i % BUFF_MOVE) && i && !(j = 0))
			h = h->next;
		ft_putchar(STRING_INITIALS_SIDE[h->move_all[j].side]);
		ft_putchar(STRING_INITIALS_MOD[h->move_all[j].mod]);
		if (i + 1 != env.nb_move)
			ft_putchar(' ');
		i++;
		j++;
	}
	ft_putchar('\n');
}

void		print_ins(t_move *tab, size_t nb)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < nb)
	{
		ft_putchar(STRING_INITIALS_SIDE[tab[i].side]);
		ft_putchar(STRING_INITIALS_MOD[tab[i].mod]);
		if (i + 1 != nb)
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
