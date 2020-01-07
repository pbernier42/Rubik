/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:32 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/07 13:06:34 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBIK_H
# define RUBIK_H

# include <unistd.h>
# include <stdbool.h>

typedef enum e_side		t_side;
typedef struct s_move	t_move;

enum					e_side
{
	side_null,
	side_front,
	side_right,
	side_up,
	side_back,
	side_left,
	side_down
};

struct					s_move
{
	t_side				side;
	bool				twice;
	bool				reverse;
};

#endif
