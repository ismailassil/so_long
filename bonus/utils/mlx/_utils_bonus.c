/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:24:18 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:50 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

int	ft_is_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'N')
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
		(write(2, "Error: Allocation failed for map.\n", 34),
			ft_free_nodes(map), exit(EXIT_FAILURE));
	while (head != NULL)
	{
		_map[i] = ft_substr(head->data, 0, ft_strlen(head->data));
		if (!_map[i])
			(write(2, "Error: Allocation failed for map.\n", 34),
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

int	ft_last_row(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		i++;
	return (i - 1);
}

int	ft_escape(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_free(&data->map);
	ft_free_nodes(data->_node_map);
	exit(EXIT_SUCCESS);
	return (0);
}
