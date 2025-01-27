/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:00:23 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 03:01:47 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		size_start;
	int		_start;

	_start = start;
	if (s == NULL)
		return (NULL);
	if (_start > ft_strlen(s))
		return (ft_strdup(""));
	size_start = ft_strlen(s + _start);
	if (size_start < (int)len)
		len = size_start;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s + _start, len + 1);
	return (ptr);
}

char	*ft_strtrim(char **s1, char *set)
{
	size_t	s1_size;
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_size = ft_strlen((*s1));
	end = s1_size - 1;
	while (start < s1_size && ft_strchr(set, (*s1)[start]))
		start++;
	while (end > 0 && ft_strchr(set, (*s1)[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	else
		end = end - start + 1;
	ptr = ft_substr((*s1), start, end);
	if (ptr == NULL)
		return (NULL);
	free(*s1);
	return (ptr);
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
