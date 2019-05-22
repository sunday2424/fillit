/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:56:28 by junpark           #+#    #+#             */
/*   Updated: 2019/05/21 04:48:52 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
#include <stdio.h>
void	print_lst(t_tet *list)
{
	int x;

	x = 0;
	printf("%d height\n", list->height);
	printf("%d width\n", list->width);
	while(list->str[x] != NULL)
	{
		ft_putstr(list->str[x]);
		ft_putchar('\n');
		x++;
	}
	ft_putchar('\n');
	if(list->next != NULL)
		print_lst(list->next);
}
*/

int		main(int ac, char **av)
{
	t_tet	*list;
	t_map	*map;

	if (ac == 2)
	{
		list = handle_input(av[1]);
		if (list == NULL)
		{
			print_error();
			return (0);
		}
//		print_lst(list);
		map = solve(list);
		print_map(map);
		free_map(map);
		free_tetris(list);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	return (0);
}
