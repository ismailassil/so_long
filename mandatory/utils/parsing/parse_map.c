/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:19:15 by iassil            #+#    #+#             */
/*   Updated: 2024/02/20 10:33:37 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

void	ft_parse_map(int fd, t_list **map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		(close(fd), ft_print(2, "Error: file is empty.\n"), exit(EXIT_FAILURE));
	ft_lstadd_back(map, ft_lstnew(line));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(map, ft_lstnew(line));
		i++;
	}
	close(fd);
	ft_check_if_rectangle(map);
	ft_check_char(map);
	ft_check_walls(map);
	ft_valid_path(map);
}

void	ft_check_if_rectangle(t_list **map)
{
	t_list	*head;
	char	*ptr;
	int		i;

	i = 0;
	head = *map;
	while (head->next != NULL)
		head = head->next;
	while (head->data[i] != '\0')
	{
		if (head->data[i] == '\n')
			(ft_free_nodes(map), ft_print(2, "Error\n"),
				exit(EXIT_FAILURE));
		i++;
	}
	head = *map;
	while (head != NULL)
	{
		ptr = ft_strtrim(&(head->data), "\n");
		if (ptr[0] == '\0')
			(ft_free_nodes(map), ft_print(2, "Error\n"),
				exit(EXIT_FAILURE));
		head->data = ptr;
		head = head->next;
	}
}

t_cp	ft_count_components(t_list **map)
{
	int		i;
	t_list	*head;
	t_cp	count;

	head = *map;
	count.e = 0;
	count.c = 0;
	count.p = 0;
	while (head != NULL)
	{
		i = 0;
		while (head->data[i] != '\0')
		{
			if (head->data[i] == 'E')
				count.e++;
			if (head->data[i] == 'C')
				count.c++;
			if (head->data[i] == 'P')
				count.p++;
			i++;
		}
		head = head->next;
	}
	return (count);
}

void	ft_check_char(t_list **map)
{
	t_list	*head;
	t_count	count;
	int		i;

	head = *map;
	count.prev = ft_strlen(head->data);
	while (head != NULL)
	{
		i = 0;
		count.current = 0;
		if (head->data[0] == '\0')
			(ft_free_nodes(map), ft_print(2, "Error\n"),
				exit(EXIT_FAILURE));
		while (ft_is_character(head->data[i]) == 1)
		{
			i++;
			count.current++;
		}
		if (head->data[i] != '\0' || count.prev != count.current)
			(ft_free_nodes(map), ft_print(2, "Error\n"),
				exit(EXIT_FAILURE));
		count.prev = count.current;
		head = head->next;
	}
}

void	ft_check_walls(t_list **map)
{
	t_list	*head;
	t_cp	count;
	int		i;

	i = 0;
	head = *map;
	while (head->data[i] == '1')
		i++;
	if (head->data[i] != '\0')
		(ft_free_nodes(map), ft_print(2, "Error\n"), exit(EXIT_FAILURE));
	i = 0;
	while (head->next != NULL)
	{
		if (head->data[0] != '1'
			|| head->data[ft_strlen(head->data) - 1] != '1')
			(ft_free_nodes(map), ft_print(2, "Error\n"), exit(EXIT_FAILURE));
		head = head->next;
	}
	while (head->data[i] == '1')
		i++;
	if (head->data[i] != '\0')
		(ft_free_nodes(map), ft_print(2, "Error\n"), exit(EXIT_FAILURE));
	count = ft_count_components(map);
	if (count.e != 1 || count.c < 1 || count.p != 1)
		(ft_free_nodes(map), ft_print(2, "Error\n"), exit(EXIT_FAILURE));
}
