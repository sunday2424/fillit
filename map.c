/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:22:15 by junpark           #+#    #+#             */
/*   Updated: 2019/05/08 09:35:11 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** A function to get a width/length of a square (sqrt)
*/

int		get_min_map(t_tet *tetlist)
{
	t_tet	*tmplst;
	int		numoftet;
	int		i;

	i = 2;
	tmplst = tetlist;
	while (tmplst->next)
		tmplst = tmplst->next;
	numoftet = (tmplst->alpha) + 1;
	while ((i * i) < (numoftet * 4))
		i++;
	return (i);
}

/*
** Allocate memory for a new empty map.
*/

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->maparr = (char **)tet_memalloc((size_t)size, (size_t)size);
	if (!(map->maparr))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(map->maparr)[i][j] = '.';
			j++;
		}
		(map->maparr)[i][j] = '\0';
		i++;
	}
	(map->maparr)[i] = "\0";
	map->mapsize = size;
	return (map);
}

void	tet_mapfree(t_map **alst)
{
	t_map *tmp;

	if (!(*alst) || !alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
}

void	map_print(t_map **finalmap, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		ft_putstr(((*finalmap)->maparr)[j]);
		ft_putchar('\n');
		j++;
	}
}
