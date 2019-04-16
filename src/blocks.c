/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:41:00 by junpark           #+#    #+#             */
/*   Updated: 2019/04/15 17:11:14 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetris(t_tetris *tetris)
{
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetris->pos)));
	ft_memdel((void **)&tetris);
}

t_tetris	*new_tetris(char **pos, int width, int height, char value)
{
	t_tetris	*tetris;

	tetris = ft_memalloc(sizeof(t_tetris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_position	*new_position(int x, int y)
{
	t_position	*position;

	position = ft_memalloc(sizeof(t_position));
	position->x = x;
	position->y = y;
	return (position);
}
