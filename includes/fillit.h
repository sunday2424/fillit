/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:30:14 by junpark           #+#    #+#             */
/*   Updated: 2019/04/14 08:27:49 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

# define CBLOCK '#'
# define CEMPTY '.'

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct	s_tetris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_tetris;

void		get_size(char *str, t_position *min, t_position *max);
t_tetris	*ext_tetris(char *str, char value);
int			valid_tetris(char *str);
int			check_map(char *str, int count);
t_list		*read_maplst(int fd);

t_list		*free_list(t_list *list);
void		free_tetris(t_tetris *tetris);
t_tetris	*new_tetris(char **pos, int width, int height, char value);
t_position	*new_position(int x, int y);

void		free_map(t_map *map);
void		print_map(t_map *map);
t_map		*new_map(int size);
int			check_place(t_tetris *tetris, t_map *map, int x, int y);
void		place_piece(t_tetris *tetris, t_map *map, t_position *position, char c);

int			solve_map(t_map *map, t_list *list);
int			high_sqrt(int n);
t_map		*solve(t_list *list);

#endif
