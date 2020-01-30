/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:06:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 18:06:52 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define NB_MOVE_MAX					6
# define INITIALS_SIDE					((char[7]){"FRUBLD"})

# define TSTICKER_NULL					{side_null, {-1, -1}}

# define TSTICKERS_FRONT_UP_LEFT		{{side_front, {0, 0}}, {side_up, {2, 0}}, {side_left, {0, 2}}}
# define TSTICKERS_FRONT_UP_RIGHT		{{side_front, {0, 2}}, {side_up, {2, 2}}, {side_right, {0, 0}}}
# define TSTICKERS_FRONT_DOWN_RIGHT		{{side_front, {2, 2}}, {side_down, {0, 2}}, {side_right, {2, 0}}}
# define TSTICKERS_FRONT_DOWN_LEFT		{{side_front, {2, 0}}, {side_down, {0, 0}}, {side_left, {2, 2}}}
# define TSTICKERS_BACK_DOWN_RIGHT		{{side_back, {2, 0}}, {side_down, {2, 2}}, {side_right, {2, 2}}}
# define TSTICKERS_BACK_DOWN_LEFT		{{side_back, {2, 2}}, {side_down, {2, 0}}, {side_left, {2, 0}}}
# define TSTICKERS_BACK_UP_LEFT			{{side_back, {0, 2}}, {side_up, {0, 0}}, {side_left, {0, 0}}}
# define TSTICKERS_BACK_UP_RIGHT		{{side_back, {0, 0}}, {side_up, {0, 2}}, {side_right, {0, 2}}}

# define TAB_TSTICKERS_FRONT_CORNER		TSTICKERS_FRONT_UP_LEFT, TSTICKERS_FRONT_UP_RIGHT, TSTICKERS_FRONT_DOWN_RIGHT, TSTICKERS_FRONT_DOWN_LEFT
# define TAB_TSTICKERS_BACK_CORNER		TSTICKERS_BACK_DOWN_RIGHT, TSTICKERS_BACK_DOWN_LEFT, TSTICKERS_BACK_UP_LEFT, TSTICKERS_BACK_UP_RIGHT

# define TAB_TSTICKERS_CORNER			((t_sticker[8][3]){TAB_TSTICKERS_FRONT_CORNER, TAB_TSTICKERS_BACK_CORNER})

# define TSTICKER_FRONT_UP				{{side_front, {0, 1}}, {side_up, {2, 1}}, TSTICKER_NULL}
# define TSTICKER_FRONT_RIGHT			{{side_front, {1, 2}}, {side_right, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_FRONT_DOWN			{{side_front, {2, 1}}, {side_down, {0, 1}}, TSTICKER_NULL}
# define TSTICKER_FRONT_LEFT			{{side_front, {1, 0}}, {side_left, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_LEFT_UP				{{side_left, {0, 1}}, {side_up, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_RIGHT_UP				{{side_right, {0, 1}}, {side_up, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_BACK_DOWN				{{side_back, {2, 1}}, {side_down, {2, 1}}, TSTICKER_NULL}
# define TSTICKER_BACK_LEFT				{{side_back, {1, 0}}, {side_left, {1, 0}}, TSTICKER_NULL}
# define TSTICKER_BACK_UP				{{side_back, {0, 1}}, {side_up, {0, 1}}, TSTICKER_NULL}
# define TSTICKER_BACK_RIGHT			{{side_back, {1, 2}}, {side_right, {1, 2}}, TSTICKER_NULL}

# define TSTICKER_RIGHT_DOWN			{{side_right, {0, 1}}, {side_down, {1, 2}}, TSTICKER_NULL}
# define TSTICKER_LEFT_DOWN				{{side_left, {2, 1}}, {side_down, {1, 0}}, TSTICKER_NULL}

# define TAB_TSTICKER_FRONT_EDGE		TSTICKER_FRONT_UP, TSTICKER_FRONT_RIGHT, TSTICKER_FRONT_DOWN, TSTICKER_FRONT_LEFT
# define TAB_TSTICKER_TOP_EDGE			TSTICKER_LEFT_UP, TSTICKER_RIGHT_UP
# define TAB_TSTICKER_BACK_EDGE			TSTICKER_BACK_DOWN, TSTICKER_BACK_LEFT, TSTICKER_BACK_UP, TSTICKER_BACK_RIGHT
# define TAB_TSTICKER_DOWN_EDGE			TSTICKER_RIGHT_DOWN, TSTICKER_LEFT_DOWN

# define TAB_TSTICKERS_EDGE				((t_sticker[12][3]){TAB_TSTICKER_FRONT_EDGE, TAB_TSTICKER_TOP_EDGE, TAB_TSTICKER_BACK_EDGE, TAB_TSTICKER_DOWN_EDGE})

# define COO_Y							coo[0]
# define COO_X							coo[1]

