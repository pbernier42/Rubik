/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:11:00 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/03 21:28:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_env	t_env;
typedef struct s_move	t_move;
typedef enum e_side		t_side;
typedef enum e_mod		t_mod;
extern t_env			g_env;

t_env					g;

enum					e_side
{
	side_front,
	side_right,
	side_up,
	side_back,
	side_left,
	side_down,
	side_null
};

enum					e_mod
{
	mod_twice,
	mod_reverse,
	mod_null
};

struct					s_move
{
	t_side				side;
	t_mod				mod;
};

struct					s_env
{
	int					i;
	t_move				*(buffer[10]);
};

int		main(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g.i = 0;
	g.buffer[1] = NULL;
	g.buffer[0] = malloc((sizeof(t_move) * 10) + 1);
	while (g.buffer[j])
	{
		while (g.buffer[j][i]) // comment iterer ?
		{
			(g.buffer)[j][i].side = (i + 1) % side_null;
			(g.buffer)[j][i].mod = (i + 1) % mod_null;
			i++;
		}
		j++;
	}
	g.buffer[0] = malloc((sizeof(t_move) * 10) + 1);
	i = 0;
	while (i < 10)
	{
		printf("%d | %d\n", (g.buffer)[i]->side, (g.buffer)[i]->mod);
		i++;
	}
	return (0);
}
