/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:06:47 by iassil            #+#    #+#             */
/*   Updated: 2024/02/19 10:48:38 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

int	on_keypress(int keysym, t_data *data)
{
	t_direction	d;

	d.x = 0;
	d.y = 0;
	ft_get_player_position(data->map, &d.x, &d.y);
	if (keysym == 53)
		ft_destroy(data);
	else if (keysym == 13 || keysym == 126)
		ft_render(data, d, 'u');
	else if (keysym == 0 || keysym == 123)
		ft_render(data, d, 'l');
	else if (keysym == 2 || keysym == 124)
		ft_render(data, d, 'r');
	else if (keysym == 1 || keysym == 125)
		ft_render(data, d, 'd');
	return (0);
}

void	ft_inner_loop(t_data dt, t_direction d, int i)
{
	int		j;
	t_tex	dd;

	d.x = 0;
	j = 0;
	dd.y = i * 64;
	while (dt.map[i][j] != '\0')
	{
		dd.x = j * 64;
		if (dt.map[i][j] == '1' && i == 0 && j == 0)
			mlx_put_image_to_window(dt.mlx, dt.window, dt.txt[2], dd.x, dd.y);
		else if (dt.map[i][j] == '1')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.txt[1], dd.x, dd.y);
		else if (dt.map[i][j] == 'E')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.txt[7], dd.x, dd.y);
		else if (dt.map[i][j] == '0')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.txt[0], dd.x, dd.y);
		j++;
	}
}

void	ft_mlx_window(t_data data)
{
	t_direction	d;
	int			i;

	i = 0;
	d.y = 0;
	while (data.map[i] != 0)
	{
		ft_inner_loop(data, d, i);
		i++;
	}
}

void	ft_mlx_hook(t_data *data)
{
	mlx_hook(data->window, KEYRELEASE, KEYRELEASEMASK, &on_keypress, data);
	mlx_hook(data->window, CROSSKEY, KEYRELEASEMASK, &ft_escape, data);
	mlx_loop_hook(data->mlx, ft_next_frame, data);
	mlx_loop(data->mlx);
}

void	ft_mlx(t_list **map)
{
	t_data		data;
	t_list		*head;

	head = *map;
	data.map = ft_get_map(map);
	data.mlx = mlx_init();
	if (!data.mlx)
		(write(2, "Error: MiniLibX initialization failed.\n", 39),
			ft_free_nodes(map), ft_free(&data.map), exit(EXIT_FAILURE));
	data.window_width = ft_strlen(head->data) * 64;
	data.window_height = ft_listlen(map) * 64;
	if (data.window_width > 2560 || data.window_height > 1408)
		(write(2, "Error\n", 6),
			ft_free_nodes(map), ft_free(&data.map), free(data.mlx),
			exit(EXIT_FAILURE));
	data.window = mlx_new_window (data.mlx, data.window_width,
			data.window_height, "so_long");
	if (!data.window)
		(write(2, "Error: Window is not initialized.\n", 34),
			ft_free_nodes(map), ft_free(&data.map), free(data.mlx),
			exit(EXIT_FAILURE));
	ft_load_images(&data);
	ft_mlx_window(data);
	data._node_map = &head;
	ft_mlx_hook(&data);
}
