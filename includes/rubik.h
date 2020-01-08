/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:32 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/08 17:01:36 by rlecart          ###   ########.fr       */
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


# define INITIALS_SIDE		((char[6]){"FRUBLD"})
# define INITIALS_MOD		((char[2]){"2'"})

# define SQUARE				true
# define FULL				false

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

struct						s_move
{
	t_side					side;
	t_mod					mod;
};

struct						s_turn
{
	char					**turn;

	char					**right;
	char					**down;
	char					**left;
	char					**up;
};

/*
** error.c
*/

void						error(int typecode);

/*
** display.c
*/

void						display(char ***tab, bool sw, int cel[12]);

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
t_turn						instruction_turn(char ***cube, t_side side);

/*
** utils.c
*/

# define INITIALS_SPACE		((char[5]){" \t\r\v\f"})
# define IS_SPACE(space) 	in_string(space, INITIALS_SPACE)
# define IS_SIDE(side)		in_string(side, INITIALS_SIDE)
# define IS_MOD(mod)		in_string(mod, INITIALS_MOD)


bool						in_string(char lettre, char *string);
size_t						skip_space(size_t len, char *string);

#endif
