/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:26 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/08 16:53:48 by rlecart          ###   ########.fr       */
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
	// if (!(ret[6] = (char**)malloc(sizeof(char*) * ((3 * 6) + 1))))
	// 	error(-2);
	//malloc 6 *  3 *  3
	//
	ret[6][3 * 6] = NULL;

	i = -1;
	//while i < 6
	//	&ret[i] = &ret[6] + (i * 9) 

	while (++i < (3 * 6))
	{
		if (!(ret[6][i] = ft_strdup("000")))
			error(-3);
		if (i % 3)
			ret[i] = ret[6];
	}
	//display(ret, FULL, NULL);
	return (ret);
}
