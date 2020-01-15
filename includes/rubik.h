/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:32 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/14 17:53:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBIK_H
# define RUBIK_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "../lib/libft/includes/libft.h"

typedef enum e_side			t_side;
typedef enum e_mod			t_mod;
typedef struct s_move		t_move;
typedef struct s_turn		t_turn;
typedef struct s_line		t_line;

# define INITIALS_SIDE		((char[6]){"FRUBLD"})
# define INITIALS_SIDE2		((char[6]){"frubld"})
# define INITIALS_MOD		((char[2]){"2'"})

# define WITH_LETTER		1

# define F_NONE				0
# define F_FRONT			1
# define F_RIGHT			2
# define F_UP				3
# define F_BACK				4
# define F_LEFT				5
# define F_DOWN				6

# define DISPLAY(cube, F_NONE)		display(cube, F_NONE, NULL)

enum						e_side
{
	side_front,
	side_right,
	side_up,
	side_back,
	side_left,
	side_down,
	side_null
};

enum						e_mod
{
	mod_twice,
	mode_reverse,
	mod_null
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

/*
** error.c
*/

void						error(int typecode);

/*
** display.c
*/

void						display(char ***tab, int face, int cel[12]);

/*
** init.c
*/

char						***init_tab(void);

/*
** main.c
*/

int							arg_count(char *argv);
void						instructions(char ***cube, int arg_count, char *argv);
t_move						arg_instruction(char arg[2]);
void						read_instruction(char ***cube, int arg_count, t_move *instruction);

# define C_LEFT				{{0, 0}, {1, 0}, {2, 0}}
# define C_UP				{{0, 0}, {0, 1}, {0, 2}}
# define C_RIGHT			{{0, 2}, {1, 2}, {2, 2}}
# define C_DOWN				{{2, 0}, {2, 1}, {2, 2}}
# define LINE(l_s, l_c)		((t_line){l_s, l_c})
# define A_RIGHT			((t_line[6]){LINE(side_right, C_LEFT), LINE(side_back, C_LEFT), LINE(side_right, C_UP), LINE(side_left, C_LEFT), LINE(side_front, C_LEFT), LINE(side_right, C_DOWN)})
# define A_DOWN				((t_line[6]){LINE(side_down, C_UP), LINE(side_down, C_RIGHT), LINE(side_front, C_UP), LINE(side_down, C_DOWN), LINE(side_down, C_LEFT), LINE(side_back, C_DOWN)})
# define A_LEFT				((t_line[6]){LINE(side_left, C_RIGHT), LINE(side_front, C_RIGHT), LINE(side_left, C_UP), LINE(side_right, C_RIGHT), LINE(side_back, C_RIGHT), LINE(side_left, C_DOWN)})
# define A_UP				((t_line[6]){LINE(side_up, C_DOWN), LINE(side_up, C_RIGHT), LINE(side_back, C_UP), LINE(side_up, C_UP), LINE(side_up, C_LEFT), LINE(side_up, C_DOWN)})
# define AROUND(side)		((t_line[4]){A_RIGHT[side], A_DOWN[side], A_LEFT[side], A_UP[side]})

t_turn						instruction_turn(char ***cube, t_side side);
void						turn_side(t_turn turn);

/*
** utils.c
*/

# define INITIALS_SPACE		((char[6]){" \t\r\v\f\0"})
# define IS_SPACE(space) 	in_string(space, INITIALS_SPACE)
# define IS_SIDE(side)		in_string(side, INITIALS_SIDE)
# define IS_MOD(mod)		in_string(mod, INITIALS_MOD)


bool						in_string(char lettre, char *string);
size_t						skip_space(size_t len, char *string);

#endif
