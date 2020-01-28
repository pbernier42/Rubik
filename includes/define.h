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

# define COO_Y							coo[0]
# define COO_X							coo[1]

# define TAB_COO_LEFT					{{0, 0}, {1, 0}, {2, 0}}
# define TAB_COO_UP						{{0, 0}, {0, 1}, {0, 2}}
# define TAB_COO_RIGHT					{{0, 2}, {1, 2}, {2, 2}}
# define TAB_COO_DOWN					{{2, 0}, {2, 1}, {2, 2}}

# define TLINE(l_s, l_c)				((t_line){l_s, l_c})

# define TAB_TLINE_AROUND_RIGHT			((t_line[6]){TLINE(side_right, TAB_COO_LEFT), TLINE(side_back, TAB_COO_LEFT), TLINE(side_right, TAB_COO_UP), TLINE(side_left, TAB_COO_LEFT), TLINE(side_front, TAB_COO_LEFT), TLINE(side_right, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_DOWN			((t_line[6]){TLINE(side_down, TAB_COO_UP), TLINE(side_down, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_UP), TLINE(side_down, TAB_COO_DOWN), TLINE(side_down, TAB_COO_LEFT), TLINE(side_back, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_LEFT			((t_line[6]){TLINE(side_left, TAB_COO_RIGHT), TLINE(side_front, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_UP), TLINE(side_right, TAB_COO_RIGHT), TLINE(side_back, TAB_COO_RIGHT), TLINE(side_left, TAB_COO_DOWN)})
# define TAB_TLINE_AROUND_UP			((t_line[6]){TLINE(side_up, TAB_COO_DOWN), TLINE(side_up, TAB_COO_RIGHT), TLINE(side_back, TAB_COO_UP), TLINE(side_up, TAB_COO_UP), TLINE(side_up, TAB_COO_LEFT), TLINE(side_front, TAB_COO_DOWN)})
# define TLINE_TAB_AROUND(side)			((t_line[4]){TAB_TLINE_AROUND_RIGHT[side], TAB_TLINE_AROUND_DOWN[side], TAB_TLINE_AROUND_LEFT[side], TAB_TLINE_AROUND_UP[side]})

# define BIN_CUBE 						(binary[0])
# define BIN_CORNER						(binary[1])
# define BIN_TAB_EDGE_OPPOSITE			(edge[0])
# define BIN_TAB_EDGE_NEAR				(edge[1])

# define TAB_TSIDES_COLOR_ALL(tcolor)	(t_side*)tcolor
# define TAB_TSIDES_COLOR_TWO(tcolor)	(t_side[3]){(t_side)tcolor[0], (t_side)tcolor[1], side_null}



#endif
