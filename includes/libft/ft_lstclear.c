/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:22:04 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:22:06 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

/*

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp; // Creation d'une variable temporaire 
	pour ne pas perdre le pointeur origin

	while (*lst)   (|| *lst != NULL )
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

*/