/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:26 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/15 20:28:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

char	***init_tab(void)
{
	int		i;
	int		j;
	char	***ret;

	ret = NULL;
	if (!(ret = (char***)malloc(sizeof(char**) * 8)))
		error(-1);
	ret[7] = NULL;
	if (!(ret[6] = (char**)malloc(sizeof(char*) * ((6 * 3) + 1))))
		error(-2);
	ret[6][6 * 3] = NULL;
	i = -1;
	j = 0;
	while (++i < 6 * 3)
	{
		ret[6][i] = ft_strnew(3);
		ret[6][i][0] = INITIALS_SIDE[j];
		ret[6][i][1] = INITIALS_SIDE[j];
		ret[6][i][2] = INITIALS_SIDE[j];
		if (!(i % 3))
		{
			ret[j] = &ret[6][i];
			j++;
		}
		//if ((i % 3) == 2)
		//	ret[j++] = &ret[6][i - 2];
	}
	ft_putstr(ret[0][0]);
	ft_putstr(ret[0][1]);
	ft_putstr(ret[0][2]);
	ft_putchar('\n');
	ft_putstr(ret[1][0]);
	ft_putstr(ret[1][1]);
	ft_putstr(ret[1][2]);
	ft_putchar('\n');
	ft_putstr(ret[2][0]);
	ft_putstr(ret[2][1]);
	ft_putstr(ret[2][2]);
	ft_putchar('\n');
	ft_putstr(ret[3][0]);
	ft_putstr(ret[3][1]);
	ft_putstr(ret[3][2]);
	sleep(1);

//	while (++i < 6)
//	{
//		if (!(ret[i] = (char**)malloc(sizeof(char*) * (3 + 1))))
//			error(-2);
//		ret[i][4] = NULL;
//		j = -1;
//		while (++j < 3)
//		{
//			if (!(ret[i][j] = ft_strnew(3)))
//				error(-3);
//		}
//	}

	// printf("[%c][%c][%c]\n", ret[0][0][0], ret[0][0][1], ret[0][0][2]);
	// printf("[%c][%c][%c]\n", ret[0][1][0], ret[0][1][1], ret[0][1][2]);
	// printf("[%c][%c][%c]\n\n", ret[0][2][0], ret[0][2][1], ret[0][2][2]);
	return (ret);
}
