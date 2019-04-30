/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:59:55 by junpark           #+#    #+#             */
/*   Updated: 2019/04/30 10:43:29 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** list functions that are used but these were not
** required functions from libft.
*/

size_t	ft_lstcount(t_list *lst)
{
	size_t i;

	i = 0;
	while (lst != NULL)
	{
		lst	= lst->next;
		i++;
	}
	return (i);
}

void	ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

/*
** subset function of read_maplst.
*/

t_list	*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

char	**tet_memalloc(size_t y, size_t x)
{
	char	**ptr;
	size_t	i;

	i = 0;
	ptr = (char**)malloc(sizeof(char *) * (y + 1));
	if (!ptr)
		return (0);
	while (i < y + 1)
	{
		ptr[i] = (char *)malloc(sizeof(char) * x + 1);
		if (!ptr[i])
			return (0);
		ft_memset(ptr[i], 0, (sizeof(char) * x + 1));
		i++;
	}
	return (ptr);
}
