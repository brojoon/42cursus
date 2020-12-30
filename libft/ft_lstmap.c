/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 05:14:58 by hyungjki          #+#    #+#             */
/*   Updated: 2020/12/31 05:05:28 by hyungjki         ###   ########.fr       */
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
	while (cur)
	{
		if (!(node = ft_lstnew((*f)(cur->content))))
			break ;
		ft_lstadd_back(&result, node);
		cur = cur->next;
	}
	if (ft_lstsize(lst) != ft_lstsize(result))
		ft_lstclear(&result, del);
	return (result);
}
