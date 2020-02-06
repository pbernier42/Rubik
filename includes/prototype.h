/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:22:23 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/06 16:56:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "rubik.h"

//type
//
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

void		resolve(char ***cube);

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
short		tab_tmove_edge_near(t_move move[NB_MOVE_MAX], t_binary binary[5]);
short		tab_tmove_twist_edge(t_move move[NB_MOVE_MAX], t_binary	binary[5]);
void		tbin_update(char ***cube, t_binary binary[5], t_color corner[3],
				t_argument argument);

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

/*
** utils/parsing.c
*/

short		index_tab_tside(t_side side, t_side *tab_side, short size_tab);
short		index_tab_tstickers(t_binary bin_cube,
				t_sticker (*tab_stickers)[3], short size_tab);
short		index_string(char c, char *string);
short		index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab);
short		nb_byte_tbinary(t_binary binary, short spectrum);
short		copy_tab_tside(t_side dest[side_null], t_side from[side_null]);
short		copy_tab_tmove(t_move dest[NB_MOVE_MAX], t_move from[NB_MOVE_MAX]);

/*
** error.c
*/

void						error(int typecode, char *str);

/*
** display.c
*/

void						display(char ***tab, int face, int cel[12]);

/*
** init.c
*/

char						***init_tab(void);

/*
** refine.c
*/

void						refine(t_move *tab, size_t nb);

/*
** main.c
*/

int							arg_count(char *argv);
void						instructions(char ***cube, int arg_count, char *argv);
t_move						arg_instruction(char arg[2]);
void						read_instruction(char ***cube, int arg_count, t_move *instruction);
t_turn						instruction_turn(char ***cube, t_side side);

/*
** utils.c
*/

size_t						skip_space(size_t len, char *string);
void						ungly_display(char ***cube);
t_binary					combine_binary(t_binary *tab, short size_tab);

/*
** utils2.c
*/

void						print_ins(t_move *tab, size_t nb);
void						print_env(void);
int							pdebug(void);
int							mod_range(int a, int b, int n);
t_binary					isolate(t_side side, t_binary binary);
t_binary					stob(t_side *side, size_t nb_side, t_binary binary);

/*
** utils3.c
*/

size_t						byte_counter(t_binary binary, size_t nb);
void						fill_enum(int tab[NB_ITER], int type, int nb, ...);
void						fill_side_bin(t_side tab[6], t_binary binary);
void						add_env(t_move *move, int nb_move);

/*
** resolve.c
*/

void		resolve(char ***cube);
void		bin(t_binary nbr);
t_binary	bloc_binary(char ***cube, t_side side[3]);

#endif
