/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:51:56 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:45:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_clist **alst, void (*del)(void*, size_t))
{
	t_clist		*ptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		free(ptr);
		if (ptr->next)
			*alst = NULL;
		ptr = ptr->next;
	}
}
