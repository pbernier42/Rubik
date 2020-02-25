/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:05:25 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:54:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H

# include "rubik.h"

typedef struct s_line		t_line;
typedef struct s_move		t_move;
typedef struct s_turn		t_turn;
typedef struct s_sticker	t_sticker;
typedef struct s_list		t_list;

typedef unsigned long long	t_binary;

typedef enum e_argument		t_argument;
typedef enum e_arg_bin		t_arg_bin;

typedef enum e_group		t_group;
typedef enum e_side			t_side;
typedef enum e_color		t_color;
typedef enum e_mod			t_mod;
typedef enum e_around		t_around;

/*
** enums
*/

//paranm!
enum						e_argument
{
	arg_cube_all =			0b00000001,
	arg_corner =			0b00000010,
	arg_cube_two =			0b00000100,
	arg_corner_less =		0b00001000,
	arg_edge =				0b00010000,
	arg_edge_prim =			0b00100000,
	arg_cube_one =			0b01000000,
	arg_corner_less_prim =	0b10000000
};

// enum						e_argument
// {
// 	arg_cube =	0
// 	arg_corner = 1
// 	arg_edge = 2
// 	arg_edge_prim = 3
// };
//
//
// enum						e_arg_bin
// {
// 	arg_bin_cube = 0b0000 0000 0000 1000,
// 	arg_bin_corner = 0b0000 0000 1000 0000,
// 	arg_bin_edge = 0b0000 1000 0000 0000,
// 	arg_bin_edge_prim = 0b1000 0000 0000 0000
// };


enum						e_group
{
	grp_corner_rotate_twist,
	grp_edge_twist,
	grp_null
};

enum						e_side
{
	side_front, //0
	side_right, //1
	side_up,	//2
	side_back,	//3
	side_left,	//4
	side_down,	//5
	side_null	//6
};

enum						e_color
{
	color_red, 		//front //0
	color_yellow, 	//right	//1
	color_blue,		//up	//2
	color_orange, 	//back	//3
	color_white, 	//left	//4
	color_green, 	//down	//5
	color_null
};

enum						e_mod
{
	mod_twice,
	mod_reverse,
	mod_null
};

enum						e_around
{
	around_right,
	around_down,
	around_left,
	around_up,
	around_null
};

/*
** structs
*/

struct						s_line
{
	t_side					side;
	short					coo[3][2];
};

struct						s_move
{
	t_side					side;
	t_mod					mod;
};

struct						s_env
{
	size_t					nb_move;
	t_move					move_all[BUFF_MOVE];
	t_env					*next;
};

struct						s_turn
{
	char					**front;
	char					*right[3];
	char					*down[3];
	char					*left[3];
	char					*up[3];
};

struct						s_sticker
{
	t_side					side;
	short					coo[2];
};

struct						s_list
{
	size_t					nb_move;
	t_move					*move;
};


#endif
