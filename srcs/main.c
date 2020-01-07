/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:04:51 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/07 13:04:52 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

t_move	arg_instruction(char *arg)
{
	(void)arg;
	return ((t_move){side_null, true, true});
}

int		main(int argc, char **argv)
{
	int		len;
	t_move	instruction[argc - 1];
	//ableau

	len = 0;
	while (++len < argc)
	{
		instruction[len - 1] = arg_instruction(argv[len]);
		if (instruction[len - 1].side == side_null)
			return (-1);
	}
	//creation du tableau
	//suite du cul
	return (0);
}
