/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:49:33 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/23 20:41:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>



size_t	skip_space(size_t len, char *string)
{
	while (string && SHORT_IS_SPACE(string[len]) != -1)
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
