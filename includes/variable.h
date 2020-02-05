/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:05:25 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/03 20:50:18 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H

typedef unsigned long long	t_binary;

/*
** enums
*/

typedef enum e_argument		t_argument;
typedef enum e_group		t_group;
typedef enum e_side			t_side;
typedef enum e_color		t_color;
typedef enum e_mod			t_mod;
typedef enum e_around		t_around;


enum						e_argument
{
	arg_cube_all = 0b000001,
	arg_corner = 0b000010,
	arg_cube_two = 0b000100,
	arg_corner_less = 0b001000,
	arg_edge = 0b010000,
	arg_cube_one = 0b100000
};

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

typedef struct s_env		t_env;
extern t_env				g_env;

typedef struct s_line		t_line;
typedef struct s_move		t_move;
typedef struct s_turn		t_turn;
typedef struct s_sticker	t_sticker;

struct						s_env
{
	int						nb_move;
	t_move					*(move_all[10]);
};

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
#endif
