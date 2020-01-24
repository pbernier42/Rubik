/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:11:52 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/24 20:27:46 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

size_t	byte_counter(t_binary binary, size_t nb)
{
	size_t		i;
	size_t		count;
	t_binary	tmp;

	i = -1;
	count = 0;
	tmp = 1;
	while (++i < nb)
	{
		if (binary & tmp)
			count++;
		binary = binary >> 1;
	}
	return (count);
}
