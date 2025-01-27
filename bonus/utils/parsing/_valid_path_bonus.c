/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _valid_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:56:52 by iassil            #+#    #+#             */
/*   Updated: 2024/02/18 20:56:35 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

static void	ft_check__path(t_list **map, int *pos_player, char **_map)
{
	char	**_map2;
	char	**_map3;

	_map2 = ft_get_map(map);
	ft_check_path(&_map, pos_player[0], pos_player[1]);
	if (check_validity(_map) == 1)
		(ft_free_nodes(map), ft_free(&_map), ft_free(&_map2),
			write(2, "Error\n", 6), exit(EXIT_FAILURE));
	ft_check_path_v2(&_map2, pos_player[0], pos_player[1]);
	if (check_validity_v2(_map2) == 1)
		(ft_free_nodes(map), ft_free(&_map), ft_free(&_map2),
			write(2, "Error\n", 6), exit(EXIT_FAILURE));
	_map3 = ft_get_map(map);
	ft_check_path_v3(&_map3, pos_player[0], pos_player[1]);
	if (check_validity_v3(_map3) == 1)
		(ft_free_nodes(map), ft_free(&_map), ft_free(&_map2), ft_free(&_map3),
			write(2, "Error\n", 6), exit(EXIT_FAILURE));
	ft_free(&_map2);
	ft_free(&_map3);
}

void	ft_valid_path(t_list **map)
{
	char	**_map;
	int		*pos_player;
	int		i;

	i = 0;
	_map = ft_get_map(map);
	pos_player = ft_get_coordination(_map);
	if (pos_player[0] == -1 && pos_player[1] == -1)
		(ft_free_nodes(map), ft_free(&_map),
			write(2, "Error\n", 6), exit(EXIT_FAILURE));
	ft_check__path(map, pos_player, _map);
	ft_free(&_map);
}

void	ft_check_path(char ***_map, int x, int y)
{
	if ((*_map)[x][y] == '1' || (*_map)[x][y] == '.'
		|| (*_map)[x][y] == 'E')
		return ;
	(*_map)[x][y] = '.';
	ft_check_path(_map, x + 1, y);
	ft_check_path(_map, x, y + 1);
	ft_check_path(_map, x - 1, y);
	ft_check_path(_map, x, y - 1);
}

int	check_validity(char **_map)
{
	int			i;
	int			j;

	i = 0;
	while (_map[i] != 0)
	{
		j = 0;
		while (_map[i][j] != '\0')
		{
			if (_map[i][j] == 'P' || _map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_get_coordination(char **str)
{
	static int	xy[2];
	int			i;
	int			j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'P')
			{
				xy[0] = i;
				xy[1] = j;
				return (xy);
			}
			j++;
		}
		i++;
	}
	xy[0] = -1;
	xy[1] = -1;
	return (xy);
}
