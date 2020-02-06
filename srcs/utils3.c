/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:11:52 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/06 16:24:16 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	fill_enum(int tab[NB_ITER], int type, int nb, ...)
{
	int		i;
	va_list	ap;

	i = -1;
	ft_memset(tab, type, NB_ITER);
	va_start(ap, nb);
	while (++i < nb)
		tab[i] = va_arg(ap, int);
	va_end(ap);
}

void	*better_memset(void *s, int c, size_t len, size_t byte)
{
	while (len--)
	{
		((char*)s)[len * byte] = c;
	}
	return (s);
}

t_env	*create_new_chain(t_env *h)
{
	t_env	*ret;

	if (!(ret = (t_env*)malloc(sizeof(t_env))))
		error(-1, "CREATE NEW CHAIN");
	ret->nb_move = h->nb_move;
	ret->next = NULL;
	return (ret);
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
