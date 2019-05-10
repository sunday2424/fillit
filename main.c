/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:56:28 by junpark           #+#    #+#             */
/*   Updated: 2019/05/07 16:21:29 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void print_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((list = valid_input(open(av[1], O_RDONLY))) == NULL)
	{
        print_error();
		return (0);
	}
	map = solve(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
