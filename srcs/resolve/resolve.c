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

# define TAB_SHORTS_COLOR_ORDER		((short[6][3]){{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}})
# define SHORT_COLOR_ORDER(i, j)	(TAB_SHORTS_COLOR_ORDER[i])[j]
# define TAB_TSIDE_REFINE(i, j)		((t_side[3]){\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 0)),\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 1)),\
									TSIDE_CORNER(i, SHORT_COLOR_ORDER(j, 2))})

# define TMOVE_RESULT				move[0]
# define TMOVE_SAVE					move[1]


t_move		*find_best_resolve(char ***cube, size_t *arg_number)
{
	short		i[2];
	t_color		color[3];
	//t_move		*move[2] = {NULL, NULL};

	I = -1;
	while (++I < 8)
	{

		J = -1;
		while (++J < 6)
		{
			copy_tab_tside((t_side*)color, TAB_TSIDE_REFINE(I, J), 3);
			resolve(cube, color); // segfault a cause du '-1' de I envoye dans two_two_bloc()
			//tab_tmove_conv_env(TMOVE_RESULT, env.nb_move, );
		}
	}
	printf("DONE.\n");
	*arg_number = 0;
	return (NULL);
}

void		resolve(char ***cube, t_color color[3])
{
	printf("[%s][%s][%s]\n", STR_SIDE(color[0]), STR_SIDE(color[1]), STR_SIDE(color[2]));

	two_two_bloc(cube, color);
}
