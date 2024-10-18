/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:55 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

/*

CE CODE N'EST PAS VALABLE AVEC UN TESTEUR QUI N'ALLOUE PAS DE MEMOIRE POUR NEW;;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		//// new->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		//// new->next = NULL; 
	}
}

#CODE VALABLE , VERIF REALISER, 
#NEXT->NULL N'EST PAS PRECISER ET EST SUPPOSER REALISEE

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last // Variable temp pour ne pas perdre le pointeur;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
*/