/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:30:14 by junpark           #+#    #+#             */
/*   Updated: 2019/05/21 04:47:03 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
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

typedef struct		s_tet
{
	char			**str;
	int				width;
	int				height;
	char			alpha;
	struct s_tet	*next;
}					t_tet;

t_tet				*handle_input(char *file);
t_tet				*valid_input(int ns, char *str);
t_tet				*save_if_valid(int num, char **array);
int					ctbks(char **map);
int					ccon(char **map);

int					top(char **map);
int					bottom(char **map);
int					right(char **map);
int					left(char **map);
char				**trim(char **map);

t_map				*new_map(int size);
void				free_map(t_map *map);
t_tet				*new_tetris(char **str, int width, int height, char value);
void				free_tetris(t_tet *tetris);
t_position			*new_position(int x, int y);

size_t				tet_lstcount(t_tet *list);
void				tet_lstprev(t_tet **alst);
t_tet				*start_list(int num, char ***str);
void				add_to_list(t_tet *alst, t_tet *new_list);

int					check_place(int i, int j, t_tet *tetris, t_map *map);
void				put_piece(t_tet *tetris, t_map *map, t_position *position, char c);
int					rec_backtrack(t_map *map, t_tet *tetlst);
t_map				*solve(t_tet *tetlst);
int					ft_sqrt(t_tet *tetlst);

void				print_error(void);
void				print_map(t_map *map);

#endif
