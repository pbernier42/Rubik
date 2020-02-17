/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:43:36 by rlecart           #+#    #+#             */
/*   Updated: 2020/02/12 20:04:17 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

void	error(int typecode, char *error_type, char *detail)
{
	printf("%s\n", error_type);
	//ft_putstr_fd(error_type, 2);
	if (detail)
	{
		printf(" at/trying to {%s}\n", detail);
		// ft_putstr_fd(" at/trying to { ", 2);
		// ft_putstr_fd(detail, 2);
		// ft_putstr_fd(" }", 2);
	}
	//ft_putstr_fd("\n", 2);
	exit(typecode);
}
