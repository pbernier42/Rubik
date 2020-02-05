/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:26 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/16 17:53:42 by rlecart          ###   ########.fr       */
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
		error(-1, "Malloc");
	ret[7] = NULL;
	if (!(ret[6] = (char**)malloc(sizeof(char*) * (18 + 1))))
		error(-2, "Malloc");
	ret[6][18] = NULL;
	i = -1;
	j = 0;
	while (++i < 18)
	{
		ret[6][i] = ft_strnew(3);
		ret[6][i][0] = STRING_INITIALS_SIDE[j];
		ret[6][i][1] = STRING_INITIALS_SIDE[j];
		ret[6][i][2] = STRING_INITIALS_SIDE[j];
		if (!(i % 3))
			ret[j] = &(ret[6][i]);
		else if (!((i + 1) % 3) && j < 5)
			j++;
	}
	return (ret);
}
