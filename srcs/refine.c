/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:51:47 by rlecart           #+#    #+#             */
/*   Updated: 2020/01/22 21:07:02 by rlecart          ###   ########.fr       */
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
// ((FFFFFFF % 4) == 0) = "" : side = side_null + mod = mod_null
//             || == 1 = "F" : mod = mod_null
//             || == 2 = "F2" : mod = mod_twice
//             || == 3 = "'" : mod = mod_reverse
//
// nb = 18
//
// quand je le rempli que je stash
//
// F'
// B'
// R2
// F'
// L
// U
// B2
// D
// F
// D2
// F'
// B2
// R
//
// F 2
// B 3
//
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
// ((FFFFFFF % 4) == 0) = "" : side = side_null + mod = mod_null
//             || == 1 = "F" : mod = mod_null
//             || == 2 = "F2" : mod = mod_twice
//             || == 3 = "'" : mod = mod_reverse
//
// F'
// B'
// R2
// F'
// L
// U

void	print_ins(t_move *tab, size_t nb)
{
	size_t	i;

	i = -1;
	while (++i < nb)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = { ");
		ft_putnbr(tab[i].side);
		ft_putstr(", ");
		ft_putnbr(tab[i].mod);
		ft_putstr(" }\n");
		//printf("tab[%lu] = { %d, %d }\n", i, tab[i].side, tab[i].mod);
	}
}

t_move	stash_ins(t_move *tmp, size_t *count, size_t *j)
{
	size_t	ctmp;
	t_move	ret;

	ctmp = *count % 4;
	ret.side = tmp->side;
	if (ctmp == 0) // a cause de ca le cas "F" ou "FFFF" n'est pas discerne
	{
		ret.side = side_null;
		ret.mod = mod_null;
		tmp->side = side_null;
		tmp->mod = mod_null;
		*count = 0;
	}
	else if (ctmp == 1)
	{
		ret.mod = mod_null;
		(*j)++;
	}
	else if (ctmp == 2)
	{
		ret.mod = mod_twice;
		(*j)++;
	}
	else
	{
		tmp->mod = mod_reverse;
		(*j)++;
	}
	printf("{ %d, %d }\n", ret.side, ret.mod);
	return (ret);
}

void	refine(t_move *tab, size_t nb)
{
	size_t	i;
	size_t	j;
	int		sw;
	size_t	count[2];
	t_move	tmp[2];
	t_move	ret[nb];

	i = 0;
	j = 0;
	sw = 0;
	tmp[0].side = side_null;
	tmp[1].side = side_null;
	count[0] = 0;
	count[1] = 0;
	while (tab && i < nb)
	{
		if (i > 0)
		{
			if (i < nb && !(tmp[sw].side - tab[i].side) % 3)
				sw = (sw + 1) % 2;
			else
			{
				ret[j] = stash_ins(&tmp[sw], &count[sw], &j);
				sw = (sw + 1) % 2;
				if (tmp[sw].side == side_null)
					ret[j] = stash_ins(&tmp[sw], &count[sw], &j);
				if (i == nb)
					break ;
			}
		}
		if (tmp[sw].side == side_null)
			tmp[sw] = tab[i];
		count[sw] += tab[i].mod + 2;
		i++;
	}
	print_ins(ret, j);
	//while (1);
	//printf("");
}
