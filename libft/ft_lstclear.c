/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:13:18 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/02 18:03:17 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	next = *lst;
	while (cur)
	{
		cur = next;
		next = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
