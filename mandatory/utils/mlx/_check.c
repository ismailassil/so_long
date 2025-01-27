/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:30:52 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:28:33 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

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
		mlx_put_image_to_window(dt->mlx, dt->window, dt->pic[7], dd.x, dd.y);
	}
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

static void	ft_before_exit(t_data *data)
{
	char	*m1;
	char	*m2;

	m1 = "-------------------\nCongratulations.\nYou Found all the Coins.\n";
	m2 = "You Won\n-------------------\n";
	ft_print_move();
	ft_print(1, m1);
	ft_print(1, m2);
	ft_free(&data->map);
	ft_free_nodes(data->_node_map);
	free(data->mlx);
}

void	ft_check_exit(t_data *data, char c)
{
	t_direction	p;

	p.x = 0;
	p.y = 0;
	ft_get_player_position(data->map, &p.x, &p.y);
	if (ft_check_coin_for_exit(data) == true)
	{
		if (c == 'u' && data->map[p.x - 1][p.y] == 'E')
			(ft_before_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'd' && data->map[p.x + 1][p.y] == 'E')
			(ft_before_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'l' && data->map[p.x][p.y - 1] == 'E')
			(ft_before_exit(data), exit(EXIT_SUCCESS));
		else if (c == 'r' && data->map[p.x][p.y + 1] == 'E')
			(ft_before_exit(data), exit(EXIT_SUCCESS));
	}
}
