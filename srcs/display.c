/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:15:53 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/08 17:05:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	display(char ***tab, bool sw, int cel[12])
{
	int		i;
	int		j;

	i = -1;
	cel = (int[12]){7, 4, 7, 7, 3, 7, 5, 1, 2, 7, 6, 7};
	(void)sw;
	while (++i < 12)
	{
		j = -1;
		while (++j < 3)
		{
			if (cel[i] == 7)
				ft_putstr("xxx");
			else
				ft_putstr("   ");
				//ft_putstr(tab[6][cel[i] * 3 + j]);
			ft_putchar('\n');
		}
		if (i % 3)
			ft_putchar('\n');
	}
	(void)tab;
}
