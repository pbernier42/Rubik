/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:04:09 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/27 18:05:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

# define TAB_SHORTS_COLOR_ORDER		((short[6][3]){{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}})
# define SHORT_COLOR_ORDER(i, j)	(TAB_SHORTS_COLOR_ORDER[i])[j]
# define TAB_TSIDE_REFINE(i, j)		((t_side[3]){\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 0)),\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 1)),\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 2))})

# define TLIST_RESULT				list[0]
# define TLIST_SAVE					list[1]


t_list		find_best_resolve(char ***cube, t_list shuffle)
{
	short		i[2];
	t_color		color[3];
	t_list		list[2];

	I = -1;
	TLIST_RESULT.nb_move = 0;
	TLIST_RESULT.move = NULL;
	TLIST_SAVE = TLIST_RESULT;

	read_tab_tmove(cube, shuffle);
	while (++I < 8)
	{
		J = -1;
		while (++J < 6)
		{
			copy_tab_tside((t_side*)color, TAB_TSIDE_REFINE(I, J), 3);
			resolve(cube, color);
			//TINST_RESULT = tab_tmove_conv_env(TINST_RESULT, ???);
			//if (TINST_SAVE.nb_move < TINST_RESULT.nb_move)
			//	TINST_SAVE = TINST_RESULT;
			//reset cube
		}
		printf("\n");
	}
	return (TLIST_SAVE);
}

void		resolve(char ***cube, t_color color[3])
{
	//printf("[%s][%s][%s]\n", STR_SIDE(color[0]), STR_SIDE(color[1]), STR_SIDE(color[2]));

	two_two_bloc(cube, color);
	//two_two_three_bloc(cube, color);
}
