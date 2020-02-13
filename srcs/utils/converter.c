/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:22:17 by pbernier          #+#    #+#             */
/*   Updated: 2020/02/05 22:24:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>

t_binary	tbin_conv_tstickers(t_sticker bloc[3])
{
	t_binary	binary;
	t_side		side;
	short		i;

	side = side_front;
	binary = 0;
	while (side != side_null)
	{
		if ((i = index_tab_tside(side,
			((t_side[3]){bloc[0].side, bloc[1].side, bloc[2].side}), 3)) != -1)
		{
			binary = binary << (((bloc[i].COO_Y * 3) + bloc[i].COO_X) + 1);
		 	binary += 1;
		 	binary = binary << (9 - (((bloc[i].COO_Y * 3) + bloc[i].COO_X) + 1));
		}
		else
			binary = binary << 9;
		++side;
	}
	return (binary);
};

t_binary	tbin_conv_tsides(char ***cube, t_side side[3])
{
	t_side		side_len;
	short		side_select;
	t_binary	binary;

	side_len = side_front;
	binary = 0;
	while (side_len != side_null)
	{
		binary = binary << 9;
		side_select = -1;
		while (++side_select < 3)
			binary += tbin_conv_char(cube[side_len], side[side_select]);
		++side_len;
	}
	return (binary);
}


t_binary	tbin_conv_char(char **cube_side, t_side side)
{
	short		coo[2];
	t_binary	binary;

	COO_Y = -1;
	binary = 0;
	while (side != side_null && ++COO_Y != 3)
	{
		COO_X = -1;
		while (++COO_X != 3)
		{
			binary = binary << 1;
			if (cube_side[COO_Y][COO_X] == STR_INITIALS_SIDE[side])
				++binary;
		}
	}
	return (binary);
}

t_binary	tbin_conv_tab_tsides(t_side *side, short nb_side, t_binary binary)
{
	short		i;
	t_binary	ret;

	i = -1;
	ret = 0;
	while (++i < nb_side)
	{
		ret = ret << 9;
		ret += (side[i] != side_null ? (binary >> (9 * (5 - side[i])) & 511) : 0);
	}
	return (ret);
}

void	tab_tmove_conv_str(t_move *dst, int nb_move, char *str)
{
	size_t		len;
	int			count;

	len = sizet_skip_space(0, str);
	count = 0;
	while (count < nb_move)
	{
		dst[count++] = tmove_conv_char((char[2]){str[len], str[len + 1]});
		len += 2;
		len = sizet_skip_space(len, str);
	}
}

t_move	tmove_conv_char(char arg[2])
{
	t_move	ret;

	ret.side = side_front;
	while (ret.side != side_null && arg[0] != STR_INITIALS_SIDE[ret.side])
		++ret.side;
	if (!arg[1] || SHORT_IS_SPACE(arg[1]) != -1)
		return ((t_move){ret.side, mod_null});
	ret.mod = mod_twice;
	while (ret.mod != mod_null && arg[1] != STR_INITIALS_MOD[ret.mod])
		++ret.mod;
	return (ret);
}

void	tab_tmove_adjust_group(t_move *moves, size_t nb_move,
			t_side side_reference, short rotate)
{
	size_t	i;

	i = -1;
	while (++i < nb_move)
		moves[i].side = ((t_side[6]){
			side_reference,
			TSIDE_AROUND(TAROUND_ROTATE(around_right, rotate), side_reference),
			TSIDE_AROUND(TAROUND_ROTATE(around_up, rotate), side_reference),
			(side_reference + 3) % 6,
			TSIDE_AROUND(TAROUND_ROTATE(around_left, rotate), side_reference),
			TSIDE_AROUND(TAROUND_ROTATE(around_down, rotate), side_reference)
			})[moves[i].side];
}

























//
