/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:59:55 by junpark           #+#    #+#             */
/*   Updated: 2019/05/20 21:53:23 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	tet_lstcount(t_tet *list)
{
    size_t i;
    
    i = 0;
    while (list != NULL)
    {
        list = list->next;
        i++;
    }
    return (i);
}

void    tet_lstprev(t_tet **alst)
{
    t_tet    *prev;
    t_tet    *cur;
    t_tet    *next;
    
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

t_tet	*start_list(int num, char ***str)
{
	t_tet		*new_list;
	t_tet		*curr;
	int			w;
	int			h;
	int			i;
	char		alpha;

	i = -1;
	alpha = 'A';
	while (++i < (num / 4))
	{
		w = right(str[i]) - left(str[i]) + 1;
		h = bottom(str[i]) - top(str[i]) + 1;
		if (alpha == 'A')
		{
			new_list = new_tetris(trim(str[i]), w, h, alpha);
			curr = new_list;
		}
		else
		{
			curr->next = new_tetris(trim(str[i]), w, h, alpha);
			curr = curr->next;
		}
		alpha++;
	}
	curr->next = NULL;
	return (new_list);
}
