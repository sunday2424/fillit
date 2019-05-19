/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:59:55 by junpark           #+#    #+#             */
/*   Updated: 2019/05/19 04:29:51 by atropnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** list functions that are used but these were not
** required functions from libft.
*/

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
	int			i;
	char		alpha;

	i = 0;
	alpha = 'A';
	while (i < num)
	{
		if (alpha == 'A')
		{
			new_list = new_tetris(trim(str[i]), (right(str[i]) - left(str[i])), \
						(bottom(str[i]) - top(str[i])), alpha);
			curr = new_list;
		}
		else
		{
			curr->next = new_tetris(trim(str[i]), \
					(right(str[i]) - left(str[i])), \
						(bottom(str[i]) - top(str[i])), alpha);
			curr = curr->next;
		}
		i++;
		alpha++;
	}
	curr->next = NULL;
	return (new_list);
}
