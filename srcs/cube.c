/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:16:38 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/12 20:26:38 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

char	***init_cube(void)
{
	int		i;
	int		j;
	char	***ret;

	ret = NULL;
	if (!(ret = (char***)malloc(sizeof(char**) * 8)))
		error(-1, ERR_MALLOC, "init_cube(), first");
	ret[7] = NULL;
	if (!(ret[6] = (char**)malloc(sizeof(char*) * (18 + 1))))
		error(-1, ERR_MALLOC, "init_cube(), second");
	ret[6][18] = NULL;
	i = -1;
	j = 0;
	while (++i < 18)
	{
		ret[6][i] = ft_strnew(3);
		ret[6][i][0] = STR_INITIALS_SIDE[j];
		ret[6][i][1] = STR_INITIALS_SIDE[j];
		ret[6][i][2] = STR_INITIALS_SIDE[j];
		if (!(i % 3))
			ret[j] = &(ret[6][i]);
		else if (!((i + 1) % 3) && j < 5)
			j++;
	}
	return (ret);
}

void	erase_cube(char ***cube)
{
	ft_memdel(((void*)cube[6]));
	ft_memdel((void*)cube);
}
