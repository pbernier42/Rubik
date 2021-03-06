/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:48:16 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/17 20:45:43 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while ((char)s[start] && i < len)
			str[i++] = (char)s[start++];
		str[len] = '\0';
	}
	return (str);
}
