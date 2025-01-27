/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:49:22 by iassil            #+#    #+#             */
/*   Updated: 2024/02/20 10:44:23 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

int	ft_destroy(t_data *data)
{
	ft_print(1, "-------------------\n");
	ft_print(1, "You gave up!\n");
	ft_print(1, "Is the map too hard for you?\n");
	ft_print(1, "-------------------\n");
	mlx_destroy_window(data->mlx, data->window);
	ft_free_nodes(data->_node_map);
	ft_free(&data->map);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

void	ft_print_move(void)
{
	static int	movements;

	movements++;
	if (movements == 1)
	{
		ft_print(1, "You moved ");
		ft_putnbr(movements);
		ft_print(1, " time.\n");
	}
	else if (movements > 1)
	{
		ft_print(1, "You moved ");
		ft_putnbr(movements);
		ft_print(1, " times.\n");
	}
}

int	ft_escape(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_free(&data->map);
	ft_free_nodes(data->_node_map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_before_exit(t_data *data)
{
	ft_free_nodes(data->_node_map);
	ft_free(&data->map);
	free(data->mlx);
}

void	ft_load_images(t_data *data)
{
	ft_render_image(*data, &data->pic[0], "./textures/bkg.xpm");
	ft_render_image(*data, &data->pic[1], "./textures/wall.xpm");
	ft_render_image(*data, &data->pic[2], "./textures/coin.xpm");
	ft_render_image(*data, &data->pic[3], "./textures/front.xpm");
	ft_render_image(*data, &data->pic[4], "./textures/back.xpm");
	ft_render_image(*data, &data->pic[5], "./textures/left.xpm");
	ft_render_image(*data, &data->pic[6], "./textures/right.xpm");
	ft_render_image(*data, &data->pic[7], "./textures/opened.xpm");
	ft_render_image(*data, &data->pic[8], "./textures/closed.xpm");
}
