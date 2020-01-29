/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:32 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/27 22:23:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBIK_H
# define RUBIK_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# include "../lib/libft/includes/libft.h"
# include "define.h"

typedef enum e_color		t_color;
typedef enum e_side			t_side;
typedef enum e_mod			t_mod;
typedef enum e_around		t_around;
typedef struct s_move		t_move;
typedef struct s_turn		t_turn;
typedef struct s_line		t_line;
typedef struct s_sticker	t_sticker;
typedef struct s_action		t_action;
typedef struct s_condition	t_condition;
typedef unsigned long long	t_binary;



# define INITIALS_MOD		((char[3]){"2'"})

# define WITH_LETTER		1
# define NB_ITER			5

# define DISPLAY(cube, side_null)		display(cube, side_null, (int[12]){7, 4, 7, 7, 3, 7, 5, 1, 2, 7, 6, 7})

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
	color_red,
	color_yellow,
	color_blue,
	color_orange,
	color_white,
	color_green,
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

struct						s_action
{
	t_side					side;
	t_binary				binary;
};

struct						s_condition
{
	t_binary				binary;
	t_move					move[NB_ITER];
};

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

# define INITIALS_SPACE		((char[6]){" \t\r\v\f\0"})
# define IS_SPACE(space) 	in_string(space, INITIALS_SPACE)
# define IS_SIDE(side)		in_string(side, INITIALS_SIDE)
# define IS_MOD(mod)		in_string(mod, INITIALS_MOD)


bool						in_string(char lettre, char *string);
size_t						skip_space(size_t len, char *string);
void						ungly_display(char ***cube);
t_binary					combine_binary(t_binary *tab, short size_tab);

/*
** utils2.c
*/

void						print_ins(t_move *tab, size_t nb);
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

/*
** resolve.c
*/

void		resolve(char ***cube);
void		bin(t_binary nbr);
t_binary	bloc_binary(char ***cube, t_side side[3]);


# include "prototype.h"
# include "variable.h"

#endif
