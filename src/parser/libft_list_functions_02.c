/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list_functions_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:18:38 by elraira-          #+#    #+#             */
/*   Updated: 2022/05/19 20:19:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns the last node of the list.
 *
 * @param lst  The beginning of the list.

 * @return t_list* Last node of the list

 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/**
 * @brief Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.

 *
 * @param lst  The address of a pointer to a node.
 * @param f The address of the function used to iterate on
	the list.
 * @param del The address of the function used to delete
	the content of a node if needed.
 * @return t_list* The new list.
	NULL if the allocation fails.

 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
			ft_lstclear(&tmp, del);
		lst = lst->next;
		ft_lstadd_back(&new, tmp);
	}
	return (new);
}

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.
 *
 * @param content The content to create the node with.

 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_tlist;

	new_tlist = (t_list *)malloc(sizeof(t_list));
	if (new_tlist)
	{
		new_tlist->next = NULL;
		new_tlist->content = content;
	}
	return (new_tlist);
}

/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.

 * @return int The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 1;
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
