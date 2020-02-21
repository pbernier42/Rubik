/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:32 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/21 18:14:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUBIK_H
# define RUBIK_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# include "../lib/libft/includes/libft.h"

typedef struct s_env		t_env;
extern t_env				env;

extern char ***g_layer;

# include "define.h"
# include "variable.h"
# include "prototype.h"

#endif
