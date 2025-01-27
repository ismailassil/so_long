/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:24:18 by iassil            #+#    #+#             */
/*   Updated: 2024/02/20 10:19:15 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

int	ft_is_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

char	**ft_get_map(t_list **map)
{
	t_list	*head;
	char	**_map;
	int		i;

	i = 0;
	head = *map;
	_map = (char **)malloc((ft_listlen(map) + 1) * sizeof(char **));
	if (!map)
		(ft_print(2, "Error: Allocation failed for map\n"),
			ft_free_nodes(map), exit(EXIT_FAILURE));
	while (head != NULL)
	{
		_map[i] = ft_substr(head->data, 0, ft_strlen(head->data));
		if (!_map[i])
			(ft_print(2, "Error: Allocation failed for map\n"),
				ft_free_nodes(map), exit(EXIT_FAILURE));
		head = head->next;
		i++;
	}
	_map[i] = 0;
	return (_map);
}

void	ft_get_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_exit_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_last_row(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		i++;
	return (i - 1);
}
