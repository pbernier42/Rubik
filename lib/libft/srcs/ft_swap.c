/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:10:31 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:45:44 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *tab, size_t len)
{
	int		tmp;
	char	*tab2;
	size_t	i;

	i = -1;
	tab2 = (char*)tab;
	while (++i < len)
	{
		tmp = tab2[i];
		tab2[i] = tab2[len - 1 - i];
		tab2[len - 1 - i] = tmp;
	}
}
