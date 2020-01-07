/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:26 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/07 19:24:03 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

char	**create_tab(int y, int x)
{
	char	**ret;

	ret = NULL;
	if (x > 0 && y > 0)
	{
		if (!(ret = (char**)malloc(sizeof(char*) * y)))
			error(-1);
		ret[y] = NULL;
		while (--y >= 0)
		{
			if (!(ret[y] = (char*)malloc(sizeof(char) * x)))
				error(-1);

		}
	}
	return (ret);
}

char	***init_tab(void)
{
	int		i;
	char	***ret;

	ret = NULL;
	if (!(ret = (char***)malloc(sizeof(char**) * 8)))
		error(-1);
	if (!(ret[6] = (char**)malloc(sizeof(char*) * ((3 * 6) + 1))))
		error(-2);
	ret[6][3 * 6] = NULL;
	i = -1;
	while (++i < (3 * 6))
	{
		if (!(ret[6][i] = ft_strdup(3)))
			error(-3);
	}
	return (ret);
}
