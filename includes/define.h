/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:06:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/12 20:12:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "rubik.h"

/*
** error();
*/

# define ERR_WRONG_ARG_NUMBER			"Wrong number of arguments"
# define ERR_MALLOC						"Can't malloc"

/*
** ???
*/

# define WITH_LETTER					1
# define NB_ITER						5
# define DISPLAY(cube, side_null)		display(cube, side_null, (int[12]){7, 4, 7, 7, 3, 7, 5, 1, 2, 7, 6, 7})
# define BUFF_MOVE						50

# define STR_SIDE(i)					((char*[side_null + 1]){\
											"front", "right", "up", "back", "left", "down", "null"})[i]
# define STR_MOD(i)						((char*[mod_null + 1]){\
											"twice", "reverse", "null"})[i]
# define STR_AROUND(i)					((char*[around_null + 1]){\
											"right", "down", "left", "up", "null"})[i]

/*
** NUMBER
*/

# define NB_MOVE_MAX					6

# define I								i[0]
# define J								i[1]
# define K								i[2]

# define NB_BYTE						i[1]
# define NB_MOVE						i[1]
# define NB_SIDE						i[1]

# define NB_TURN(tmod)					((int[3]){2, 3, 1})[tmod]
# define NB_RANGE_SUB(a, b, n)			(((a > b) ? (a - b) : (b - a)) % n)

/*
** STRING
*/

# define STR_INITIALS_SIDE			((char[7]){"FRUBLD"})
# define STR_INITIALS_MOD			((char[3]){"2'"})
# define STR_INITIALS_SPACE			((char[6]){" \t\r\v\f\0"})

/*
** SHORT
*/

# define SHORT_IS_SPACE(space)			index_str(space, STR_INITIALS_SPACE)
# define SHORT_IS_SIDE(side)			index_str(side, STR_INITIALS_SIDE)
# define SHORT_IS_MOD(mod)				index_str(mod, STR_INITIALS_MOD)
# define SHORT_ABSOLUTE(number)			((number < 0) ? (number * -1) : (number))

# define INDEX_CORNER(tcolor)				index_tab_tstickers(\
												tbin_conv_tsides(cube, TAB_TSIDES_COLOR_ALL(tcolor)),\
												TAB_TSTICKERS_CORNER, 8)
# define INDEX_EDGE(tcolor_one, tcolor_two)	index_tab_tstickers(\
												tbin_conv_tsides(cube, TAB_TSIDES_COLOR_TWO(tcolor_one, tcolor_two)),\
												TAB_TSTICKERS_EDGE, 12)


/*
** TSTICKER
*/

# define TSTICKER_NULL					{side_null, {-1, -1}}

# define TSTICKERS_FRONT_UP_LEFT		{{side_front, {0, 0}}, {side_up, {2, 0}}, {side_left, {0, 2}}}
# define TSTICKERS_FRONT_UP_RIGHT		{{side_front, {0, 2}}, {side_up, {2, 2}}, {side_right, {0, 0}}}
# define TSTICKERS_FRONT_DOWN_RIGHT		{{side_front, {2, 2}}, {side_down, {0, 2}}, {side_right, {2, 0}}}
# define TSTICKERS_FRONT_DOWN_LEFT		{{side_front, {2, 0}}, {side_down, {0, 0}}, {side_left, {2, 2}}}

# define TSTICKERS_BACK_DOWN_RIGHT		{{side_back, {2, 0}}, {side_down, {2, 2}}, {side_right, {2, 2}}}
# define TSTICKERS_BACK_DOWN_LEFT		{{side_back, {2, 2}}, {side_down, {2, 0}}, {side_left, {2, 0}}}
# define TSTICKERS_BACK_UP_LEFT			{{side_back, {0, 2}}, {side_up, {0, 0}}, {side_left, {0, 0}}}
# define TSTICKERS_BACK_UP_RIGHT		{{side_back, {0, 0}}, {side_up, {0, 2}}, {side_right, {0, 2}}}

