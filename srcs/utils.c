/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:49:33 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/09 18:04:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

short	in_side_tab(t_side side, t_side *tab_side, short size_tab)
{
	short	len_tab;

	len_tab = -1;
	while (tab_side && ++len_tab < size_tab)
		if (side == tab_side[len_tab])
			return (len_tab);
	return (-1);
}

bool	in_string(char c, char *string)
{
	short	len;

	len = 0;
	while (string && string[len] && c != string[len])
		++len;
	return ((string[len]));
}

size_t	skip_space(size_t len, char *string)
{
	while (string && IS_SPACE(string[len]))
		++len;
	return (len);
}
