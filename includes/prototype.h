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
**	resolve/resolve.c
*/

void		resolve(char ***cube);

/*
**	resolve/two_two_bloc.c
*/

void		two_two_bloc(char ***cube, t_color corner[3]);

/*
**	utils/find.c
*/

void		tbin_tab_find_edge(t_binary edge_linked[3], t_sticker corner[3]);
t_sticker	tsticker_find_edge(t_sticker edge[2]);

/*
**	utils/coverter.c
*/

t_binary	tbin_conv_tstickers(t_sticker bloc[3]);
t_binary	tbin_conv_tsides(char ***cube, t_side side[3]);
t_binary	tbin_conv_char(char **cube_side, t_side side);

/*
**	utils/parsing.c
*/

short		index_tab_tside(t_side side, t_side *tab_side, short size_tab);
short		index_tab_around(t_binary bin_cube);


#endif
