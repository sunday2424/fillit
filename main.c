/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:56:28 by junpark           #+#    #+#             */
/*   Updated: 2019/05/17 22:13:50 by atropnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

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

int		main(int ac, char **av)
{
	t_tet	*list;
	t_map	*map;

	if (ac == 2)
	{
		if (list = handle_input(av[1]) == NULL)
		{
			print_error();
			return (1);
		}
		map = solve(list);
		print_map(map);
		free_map(map);
		free_list(list);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	return (0);
}
