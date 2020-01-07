/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:49:33 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/07 17:49:35 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

bool	in_string(char c, char *string)
{
	short	len;

	len = 0;
	while (string[len] && c != string[len])
		++len;
	return ((string[len]));
}

size_t	skip_space(size_t len, char *string)
{
	while (string && IS_SPACE(string[len]))
		++len;
	return (len);
}
