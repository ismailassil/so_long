/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:25:11 by iassil            #+#    #+#             */
/*   Updated: 2024/02/18 20:54:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

void	ft_check_path_v2(char ***_map, int x, int y)
{
	if ((*_map)[x][y] == '1' || (*_map)[x][y] == '.')
		return ;
	(*_map)[x][y] = '.';
	ft_check_path_v2(_map, x + 1, y);
	ft_check_path_v2(_map, x, y + 1);
	ft_check_path_v2(_map, x - 1, y);
	ft_check_path_v2(_map, x, y - 1);
}

int	check_validity_v2(char **_map)
{
	int			i;
	int			j;

	i = 0;
	while (_map[i] != 0)
	{
		j = 0;
		while (_map[i][j] != '\0')
		{
			if (_map[i][j] == 'P' || _map[i][j] == 'C' || _map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
