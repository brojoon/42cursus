/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:17:49 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 18:18:31 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	t_list *curr;

	next = *lst;
	while (next)
	{
		curr = next;
		next = curr->next;
		ft_lstdelone(curr, del);
	}
	*lst = NULL;
}
