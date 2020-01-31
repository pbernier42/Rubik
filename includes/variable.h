/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:05:25 by pbernier          #+#    #+#             */
/*   Updated: 2020/01/28 18:05:26 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H

enum						e_argument
{
	arg_cube_all = 0b000001,
	arg_corner = 0b000010,
	arg_cube_two = 0b000100,
	arg_corner_less = 0b001000,
	arg_edge = 0b010000,
	arg_cube_one = 0b100000
};

#endif
