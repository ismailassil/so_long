/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:06:47 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:28:38 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

void	ft_mlx(t_list **map)
{
	t_img		img;
	t_data		data;
	t_list		*head;

	head = *map;
	data.map = ft_get_map(map);
	data.mlx = mlx_init();
	if (!data.mlx)
		(ft_print(2, "Error: MiniLibX initialization failed.\n"),
			ft_free_nodes(map), ft_free(&data.map), exit(EXIT_FAILURE));
	img.width = ft_strlen(head->data) * 64;
	img.height = ft_listlen(map) * 64;
	if (img.width > 2560 || img.height > 1408)
		(ft_print(2, "Error\n"),
			ft_free_nodes(map), ft_free(&data.map), free(data.mlx),
			exit(EXIT_FAILURE));
	data.window = mlx_new_window(data.mlx, img.width, img.height, "so_long");
	if (!data.window)
		(ft_print(2, "Error: Window is not initialized.\n"),
			ft_free_nodes(map), ft_free(&data.map), free(data.mlx),
			exit(EXIT_FAILURE));
	ft_load_images(&data);
	ft_mlx_window(data);
	data._node_map = &head;
	ft_mlx_hook(&data);
}

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
		if (dt.map[i][j] == '1')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.pic[1], dd.x, dd.y);
		else if (dt.map[i][j] == 'P')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.pic[3], dd.x, dd.y);
		else if (dt.map[i][j] == 'C')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.pic[2], dd.x, dd.y);
		else if (dt.map[i][j] == 'E')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.pic[8], dd.x, dd.y);
		else if (dt.map[i][j] == '0')
			mlx_put_image_to_window(dt.mlx, dt.window, dt.pic[0], dd.x, dd.y);
		j++;
	}
}

void	ft_mlx_hook(t_data *data)
{
	mlx_hook(data->window, KEYRELEASE, KEYRELEASEMASK, &on_keypress, data);
	mlx_hook(data->window, CROSSKEY, KEYRELEASEMASK, &ft_escape, data);
	mlx_loop(data->mlx);
}
