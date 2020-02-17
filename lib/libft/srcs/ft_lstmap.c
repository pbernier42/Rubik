/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:08:22 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:48:27 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist		*ft_lstmap(t_clist *lst, t_clist *(*f)(t_clist *elem))
{
	t_clist		*ptr;

	ptr = NULL;
	if (lst && f)
	{
		ptr = f(lst);
		ptr->next = lst->next ? ft_lstmap(lst->next, f) : NULL;
	}
	return (ptr);
}
