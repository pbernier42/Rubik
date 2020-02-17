/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:31:23 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:48:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist		*ft_lstnew(void const *content, size_t content_size)
{
	t_clist		*ptr;

	ptr = NULL;
	if (!(ptr = (t_clist*)malloc(sizeof(t_clist))))
		return (NULL);
	ptr->next = NULL;
	if (!(content))
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	if (!(ptr->content = malloc(sizeof(content_size))))
		return (NULL);
	ft_memmove(ptr->content, content, content_size);
	ptr->content_size = content_size;
	return (ptr);
}
