/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:15:53 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/10 20:48:00 by rlecart          ###   ########.fr       */
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
	// ici mettre une condition pour pouvoir avoir un visu avec des lettres (define pour switch)
	ft_putchar(' ');
	ft_putstr(C_RESET);
}
//RGBWOY

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
	//face = 1;
	while (i < 12)
	{
		j = -1;
		while (++j < 9)
		{
			k = -1;
			while (++k < 3)
			{
				if (face == -1)
					tmp[0] = cel[i + (j % 3)]; // calcul pour iterer sur cel (123,123,123,456,456,456,789, etc)
				else
					tmp[0] = face;
				if (tmp[0] != 7)
					tmp[2] = tab[6][(tmp[0] - 1) * 3][k]; // calcul pour choper le caractere exact
				if (face == -1 && tmp[0] == 7)
					ft_putchar(' ');
				else
					putchar_color(tmp[2], col + (tmp[1] *
						find_col(tmp[2], INITIALS_SIDE)), tmp[1]);
			}
			if (j % 3 == 2)
				ft_putchar('\n');


			if (face != -1 && j == 3) // Pour gerer une seule face, mais je sais pas ou le mettre (et comment)
				return ;


		}
		i += 3;
	}
}
//
//void	display_one_face(char **face)
//{
//	int		i;
//	int		j;
//
//	i = -1;
//	while (face[++i])
//	{
//		j = -1;
//		while (face[i][++j])
//		{
//
//		}
//	}
//}
