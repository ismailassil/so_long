/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:38:19 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:38 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

void	ft_check_exit(t_data *data, char c)
{
	t_direction	p;

	p.x = 0;
	p.y = 0;
	ft_get_player_position(data->map, &p.x, &p.y);
	if (ft_check_coin_for_exit(data) == true)
	{
		if (c == 'u' && data->map[p.x - 1][p.y] == 'E')
			(ft_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'd' && data->map[p.x + 1][p.y] == 'E')
			(ft_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'l' && data->map[p.x][p.y - 1] == 'E')
			(ft_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'r' && data->map[p.x][p.y + 1] == 'E')
			(ft_exit(data), exit(EXIT_SUCCESS));
	}
}

void	ft_check_enemy(t_data *dt, char c)
{
	t_direction	p;
	t_tex		dd;
	char		*m1;
	char		*m2;

	p.x = 0;
	p.y = 0;
	m1 = "-------------------\n";
	m2 = "GAME OVER!!\n-------------------\n";
	ft_get_player_position(dt->map, &p.x, &p.y);
	dd.x = p.y;
	dd.y = p.x;
	if (c == 'u' && dt->map[p.x - 1][p.y] == 'N')
		(ft_pstr(m1), ft_pstr(m2), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
	else if (c == 'd' && dt->map[p.x + 1][p.y] == 'N')
		(ft_pstr(m1), ft_pstr(m2), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
	else if (c == 'l' && dt->map[p.x][p.y - 1] == 'N')
		(ft_pstr(m1), ft_pstr(m2), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
	else if (c == 'r' && dt->map[p.x][p.y + 1] == 'N')
		(ft_pstr(m1), ft_pstr(m2), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
}

bool	ft_check_coin_for_exit(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (true);
	return (false);
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

void	ft_check_coin(t_data *dt, t_direction d)
{
	int		i;
	int		j;
	int		count;
	t_tex	dd;

	i = 0;
	count = 0;
	while (dt->map[i] != 0)
	{
		j = 0;
		while (dt->map[i][j] != '\0')
		{
			if (dt->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
	{
		ft_get_exit_position(dt->map, &d.x, &d.y);
		dd.x = d.y * 64;
		dd.y = d.x * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[8], dd.x, dd.y);
	}
}
