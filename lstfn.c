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

