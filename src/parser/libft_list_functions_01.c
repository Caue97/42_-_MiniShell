/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list_functions_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:12:57 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/19 20:22:03 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Adds the node ’new’ at the end of the list.
 *
 * @param lst  The address of a pointer to the first link of
	a list.
 * @param new  The address of a pointer to the node to be
	added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_list = ft_lstlast(*lst);
	last_list->next = new;
}

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 *
 * @param lst  The address of a pointer to the first link of
	a list.
 * @param new  The address of a pointer to the node to be
	added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/**
 * @brief Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
	the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		lst_tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_tmp;
	}
	*lst = NULL;
}

/**
 * @brief Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete
	the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/**
 * @brief Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
 *
 * @param lst  The address of a pointer to a node.
 * @param f The address of the function used to iterate on
the list.

 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}
