/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:06:50 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/06 19:51:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	erase_env(void)
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
