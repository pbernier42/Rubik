/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:51:47 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/20 20:43:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rubik.h>

// tmp[2]
// tmp[i] pour choisir quelle var
//
// compter quand meme si y'a pas d'insidence (U et D)
// F B / L R / U D      if (F && != B) ++;
//
// F R U B L D
// F2 R2 U2 B2 L2 D2
//
// ((FFFFFFF % 4) == 0) = ""
//             || == 1 = "F"
//             || == 2 = "F2"
//             || == 3 = "'"
//
// nb = 18
//
// 3 | -1
//
// F2
// B'
// F
// R2
// F
// F2
// L'
// L2
// U
// B2
// D
// F
// D2
// F
// B2
// F2
// R2
// R'
//
//
// move
// {
//   side = 0;
//   mod = 0;
// }

void	refine(t_move *tab, size_t nb)
{
	int		i;
	int		j;
	size_t	count[2];
	t_side	tmp;
	t_move	ret[nb];

	i = -1;
	j = 0;
	while (tab && ++i < nb)
	{
		tmp = tab[i].side;
		
	}
}
