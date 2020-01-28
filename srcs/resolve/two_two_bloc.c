/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_two_bloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:28:26 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 17:28:27 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void		two_two_bloc(char ***cube, t_color corner[3])
{
	short		i;
	t_binary	binary[2];
	t_binary	edge[2][3];

	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	i = index_tab_around(BIN_CUBE);
	BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[i]);
	BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner));
	tbin_tab_find_edge(BIN_TAB_EDGE_OPPOSITE, TAB_TSTICKERS_CORNER[(i + 4) % 8]);

	bin(BIN_TAB_EDGE_OPPOSITE[0]);
	bin(BIN_TAB_EDGE_OPPOSITE[1]);
	bin(BIN_TAB_EDGE_OPPOSITE[2]);

	// TAB_BIN
	// et non pas
	// BIN_TAB
	//tbin_found_corner(t_binary bin_cube)
	(void)cube;
	(void)corner;
	(void)edge;
}
