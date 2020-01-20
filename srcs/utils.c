/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:49:33 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/20 18:13:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

short	in_side_tab(t_side side, t_side *tab_side, short size_tab)
{
	short	len_tab;

	len_tab = -1;
	while (tab_side && ++len_tab < size_tab)
		if (side == tab_side[len_tab])
			return (len_tab);
	return (-1);
}

bool	in_string(char c, char *string)
{
	short	len;

	len = 0;
	while (string && string[len] && c != string[len])
		++len;
	return ((string[len]));
}

size_t	skip_space(size_t len, char *string)
{
	while (string && IS_SPACE(string[len]))
		++len;
	return (len);
}

void 	ungly_display(char ***cube)
{
	printf("          [%c][%c][%c]    \n", cube[side_back][0][0], cube[side_back][0][1], cube[side_back][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_back][1][0], cube[side_back][1][1], cube[side_back][1][2]);
	printf("          [%c][%c][%c]    \n\n", cube[side_back][2][0], cube[side_back][2][1], cube[side_back][2][2]);
	printf("          [%c][%c][%c]    \n", cube[side_up][0][0], cube[side_up][0][1], cube[side_up][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_up][1][0], cube[side_up][1][1], cube[side_up][1][2]);
	printf("          [%c][%c][%c]    \n\n", cube[side_up][2][0], cube[side_up][2][1], cube[side_up][2][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n", cube[side_left][0][0], cube[side_left][0][1], cube[side_left][0][2], cube[side_front][0][0], cube[side_front][0][1], cube[side_front][0][2], cube[side_right][0][0], cube[side_right][0][1], cube[side_right][0][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n", cube[side_left][1][0], cube[side_left][1][1], cube[side_left][1][2], cube[side_front][1][0], cube[side_front][1][1], cube[side_front][1][2], cube[side_right][1][0], cube[side_right][1][1], cube[side_right][1][2]);
	printf("[%c][%c][%c] [%c][%c][%c] [%c][%c][%c]\n\n", cube[side_left][2][0], cube[side_left][2][1], cube[side_left][2][2], cube[side_front][2][0], cube[side_front][2][1], cube[side_front][2][2], cube[side_right][2][0], cube[side_right][2][1], cube[side_right][2][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][0][0], cube[side_down][0][1], cube[side_down][0][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][1][0], cube[side_down][1][1], cube[side_down][1][2]);
	printf("          [%c][%c][%c]    \n", cube[side_down][2][0], cube[side_down][2][1], cube[side_down][2][2]);
	// printf("\n");
	// printf("          [%c][%c][%c]    \n", cube[side_null][0][0], cube[side_null][0][1], cube[side_null][0][2]);
	// printf("          [%c][%c][%c]    \n", cube[side_null][1][0], cube[side_null][1][1], cube[side_null][1][2]);
	// printf("          [%c][%c][%c]    \n", cube[side_null][2][0], cube[side_null][2][1], cube[side_null][2][2]);
}
