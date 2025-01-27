/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _render_next_frame_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:08 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:49 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

void	ft_enemy(t_data *dt, t_tex dd)
{
	static int	k;

	if (k < 10)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[3], dd.x, dd.y);
	else if (k < 20)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[4], dd.x, dd.y);
	else if (k < 30)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[5], dd.x, dd.y);
	else if (k < 40)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[6], dd.x, dd.y);
	if (k == 40)
		(ft_move_enemy(dt), k = 0);
	else
		k++;
}

void	ft_coin(t_data *dt, t_tex dd)
{
	static int	k;

	if (k < 50)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[9], dd.x, dd.y);
	else if (k < 100)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[10], dd.x, dd.y);
	else if (k < 150)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[11], dd.x, dd.y);
	else if (k < 200)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[12], dd.x, dd.y);
	if (k == 200)
		k = 0;
	else
		k++;
}

void	ft_player(t_data *dt, t_tex dd)
{
	static int	k;

	if (k < 10)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[13], dd.x, dd.y);
	else if (k < 20)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[14], dd.x, dd.y);
	else if (k < 30)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[15], dd.x, dd.y);
	else if (k < 30)
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[16], dd.x, dd.y);
	if (k == 30)
		k = 0;
	else
		k++;
}

int	ft_next_frame(void *data_)
{
	t_data	*data;
	t_tex	dd;
	t_cc	c;

	c.i = 0;
	data = (struct s_data *)data_;
	while (data->map[c.i] != 0)
	{
		c.j = 0;
		while (data->map[c.i][c.j] != 0)
		{
			dd.x = c.j * 64;
			dd.y = c.i * 64;
			if (data->map[c.i][c.j] == 'C')
				ft_coin(data, dd);
			else if (data->map[c.i][c.j] == 'N')
				ft_enemy(data, dd);
			else if (data->map[c.i][c.j] == 'P')
				ft_player(data, dd);
			c.j++;
		}
		c.i++;
	}
	return (0);
}
