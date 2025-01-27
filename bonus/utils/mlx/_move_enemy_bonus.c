/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _move_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:45 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:45 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

void	ft_move_enemy(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i] != 0)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N')
				ft_render_the_move(data, &i, &j);
			j++;
		}
		i++;
	}
}

void	ft_render_the_move(t_data *data, int *i, int *j)
{
	static int	nbr_of_moves[21];

	if (nbr_of_moves[*i] == 0)
		ft_move_right(data, i, j, &nbr_of_moves[*i]);
	else if (nbr_of_moves[*i] == 1)
		ft_move_left(data, i, j, &nbr_of_moves[*i]);
}

void	ft_move_right(t_data *dt, int *i, int *j, int *c)
{
	t_tex	dd;
	char	*m[2];

	m[0] = "-------------------\n";
	m[1] = "GAME OVER!!\n-------------------\n";
	if (dt->map[*i][*j + 1] == 'P')
		(ft_pstr(m[0]), ft_pstr(m[1]), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
	if (dt->map[*i][*j + 1] != '1' && dt->map[*i][*j + 1] != 'N'
		&& dt->map[*i][*j + 1] != 'E' && dt->map[*i][*j + 1] != 'C')
	{
		dt->map[*i][*j] = '0';
		dd.x = *j * 64;
		dd.y = *i * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		dt->map[*i][*j + 1] = 'N';
		(*j)++;
	}
	else
		(*c) = 1;
}

void	ft_move_left(t_data *dt, int *i, int *j, int *c)
{
	t_tex	dd;
	char	*m[2];

	m[0] = "-------------------\n";
	m[1] = "GAME OVER!!\n-------------------\n";
	if (dt->map[*i][*j - 1] == 'P')
		(ft_pstr(m[0]), ft_pstr(m[1]), ft_free(&dt->map),
			ft_free_nodes(dt->_node_map), exit(1));
	if (dt->map[*i][*j - 1] != '1' && dt->map[*i][*j - 1] != 'N'
		&& dt->map[*i][*j - 1] != 'E' && dt->map[*i][*j - 1] != 'C')
	{
		dt->map[*i][*j] = '0';
		dd.x = *j * 64;
		dd.y = *i * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		dt->map[*i][*j - 1] = 'N';
		(*j)++;
	}
	else
		(*c) = 0;
}
