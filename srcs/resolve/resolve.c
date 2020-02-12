/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:04:09 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/24 18:58:06 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		resolve(char ***cube)
{
	t_color		color[3];

	color[0] = color_red;
	color[1] = color_yellow;
	color[2] = color_blue;
	two_two_bloc(cube, color);

	printf("DONE.\n");
	(void)cube;
}
