/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:02:33 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:24:53 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

int	ft_listlen(t_list **map)
{
	t_list	*head;
	int		count;

	count = 0;
	head = *map;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_list	*ft_lstnew(char *data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *_new)
{
	t_list	*ptr;

	if (_new == NULL)
		exit(EXIT_FAILURE);
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = _new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = _new;
}

void	ft_free(char ***str)
{
	int	i;

	i = -1;
	while ((*str)[++i] != 0)
		free((*str)[i]);
	free(*str);
	*str = NULL;
}

void	ft_free_nodes(t_list **map)
{
	t_list	*head;
	t_list	*tobefreed;

	head = *map;
	while (head != NULL)
	{
		tobefreed = head;
		head = head->next;
		free(tobefreed->data);
		tobefreed->data = NULL;
		free(tobefreed);
		tobefreed = NULL;
	}
}