# define TSTICKER_FRONT_UP				{{side_front, {0, 1}}, {side_up, {2, 1}}, TSTICKER_NULL}
# define TSTICKER_FRONT_RIGHT			{{side_front, {1, 2}}, {side_right, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_FRONT_DOWN			{{side_front, {2, 1}}, {side_down, {0, 1}}, TSTICKER_NULL}
# define TSTICKER_FRONT_LEFT			{{side_front, {1, 0}}, {side_left, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_LEFT_UP				{{side_left, {0, 1}}, {side_up, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_RIGHT_UP				{{side_right, {0, 1}}, {side_up, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_BACK_DOWN				{{side_back, {2, 1}}, {side_down, {2, 1}}, TSTICKER_NULL}
# define TSTICKER_BACK_LEFT				{{side_back, {1, 2}}, {side_left, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_BACK_UP				{{side_back, {0, 1}}, {side_up, {0, 1}}, TSTICKER_NULL}
# define TSTICKER_BACK_RIGHT			{{side_back, {1, 0}}, {side_right, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_RIGHT_DOWN			{{side_right, {2, 1}}, {side_down, {1, 2}}, TSTICKER_NULL}
# define TSTICKER_LEFT_DOWN				{{side_left, {2, 1}}, {side_down, {1, 0}}, TSTICKER_NULL}

# define TAB_TSTICKERS_FRONT_CORNER		TSTICKERS_FRONT_UP_LEFT, TSTICKERS_FRONT_UP_RIGHT, \
											TSTICKERS_FRONT_DOWN_RIGHT, TSTICKERS_FRONT_DOWN_LEFT
# define TAB_TSTICKERS_BACK_CORNER		TSTICKERS_BACK_DOWN_RIGHT, TSTICKERS_BACK_DOWN_LEFT, \
											TSTICKERS_BACK_UP_LEFT, TSTICKERS_BACK_UP_RIGHT

# define TAB_TSTICKER_FRONT_EDGE		TSTICKER_FRONT_UP, TSTICKER_FRONT_RIGHT, \
											TSTICKER_FRONT_DOWN, TSTICKER_FRONT_LEFT
# define TAB_TSTICKER_TOP_EDGE			TSTICKER_LEFT_UP, TSTICKER_RIGHT_UP
# define TAB_TSTICKER_BACK_EDGE			TSTICKER_BACK_DOWN, TSTICKER_BACK_LEFT, \
											TSTICKER_BACK_UP, TSTICKER_BACK_RIGHT
# define TAB_TSTICKER_DOWN_EDGE			TSTICKER_RIGHT_DOWN, TSTICKER_LEFT_DOWN

# define TAB_TSTICKERS_CORNER			((t_sticker[8][3]){TAB_TSTICKERS_FRONT_CORNER, \
											TAB_TSTICKERS_BACK_CORNER})
# define TAB_TSTICKERS_EDGE				((t_sticker[12][3]){TAB_TSTICKER_FRONT_EDGE, TAB_TSTICKER_TOP_EDGE, \
											TAB_TSTICKER_BACK_EDGE, TAB_TSTICKER_DOWN_EDGE})

/*
** COORDINATE
*/

# define COO_Y							coo[0]
# define COO_X							coo[1]

# define TAB_COO_LEFT					{{0, 0}, {1, 0}, {2, 0}}
# define TAB_COO_UP						{{0, 0}, {0, 1}, {0, 2}}
# define TAB_COO_RIGHT					{{0, 2}, {1, 2}, {2, 2}}
# define TAB_COO_DOWN					{{2, 0}, {2, 1}, {2, 2}}

# define TAB_COO_LEFT_INVERTED			{{2, 0}, {1, 0}, {0, 0}}
# define TAB_COO_UP_INVERTED			{{0, 2}, {0, 1}, {0, 0}}
# define TAB_COO_RIGHT_INVERTED			{{2, 2}, {1, 2}, {0, 2}}
# define TAB_COO_DOWN_INVERTED			{{2, 2}, {2, 1}, {2, 0}}

/*
** TLINE
*/

# define TLINE(l_side, l_coo)			((t_line){l_side, l_coo})

# define TAB_TLINE_AROUND_RIGHT			((t_line[6]){TLINE(side_right, TAB_COO_LEFT), TLINE(side_back, TAB_COO_LEFT), TLINE(side_right, TAB_COO_UP_INVERTED), \
											TLINE(side_left, TAB_COO_LEFT), TLINE(side_front, TAB_COO_LEFT), TLINE(side_right, TAB_COO_DOWN)})

# define TAB_TLINE_AROUND_DOWN			((t_line[6]){TLINE(side_down, TAB_COO_UP), TLINE(side_down, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_UP), \
											TLINE(side_down, TAB_COO_DOWN_INVERTED), TLINE(side_down, TAB_COO_LEFT_INVERTED), TLINE(side_back, TAB_COO_DOWN_INVERTED)})