# define TAB_COO_LEFT					{{0, 0}, {1, 0}, {2, 0}}
# define TAB_COO_UP						{{0, 0}, {0, 1}, {0, 2}}
# define TAB_COO_RIGHT					{{0, 2}, {1, 2}, {2, 2}}
# define TAB_COO_DOWN					{{2, 0}, {2, 1}, {2, 2}}

# define TAB_COO_UP_INVERTED			{{0, 2}, {0, 1}, {0, 0}}
# define TAB_COO_DOWN_INVERTED			{{2, 2}, {2, 1}, {2, 0}}


# define TLINE(l_side, l_coo)			((t_line){l_side, l_coo})

# define TAB_TLINE_AROUND_RIGHT			((t_line[6]){TLINE(side_right, TAB_COO_LEFT), TLINE(side_back, TAB_COO_LEFT), TLINE(side_right, TAB_COO_UP), TLINE(side_left, TAB_COO_LEFT), TLINE(side_front, TAB_COO_LEFT), TLINE(side_right, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_DOWN			((t_line[6]){TLINE(side_down, TAB_COO_UP), TLINE(side_down, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_UP), 	 TLINE(side_down, TAB_COO_DOWN_INVERTED), TLINE(side_down, TAB_COO_LEFT), TLINE(side_back, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_LEFT			((t_line[6]){TLINE(side_left, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_UP),TLINE(side_right, TAB_COO_RIGHT), TLINE(side_back, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_UP			((t_line[6]){TLINE(side_up, TAB_COO_DOWN), TLINE(side_up, TAB_COO_RIGHT), TLINE(side_back, TAB_COO_UP),      TLINE(side_up, TAB_COO_UP_INVERTED), TLINE(side_up, TAB_COO_LEFT), TLINE(side_front, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND(tside)		((t_line[4]){TAB_TLINE_AROUND_RIGHT[tside], TAB_TLINE_AROUND_DOWN[tside], TAB_TLINE_AROUND_LEFT[tside], TAB_TLINE_AROUND_UP[tside]})

# define TSIDE_AROUND(taround, tside)	TAB_TLINE_AROUND(tside)[taround].side

# define TAB_BIN_EDGE_OPPOSITE			(edge[0])
# define TAB_BIN_EDGE_NEAR				(edge[1])

# define BIN_CUBE 						(binary[0])
# define BIN_CORNER						(binary[1])
# define BIN_CORNER_LESS				(binary[2])
# define BIN_EDGE						(binary[3])
# define BIN_EDGE_EXTREMITY				(binary[4])

# define BIN_EDGES_NEAR					TAB_BIN_EDGE_NEAR[0] | TAB_BIN_EDGE_NEAR[2] | TAB_BIN_EDGE_NEAR[2]
# define BIN_EDGES_OPPOSITE				TAB_BIN_EDGE_OPPOSITE[0] | TAB_BIN_EDGE_OPPOSITE[1] | TAB_BIN_EDGE_OPPOSITE[2]

# define TAB_TSIDES_COLOR_ALL(tcolor)	(t_side*)tcolor
# define TAB_TSIDES_COLOR_TWO(tcolor)	(t_side[3]){(t_side)tcolor[0], (t_side)tcolor[1], side_null}
# define TAB_TSIDES_COLOR_ONE(tcolor)	(t_side[3]){(t_side)tcolor[0], side_null , side_null}

# define I								i[0]
# define J								i[1]

# define NB_BYTE						i[1]
# define NB_MOVE						i[1]
# define NB_SIDE						i[1]

# define TMOVE_NULL						{side_null, mod_null}
# define TMOVE_PAD_TREE					TMOVE_NULL, TMOVE_NULL, TMOVE_NULL
# define TMOVE_PAD_FIVE					TMOVE_NULL, TMOVE_NULL, TMOVE_NULL, TMOVE_NULL, TMOVE_NULL
# define TAB_TMOVE_ONE(tmove)			((t_move[NB_MOVE_MAX]){tmove, TMOVE_PAD_FIVE})

# define NB_TURN(tmod)					((int[3]){2, 3, 1})[tmod]

# define TSIDE_SIDE						side[0]
# define TSIDE_SAVE						side[1]

# define TBIN_CONV_TSIDE(tside, tbin)	tbin_conv_tab_tsides(((t_side[1]){tside}), 1, tbin)

# define SHORT_ABSOLUTE(number)			((number < 0) ? (number * -1) : (number))
# define TAROUND_ROTATE(taround, nb)	((taround + nb) % 3)
# define TAROUND_ETATOR(taround, nb)	(SHORT_ABSOLUTE(taround - nb) % 3)

# define TSIDE_PAD_SIX					side_null, side_null, side_null, side_null, side_null, side_null
# define TAB_TSIDE_NULL(tab_tside)		copy_tab_tside(tab_tside, ((t_side[side_null]){TSIDE_PAD_SIX}))

#endif
