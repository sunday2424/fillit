/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 08:59:55 by junpark           #+#    #+#             */
/*   Updated: 2019/05/07 23:50:56 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** list functions that are used but these were not
** required functions from libft.
*/

size_t    tet_lstcount(t_tet *list)
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

t_tet	*start_list(int num)
{
	t_tet		*new_list;
	char		**tet;

	if (!(new_list = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	if (!(tet = (char **)malloc(sizeof(char *) * num + 1)))
		return (NULL);
	new_list->str = tet;
	new_list->width = 0;
	new_list->height = 0;
	new_list->value = 'A';
	new_list->next = NULL;
	return (new_list);
}

void	add_to_list(t_tet **alst, t_tet *new)
{
	if (new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}