/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:26 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/08 17:51:16 by rlecart          ###   ########.fr       */
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
	ret[8] = NULL;
	i = -1;
	while (++i < 6)
	{
		if (!(ret[i] = (char**)malloc(sizeof(char*) * (3 + 1))))
			error(-2);
		ret[i][4] = NULL;
		j = -1;
		while (++j < 3)
		{
			if (!(ret[i][j] = ft_strnew(3)))
				error(-3);
		}
	}
	return (ret);
}
