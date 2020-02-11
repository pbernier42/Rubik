/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:14:46 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/11 17:11:53 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_move	*tab_tmove_conv_env(int *nb_move)
{
	size_t	i;
	size_t	j;
	t_env	*h;
	t_move	*ret;

	i = 0;
	j = 0;
	h = &env;
	if (!(ret = (t_move*)malloc(sizeof(t_move) * env.nb_move)))
		error(-1, "MALLOC ERROR CONV ENV TO TMOVE*");
	while (i < env.nb_move)
	{
		if (!(i % BUFF_MOVE) && i && !(j = 0))
			h = h->next;
		ret[i++] = h->move_all[j++];
	}
	if (nb_move)
		*nb_move = j;
	return (ret);
}
