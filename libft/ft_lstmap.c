/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:14:58 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/01 18:15:53 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*cur;
	t_list	*node;

	result = NULL;
	cur = lst;
	if (lst == NULL || (result = ft_lstnew(f(lst->content))) == NULL)
		return (0);
	cur = result;
	node = lst->next;
	while (node)
	{
		if ((cur->next = ft_lstnew(f(node->content))) == NULL)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		cur = cur->next;
		node = node->next;
	}
	return (result);
}
