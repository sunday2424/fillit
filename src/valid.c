/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 01:01:20 by junpark           #+#    #+#             */
/*   Updated: 2019/04/30 10:04:38 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Get max size of valid tetris piece.
*/

void		get_size(char *str, t_position *min, t_position *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

/*
** Extract tetris piece from a valid map.
*/

t_tetris	*ext_tetris(char *str, char value)
{
	int			i;
	char		**pos;
	t_tetris	*tetris;
	t_position	*min;
	t_position	*max;

	min = new_position(3, 3);
	max = new_position(0, 0);
	get_size(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, \
				max->x - min->x + 1);
		i++;
	}
	tetris = new_tetris(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

/*
** Subset of read_malst - check_map function.
** Check if a tetris piece is valid (Check connection).
*/

int			valid_tetris(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	if (block == 6 || block == 8)
		return (1);
	return (0);
}

/*
** Subset of read_maplst function.
** Read a given map as a string and check if it is valid.
*/

int			check_map(char *str, int count)
{
	int	i;
	int	blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!valid_tetris(str))
		return (1);
	return (0);
}

/*
** Read given map(s) and store as a list.
*/

t_list		*read_maplst(int fd)
{
	int			count;
	char		*buff;
	char		alp;
	t_list		*list;
	t_tetris	*tetris;

	buff = ft_strnew(21);
	list = NULL;
	alp = 'A';
	while ((count = read(fd, buff, 21)) >= 0)
	{
		if (check_map(buff, count) != 0 || \
				(tetris = ext_tetris(buff, alp++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buff);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
