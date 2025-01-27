/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _render_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:51:02 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:46 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

void	ft_render(t_data *data, t_direction d, char c)
{
	if (c == 'u')
	{
		(ft_check_exit(data, 'u'), ft_check_enemy(data, 'u'));
		ft_norme_render_map_image(data, d, 'u');
		ft_check_coin(data, d);
	}
	else if (c == 'l')
	{
		(ft_check_exit(data, 'l'), ft_check_enemy(data, 'l'));
		ft_norme_render_map_image(data, d, 'l');
		ft_check_coin(data, d);
	}
	else if (c == 'r')
	{
		(ft_check_exit(data, 'r'), ft_check_enemy(data, 'r'));
		ft_norme_render_map_image(data, d, 'r');
		ft_check_coin(data, d);
	}
	else if (c == 'd')
	{
		(ft_check_exit(data, 'd'), ft_check_enemy(data, 'd'));
		ft_norme_render_map_image(data, d, 'd');
		ft_check_coin(data, d);
	}
}

void	ft_norme_render_map_image(t_data *dt, t_direction d, char c)
{
	t_tex	dd;

	if (c == 'u' && ft_render_map(dt, 'u', d.x, d.y) == true)
	{
		dd.x = d.y * 64;
		dd.y = d.x * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		ft_print_move(dt);
	}
	else if (c == 'l' && ft_render_map(dt, 'l', d.x, d.y) == true)
	{
		dd.x = d.y * 64;
		dd.y = d.x * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		ft_print_move(dt);
	}
	else
		ft_norme__p2(dt, d, c);
}

void	ft_norme__p2(t_data *dt, t_direction d, char c)
{
	t_tex	dd;

	if (c == 'r' && ft_render_map(dt, 'r', d.x, d.y) == true)
	{
		dd.x = d.y * 64;
		dd.y = d.x * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		ft_print_move(dt);
	}
	else if (c == 'd' && ft_render_map(dt, 'd', d.x, d.y) == true)
	{
		dd.x = d.y * 64;
		dd.y = d.x * 64;
		mlx_put_image_to_window(dt->mlx, dt->window, dt->txt[0], dd.x, dd.y);
		ft_print_move(dt);
	}
}

bool	ft_render_map(t_data *d, char c, int x, int y)
{
	if (c == 'u' && d->map[x - 1][y] != '1' && d->map[x - 1][y] != 'E')
	{
		d->map[x][y] = '0';
		d->map[x - 1][y] = 'P';
		return (true);
	}
	else if (c == 'd' && d->map[x + 1][y] != '1' && d->map[x + 1][y] != 'E')
	{
		d->map[x][y] = '0';
		d->map[x + 1][y] = 'P';
		return (true);
	}
	else if (c == 'r' && d->map[x][y + 1] != '1' && d->map[x][y + 1] != 'E')
	{
		d->map[x][y] = '0';
		d->map[x][y + 1] = 'P';
		return (true);
	}
	else if (c == 'l' && d->map[x][y - 1] != '1' && d->map[x][y - 1] != 'E')
	{
		d->map[x][y] = '0';
		d->map[x][y - 1] = 'P';
		return (true);
	}
	return (false);
}

void	ft_render_image(t_data data, void **texture, char *img)
{
	*texture = mlx_xpm_file_to_image(data.mlx, img, &(int){64}, &(int){64});
	if (*texture == NULL)
	{
		write(2, "Error: Image is not initialized.\n", 33);
		exit(EXIT_FAILURE);
	}
}
