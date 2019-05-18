/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:30:14 by junpark           #+#    #+#             */
/*   Updated: 2019/05/07 22:03:44 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 545

typedef struct		s_map
{
	int				size;
	char			**array;
	struct s_map	*next;
}					t_map;

typedef struct		s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct		s_tetris
{
	char			**str;
	int				width;
	int				height;
	char			value;
	struct s_tetris	*next;
}					t_tet;

/*
void				get_size(char *str, t_ition *min, t_position *max);
t_tetris			*ext_tetris(char *str, char value);
int					valid_tetris(char *str);
int					check_map(char *str, int count);
t_list				*read_maplst(int fd);

void				free_tetris(t_tetris *tetris);
t_tetris			*new_tetris(char **pos, int width, int height, char value);
t_position			*new_position(int x, int y);

void				free_map(t_map *map);
void				print_map(t_map *map);
t_map				*new_map(int size);
int					get_min_map(int n);

int					check_place(t_tetris *tetris, t_map *map, int x, int y);
void				place_piece(t_tetris *tetris, t_map *map, \
					t_position *position, char c);
int					solve_map(t_map *map, t_list *list);
t_map				*solve(t_list *list);

size_t				ft_lstcount(t_list *lst);
void				ft_lstrev(t_list **alst);
t_list				*free_list(t_list *list);
*/
#endif
