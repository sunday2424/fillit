/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:04:56 by junpark           #+#    #+#             */
/*   Updated: 2019/05/08 09:25:04 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Recursive backtracking
*/

int		fit_valid(t_map *solution, t_tet *blocks)
{
	int			x;
	int			y;
	t_tet		*tetri;

	if (blocks == NULL)
		return (1);
	y = 0;
	tetri = blocks;
	while (y < solution->mapsize - blocks->height + 1)
	{
		x = 0;
		while (x < solution->mapsize - blocks->width + 1)
		{
			if (place(tetri, solution, y, x))
			{
				if (fit_valid(solution, blocks->next))
					return (1);
				else
					set_piece(tetri, solution, point_new(y, x), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Check if placement on given coordinate is available.
*/

int		place(t_tet *tetri, t_map *solution, int y, int x)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->content[j][i] == '#'
				&& solution->maparr[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetri, solution, point_new(y, x), tetri->alpha + 'A');
	return (1);
}

/*
** Place a piece on coordinate if it is available.
*/

void	set_piece(t_tet *tetri, t_map *solution, t_coord *coord, int c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->content[j][i] == '#')
				solution->maparr[coord->y + j][coord->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&coord);
}

t_coord	*point_new(int y, int x)
{
	t_coord		*coord;

	coord = ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

/*
** The beginning of solving part.
*/

t_map	*tet_solve(t_tet *blocks)
{
	int		minsize;
	t_map	*solution;

	minsize = get_min_map(blocks);
	solution = new_map(minsize);
	while (!fit_valid(solution, blocks))
	{
		minsize++;
		tet_mapfree(&solution);
		solution = new_map(minsize);
	}
	return (solution);
}
