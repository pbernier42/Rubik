/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:22:23 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/12 20:22:52 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "rubik.h"


/*
** main.c
*/

void		print_tab_tmove(t_move *tab, size_t nb);
void		bin(t_binary nbr);
void 		ungly_display(char ***cube);

/*
** cube.c
*/

char		***init_cube(void);
void		erase_cube(char ***cube);

/*
** turn.c
*/

short		read_tab_tmove(char ***cube, int nb_move, t_move *move);
t_turn		tturn_conv_tside(char ***cube, t_side side);
void		tab_char_find_around(char *data[3], char ***cube, t_line line);
void		turn_modifier(t_turn turn, t_mod mod);
void		turn_once(t_turn turn);

/*
** resolve/resolve.c
*/

t_instruct	find_best_resolve(char ***cube, t_instruct shuffle);
void		resolve(char ***cube, t_color corner[3]);

/*
** resolve/two_two_bloc.c
*/

void		two_two_bloc(char ***cube, t_color corner[3]);
short		bring_edge_opposite(char ***cube, t_side color[3],
				t_binary edge[2][3], short index_corner);
short		tab_tmove_edge_opposite(t_move move[NB_MOVE_MAX], t_binary bin_cube,
				t_binary tab_bin_edge_opposite[3],  t_sticker corner[3]);
short		tab_tmove_edge_middle(t_move move[NB_MOVE_MAX], short index_edge,
				t_binary bin_corner);
short		tab_tmove_edge_near(t_move move[NB_MOVE_MAX], t_binary binary[6]);
short		tab_tmove_twist_edge(t_move move[NB_MOVE_MAX], t_binary	binary[6], t_binary *edge);
short		tab_tmove_edge_two(t_move move[NB_MOVE_MAX], t_binary binary[6],
				short index_corner);
short		tab_tmove_right_angle(t_move move[NB_MOVE_MAX], t_binary binary[6],
				t_side side_destination);


/*
** utils/find.c
*/

void		tab_tbin_find_edge(t_binary edge_linked[3], t_sticker corner[3]);
t_sticker	tsticker_find_edge(t_sticker edge[2]);
t_side		tside_find_biggest_weight(t_binary binary);
short		tab_tside_find_filled(t_side tab_side[side_null], t_binary binary);

/*
** utils/converter.c
*/

t_binary	tbin_conv_tstickers(t_sticker bloc[3]);
t_binary	tbin_conv_tsides(char ***cube, t_side side[3]);
t_binary	tbin_conv_char(char **cube_side, t_side side);
t_binary	tbin_conv_tab_tsides(t_side *side, short nb_side, t_binary binary);
void		tab_tmove_conv_str(t_move *dst, int nb_move, char *str);
t_move		tmove_conv_char(char arg[2]);
void		tab_tmove_adjust_group(t_move *moves, size_t nb_move,
				t_side side_reference, short rotate);


/*
** utils/parsing.c
*/

size_t		sizet_count_arg(char *argv);
size_t		sizet_skip_space(size_t len, char *string);
short		index_tab_tside(t_side side, t_side *tab_side, short size_tab);
short		index_tab_tstickers(t_binary bin_cube,
				t_sticker (*tab_stickers)[3], short size_tab);
short		index_str(char c, char *string);
short		index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab);
short		nb_byte_tbin(t_binary binary, short spectrum);

/*
** utils/fill.c
*/

short		copy_tab_tside(t_side *dest, t_side *from, short size_tab);
short		copy_tab_tmove(t_move dest[NB_MOVE_MAX], t_move from[NB_MOVE_MAX]);
void		copy_tmove(t_move *dest, t_side side, t_mod mod);

/*
** argument.c
*/

void		tbin_update(char ***cube, t_binary binary[6], t_color corner[3],
				t_argument bin_argument);
void		tab_tside_edit(t_side dest[3], t_side from[3], t_binary selecter);

/*
** env.c
*/
//soir utiliser *move soit realloc
t_move		*tab_tmove_conv_env(size_t *nb_move); //return instructuion
void		add_env(t_move *move, int nb_move);
t_env		*find_chain(t_env *start);
t_env		*create_new_chain(t_env *h);
void		erase_env(void);
void		print_env(void);

/*
** refine.c
*/

void		refine(t_move *tab, size_t *nb);
t_move		stash_ins(t_move *tmp, size_t *count, size_t *j);

/*
** error.c
*/

void		error(int typecode, char *error_type, char *detail);

/*
** display.c
*/

void		display(char ***tab, int face, int cel[12]);

#endif
