/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:32:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:48:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist		*ft_lstlast(t_clist **alst)
{
	t_clist		*ptr;

	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
