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

void	fill_side_bin(t_side tab[6], t_binary binary)
{
	int			i;
	int			j;
	t_binary	tmp;

	i = -1;
	j = 0;
	better_memset(tab, side_null, 6, sizeof(t_side)); // il faut memset mais vu que c'est 4 octets un t_side alors que memset fait 1 octet par octet
	while (1);
	while (++i < 6)
	{
		tmp = isolate(i, binary);
		if ((byte_counter(tmp, 9)))
			tab[j++] = i;
	}
	print_ins((t_move[3]){{tab[0], 2}, {tab[1], 2}, {tab[2], 2}}, 3);
	print_ins((t_move[3]){{tab[3], 2}, {tab[4], 2}, {tab[5], 2}}, 3);
	ft_putendl("");
	while (1);
}