# define TAB_TLINE_AROUND_LEFT			((t_line[6]){TLINE(side_left, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_UP), \
											TLINE(side_right, TAB_COO_RIGHT), TLINE(side_back, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_DOWN_INVERTED)})

# define TAB_TLINE_AROUND_UP			((t_line[6]){TLINE(side_up, TAB_COO_DOWN), TLINE(side_up, TAB_COO_RIGHT_INVERTED), TLINE(side_back, TAB_COO_UP_INVERTED), \
											TLINE(side_up, TAB_COO_UP_INVERTED), TLINE(side_up, TAB_COO_LEFT), TLINE(side_front, TAB_COO_DOWN)})

# define TAB_TLINE_AROUND(tside)		((t_line[4]){TAB_TLINE_AROUND_RIGHT[tside], TAB_TLINE_AROUND_DOWN[tside], \
											TAB_TLINE_AROUND_LEFT[tside], TAB_TLINE_AROUND_UP[tside]})

/*
** TSIDE
*/

# define TSIDE_AROUND(taround, tside)	TAB_TLINE_AROUND(tside)[taround].side

# define TSIDE_CORNER(index, i)			TAB_TSTICKERS_CORNER[index][i].side
# define TSIDE_SIDE						side[0]
# define TSIDE_SAVE						side[1]

# define TSIDE_BIGGEST					tab_side_edge[0]

# define TSIDE_PAD_SIX					side_null, side_null, side_null, side_null, side_null, side_null

# define TAB_TSIDE_NULL(tab_tside)		copy_tab_tside(tab_tside, ((t_side[side_null]){TSIDE_PAD_SIX}), 6)

# define TAB_TSIDES_COLOR_ONE(tcolor_one) 				(t_side[3]){(t_side)tcolor_one, side_null , side_null}
# define TAB_TSIDES_COLOR_TWO(tcolor_one, tcolor_two)	(t_side[3]){(t_side)tcolor_one, (t_side)tcolor_two, side_null}
# define TAB_TSIDES_COLOR_ALL(tcolor)					(t_side*)tcolor

/*
** TBIN
*/

# define BIN_CUBE 						(binary[0])
# define BIN_CORNER						(binary[1])
# define BIN_CORNER_LESS				(binary[2])
# define BIN_EDGE						(binary[3])
# define BIN_EDGE_PRIM					(binary[4])
# define BIN_EDGE_EXTREMITY				(binary[5])

# define BIN_ORIGIN						(binary_angle[0])
# define BIN_LAYER						(binary_angle[1])

# define TAB_BIN_EDGE_OPPOSITE			(edge[0])
# define TAB_BIN_EDGE_NEAR				(edge[1])

# define BIN_EDGES_NEAR					(TAB_BIN_EDGE_NEAR[0] | TAB_BIN_EDGE_NEAR[1] | TAB_BIN_EDGE_NEAR[2])
# define BIN_EDGES_OPPOSITE				(TAB_BIN_EDGE_OPPOSITE[0] | TAB_BIN_EDGE_OPPOSITE[1] | TAB_BIN_EDGE_OPPOSITE[2])

# define BIN_RIGHT_ANGLE				(BIN_CORNER | BIN_EDGE | BIN_EDGE_PRIM)

# define TBIN_CONV_TSIDE(tside, tbin)	tbin_conv_tab_tsides(((t_side[1]){tside}), 1, tbin)

/*
** TMOVE
*/

# define TMOVE_NULL						{side_null, mod_null}
# define TMOVE_PAD_TREE					TMOVE_NULL, TMOVE_NULL, TMOVE_NULL
# define TMOVE_PAD_FIVE					TMOVE_NULL, TMOVE_NULL, TMOVE_NULL, TMOVE_NULL, TMOVE_NULL

# define TAB_TMOVE_ONE(tmove)			((t_move[NB_MOVE_MAX]){tmove, TMOVE_PAD_FIVE})

/*
** TAROUND
*/

# define TAROUND_ROTATE(taround, nb)	((taround + nb) % 4)
# define TAROUND_ETATOR(taround, nb)	(SHORT_ABSOLUTE(taround - nb) % 4)

/*
** GROUPS
*/


# define ROTATE_CORNER_TO_EDGE			"F' L B"
# define ROTATE_EDGE					"R' F D' F'"

# define TAB_STR_GROUPS(i)				(char[grp_null][10]) \
										{ \
											ROTATE_CORNER_TO_EDGE, \
											ROTATE_EDGE \
										}[i]

#endif
