/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:15:53 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/13 17:45:38 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	init_colors(char col[31])
{
	ft_bzero(col, 31);
	ft_strcat(col, C_BRED);
	ft_strcat(col, C_BYELLOW);
	ft_strcat(col, C_BBLUE);
	ft_strcat(col, C_BCYAN);
	ft_strcat(col, C_BWHITE);
	ft_strcat(col, C_BGREEN);
}

void	putchar_color(char c, char *color, int len)
{
	write(1, color, len);
	(void)c;
	if (!WITH_LETTER)
		ft_putchar(c);
	else
		ft_putchar(' ');
	ft_putstr(C_RESET);
}

int		find_col(char c, char col[7])
{
	return (ft_strchr(col, c) - col);
}

void	display(char ***tab, int face, int cel[12])
{
	int		i;
	int		j;
	int		k;
	int		tmp[3];
	char	col[31];

	i = 0;
	cel = (int[12]){7, 4, 7, 7, 3, 7, 5, 1, 2, 7, 6, 7};
	ft_bzero(col, 7);
	init_colors(col);
	tmp[1] = ft_strlen(C_BRED);
	while (i < 12)
	{
		j = -1;
		while (++j < 9)
		{
			k = -1;
			while (++k < 3)
			{
				tmp[0] = cel[i + (j % 3)]; // calcul pour iterer sur cel (123,123,123,456,456,456,789, etc)
				if (tmp[0] != 7)
					tmp[2] = tab[6][(tmp[0] - 1) * 3][k]; // calcul pour choper le caractere exact
				if (!face && tmp[0] == 7)
					ft_putchar(' ');
				else if (!face || (face && tmp[0] == face))
					putchar_color(tmp[2], col + (tmp[1] *
						find_col(tmp[2], INITIALS_SIDE)), tmp[1]);
			}
			if ((!face && j % 3 == 2) || (face && face == tmp[0]))
				ft_putchar('\n');
		}
		i += 3;
	}
}
