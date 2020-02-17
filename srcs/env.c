/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:26:04 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 21:10:49 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

int		erase_move(t_move *move)
{
	free(move);
	return (0);
}

t_list	tab_tmove_conv_env(t_list src)
{
	size_t	i;
	size_t	j;
	t_env	*h;
	t_list	ret;

	i = 0;
	j = 0;
	h = &env;
	if (env.nb_move <= src.nb_move)
		ret.move = src.move;
	else if (!(erase_move(src.move)) && !(ret.move = (t_move*)malloc(sizeof(t_move) * env.nb_move)))
		error(-1, ERR_MALLOC, "tab_tmove_conv_env()");
	while (i < env.nb_move)
	{
		if (!(i % BUFF_MOVE) && i && !(j = 0))
			h = h->next;
		ret.move[i++] = h->move_all[j++];
	}
	ret.nb_move = j;
	return (ret);
}

void	add_env(t_move *move, int nb_move)
{
	int		i;
	int		j;
	int		left;
	t_env	*h;

	i = 0;
	j = env.nb_move % BUFF_MOVE;
	left = BUFF_MOVE - j;
	h = find_chain(NULL);
	while (i < nb_move)
	{
		if (!left && env.nb_move)
		{
			h = find_chain(h);
			left = BUFF_MOVE;
			j = 0;
		}
		h->move_all[j] = move[i];
		env.nb_move++;
		left--;
		i++;
		j++;
	}
}

t_env	*find_chain(t_env *start)
{
	int		i;
	t_env	*ret;

	ret = (start) ? start : &env;
	i = (start) ? 1 : ret->nb_move / BUFF_MOVE;
	while (ret && i > 0)
	{
		if (!ret->next && i)
			ret->next = create_new_chain(ret);
		ret = ret->next;
		i--;
	}
	return (ret);
}

t_env	*create_new_chain(t_env *h)
{
	t_env	*ret;

	if (!(ret = (t_env*)malloc(sizeof(t_env))))
		error(-1, ERR_MALLOC, "create_new_chain()");
	ret->nb_move = h->nb_move;
	ret->next = NULL;
	return (ret);
}

void		erase_env(void)
{
	size_t	i;
	size_t	j;
	t_env	*h;
	t_env	*tmp;

	i = env.nb_move / BUFF_MOVE;
	j = 0;
	h = &env;
	while (i > 0)
	{
		tmp = h->next;
		if (h != &env)
			free(h);
		else
			h->next = NULL;
		if (tmp)
			h = tmp;
		i--;
	}
}

void		print_env(void)
{
	size_t	i;
	size_t	j;
	t_env	*h;

	i = 0;
	j = 0;
	h = &env;
	while (i < env.nb_move)
	{
		if (!(i % BUFF_MOVE) && i && !(j = 0))
			h = h->next;
		ft_putchar(STR_INITIALS_SIDE[h->move_all[j].side]);
		ft_putchar(STR_INITIALS_MOD[h->move_all[j].mod]);
		if (i + 1 != env.nb_move)
			ft_putchar(' ');
		i++;
		j++;
	}
	ft_putchar('\n');
}
