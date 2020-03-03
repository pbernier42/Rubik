/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:29:24 by pbernier          #+#    #+#             */
/*   Updated: 2020/03/03 19:55:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rubik.h>

size_t	sizet_count_arg(char *argv)
{
	size_t	len;
	size_t	count;

	len = sizet_skip_space(0, argv);
	count = 0;
	while (argv[len])
	{
		if (SHORT_IS_SIDE(argv[len]) == -1)
			return (0);
		if (!argv[++len])
			return (++count);
		if (SHORT_IS_MOD(argv[len]) == -1 && SHORT_IS_SPACE(argv[len]) == -1)
			return (0);
		len = sizet_skip_space(++len, argv);
		++count;
	}
	return (count);
}

size_t	sizet_skip_space(size_t len, char *string)
{
	while (string && SHORT_IS_SPACE(string[len]) != -1)
		++len;
	return (len);
}

short	index_tab_tside(t_side side, t_side *tab_side, short size_tab)
{
	short	i;

	i = -1;
	while (tab_side && ++i < size_tab)
		if (side == tab_side[i])
			return (i);
	return (-1);
}

short	index_tab_tstickers(t_binary bin_cube, t_sticker (*tab_stickers)[3],
			short size_tab)
{
	short 		i;
	t_binary	tmp;

	i = -1;
	tmp = 0;
	while (++i < size_tab)
	{
		tmp = tbin_conv_tstickers(tab_stickers[i]);
		if (tmp == (bin_cube & tmp))
			return (i);
	}
	return (-1);
}

short	index_tab_tbin(t_binary binary, t_binary *tab_binary, short size_tab)
{
	short	i;

	i = -1;
	while (tab_binary && ++i < size_tab)
		if (!(binary ^ tab_binary[i]))
			return (i);
	return (-1);
}

short	index_str(char c, char *string)
{
	short	len;

	len = 0;
	while (string && string[len] && c != string[len])
		++len;
	return ((string[len]) ? len : -1);
}

short	nb_byte_tbin(t_binary binary, short spectrum)
{
	short		i[2];

	I = -1;
	NB_BYTE = 0;
	while (++I < spectrum)
	{
		if (binary & 1)
			NB_BYTE++;
		binary = binary >> 1;
	}
	return (NB_BYTE);
}
