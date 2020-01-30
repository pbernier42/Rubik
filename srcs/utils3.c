/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:11:52 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/27 22:30:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	fill_enum(int tab[NB_ITER], int type, int nb, ...)
{
	int		i;
	va_list	ap;

	i = -1;
	ft_memset(tab, type, NB_ITER);
	va_start(ap, nb);
	while (++i < nb)
		tab[i] = va_arg(ap, int);
	va_end(ap);
}

void	*better_memset(void *s, int c, size_t len, size_t byte)
{
	while (len--)
	{
		((char*)s)[len * byte] = c;
	}
	return (s);
}
