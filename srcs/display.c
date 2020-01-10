/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:15:53 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/09 20:22:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	init_colors(char col[31]) // Probleme de concat des couleurs
{
	ft_strcat(col, C_BRED);
	ft_strcat(col, C_BYELLOW);
	ft_strcat(col, C_BBLUE);
	ft_strcat(col, C_BCYAN);
	ft_strcat(col, C_BWHITE);
	ft_strcat(col, C_BGREEN);
	ft_strcat(col, C_RESET);
	col[30] = '\0';
	int tmp;

	tmp = ft_strlen(C_BRED);
	ft_putnstr(&col[0 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[1 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[2 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[3 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[4 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[5 * 6], tmp);
	ft_putstr("bonjour");
	sleep(1);
	ft_putnstr(&col[6 * 6], tmp);
	ft_putstr("bonjour");
	while (1);
}

void	putchar_color(char c, char *color)
{
	int		i;
	int		len;

	(void)c;
	i = 0;
	len = ft_strlen(C_BRED);
	write(1, color, len);
	ft_putchar(c);
	//ft_putchar(' ');
	//ft_putstr(str);
	ft_putstr(C_RESET);
	//printf("%d\n", colors);
	//printf("c = %c | %p original | %ld resultat\n", str[i], col, (ft_strchr(col, str[i]) - col));
	//sleep(1);
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
	int		tmp;
	char	col[31];

	i = 0;
	cel = (int[12]){7, 4, 7, 7, 3, 7, 5, 1, 2, 7, 6, 7};
	init_colors(col);
	tmp = ft_strlen(C_BRED);
	ft_putnstr(&col[0 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[1 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[2 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[3 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[4 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[5 * 4], tmp);
	ft_putstr("bonjour");
	ft_putnstr(&col[6 * 4], tmp);
	ft_putstr("bonjour");
	while (1);
	while (i < 12)
	{
		j = -1;
		while (++j < 9)
		{
			k = -1;
			while (++k < 3)
			{
				tmp = (cel[i + (j % 3)] * 3) - 2;
				if (face == -1 && cel[i + (j % 3)] == 7)
					ft_putstr("a");
				else
					putchar_color(tab[6][tmp][k], &col[find_col(tmp, "abcdef\0") * ft_strlen(C_BRED)]);
			}
			if (j % 3 == 2)
				ft_putchar('\n');
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
//
//void	ft_display(char ***tab, int face, int cel[12])
//{
//
//}
