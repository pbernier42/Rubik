/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:16:38 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/21 18:02:49 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

char	***init_layer(char *str)
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
		ret[6][i][0] = str[j];
		ret[6][i][1] = str[j];
		ret[6][i][2] = str[j];
		if (!(i % 3))
			ret[j] = &(ret[6][i]);
		else if (!((i + 1) % 3) && j < 5)
			j++;
	}
	return (ret);
}

void	erase_layer(char ***layer)
{
	ft_memdel(((void*)layer[6]));
	ft_memdel((void*)layer);
}

void	reset_layer(char ***layer, char *str)
{
	int		i;

	i = -1;
	while (++i < 18)
	{
		layer[6][i][0] = str[i / 3];
		layer[6][i][1] = str[i / 3];
		layer[6][i][2] = str[i / 3];
	}
}

void	fill_side(char **side, char c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			side[i][j] = c;
	}
}

void	highlight_turn(char ***layer, t_side side, t_line line[4])
{
	int		i;
	short	x[3];
	short	y[3];
	t_side	s;

	i = -1;
	reset_layer(layer, STR_INITIALS_LAYER);
	fill_side(layer[side], '2');
	while (++i < 4)
	{
		s = line[i].side;
		y[0] = line[i].coo[0][0];
		x[0] = line[i].coo[0][1];
		y[1] = line[i].coo[1][0];
		x[1] = line[i].coo[1][1];
		y[2] = line[i].coo[2][0];
		x[2] = line[i].coo[2][1];
		layer[s][y[0]][x[0]] = '1';
		layer[s][y[1]][x[1]] = '1';
		layer[s][y[2]][x[2]] = '1';
	}
}
