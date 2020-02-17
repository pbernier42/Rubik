/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:25:53 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:45:39 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean_char(char **s, char c)
{
	size_t	l;
	char	*final;

	l = (*s) ? ft_strlen(*s) : 0;
	if (!(final = (char *)malloc(sizeof(char) * (l + 2))))
		return (NULL);
	l = -1;
	while ((*s)[++l])
		final[l] = (*s)[l];
	ft_memdel((void **)s);
	final[l++] = c;
	final[l] = '\0';
	*s = final;
	return (*s);
}
