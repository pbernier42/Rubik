/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:22:23 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 17:22:24 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/*
**	turn.c
*/

short		read_tab_tmove(char ***cube, int nb_move, t_move *move);
t_turn		tturn_conv_tside(char ***cube, t_side side);
void		tab_char_find_around(char *data[3], char ***cube, t_line line);
void		turn_modifier(t_turn turn, t_mod mod);
void		turn_once(t_turn turn);

/*
**	resolve/resolve.c
*/

void		resolve(char ***cube);

/*
**	resolve/two_two_bloc.c
*/

void		two_two_bloc(char ***cube, t_color corner[3]);
short		tab_tmove_edge_opposite(t_move move[NB_MOVE_MAX], t_binary bin_cube,
				t_binary tab_bin_edge_opposite[3],  t_sticker corner[3]);
short		tab_tmove_edge_middle(t_move move[NB_MOVE_MAX], short i,
				t_binary bin_corner);

/*
**	utils/find.c
*/

void		tab_tbin_find_edge(t_binary edge_linked[3], t_sticker corner[3]);
t_sticker	tsticker_find_edge(t_sticker edge[2]);
t_side		tside_find_biggest_weight(t_binary binary);

/*
**	utils/converter.c
*/

t_binary	tbin_conv_tstickers(t_sticker bloc[3]);
t_binary	tbin_conv_tsides(char ***cube, t_side side[3]);
t_binary	tbin_conv_char(char **cube_side, t_side side);
t_binary	tbin_conv_tab_tsides(t_side *side, short nb_side, t_binary binary);

/*
**	utils/parsing.c
*/

short		index_tab_tside(t_side side, t_side *tab_side, short size_tab);
short		index_tab_tstickers(t_binary bin_cube,
				t_sticker (*tab_stickers)[3], short size_tab);
short		copy_tab_tmove(t_move dest[NB_MOVE_MAX], t_move from[NB_MOVE_MAX]);
short		index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab);
short		nb_byte_tbinary(t_binary binary, short spectrum);


#endif
