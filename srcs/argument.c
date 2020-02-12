/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:02:31 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/12 14:03:01 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>


# define TAB_TPARAM_PARAMBIN				((t_binary[4]){arg_bin_cube, arg_bin_corner, arg_bin_edge, arg_bin_edge})
# define TAB_SHORT_SELECT_SHIFT				((short[4]){0, 4, 8, 12})
# define TBIN_PARAM(argument, select)		(TAB_TPARAM_PARAMBIN[argument] | (select << TAB_SHORT_SELECT_SHIFT[argument]))

void		tbin_update(char ***cube, t_binary binary[6], t_color corner[3],
				t_argument bin_argument)
{

	// if ((bin_argument & arg_bin_cube))
	// {
	//  	BIN_CUBE = tbin_conv_tsides(cube, select);
	// }

	if ((bin_argument & arg_cube_all))
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner));
	if ((bin_argument & arg_cube_two))
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(corner[0], corner[1]));
	if ((bin_argument & arg_cube_one))
		BIN_CUBE = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ONE(corner[0]));

	if ((bin_argument & arg_corner))
		BIN_CORNER = tbin_conv_tstickers(TAB_TSTICKERS_CORNER[INDEX_CORNER(corner)]);
	if ((bin_argument & arg_edge))
		BIN_EDGE = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[INDEX_EDGE(corner[0], corner[1])]);
	if ((bin_argument & arg_edge_prim))
		BIN_EDGE_PRIM = tbin_conv_tstickers(TAB_TSTICKERS_EDGE[INDEX_EDGE(corner[0], corner[2])]);

	if ((bin_argument & arg_corner_less))
		BIN_CORNER_LESS = tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(corner)) & tbin_conv_tstickers(TAB_TSTICKERS_CORNER[INDEX_CORNER(corner)]);

}

// t_binary		tbin_update_individual(char ***cube, t_binary *bin_argument,
// 				t_color corner[3])
// {
// 	t_side	select[3];
// 	short	shift;
//
// 	tab_tside_edit(select, (t_side*)corner, (*bin_argument) << );
// 	return ()
// }

# define TAB_TBIN_SELECTER	((t_binary[3]){0b100, 0b010, 0b001})

void		tab_tside_edit(t_side dest[3], t_side from[3], t_binary selecter)
{
	short	i[2];

	I = -1;
	J = -1;
	while (++I < 3)
		if ((selecter & TAB_TBIN_SELECTER[I]))
			dest[++J] = from[I];
	while (J < 2)
		dest[++J] = side_null;
}
