/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:49:22 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:58:42 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long_bonus.h"

int	ft_destroy(t_data *data)
{
	ft_pstr("-------------------\n");
	ft_pstr("You gave up!\n");
	ft_pstr("Is the map too hard for you?\n");
	ft_pstr("-------------------\n");
	mlx_destroy_window(data->mlx, data->window);
	ft_free(&data->map);
	ft_free_nodes(data->_node_map);
	exit(EXIT_SUCCESS);
}

void	ft_print_move(t_data *data)
{
	static int	movements;
	char		*number;
	t_tex		dd;

	dd.x = 0;
	dd.y = 0;
	movements++;
	number = ft_itoa(movements);
	mlx_put_image_to_window(data->mlx, data->window, data->txt[2], dd.x, dd.y);
	mlx_string_put(data->mlx, data->window, dd.x + 10, 21, COLOR, number);
	free(number);
}

void	ft_exit(t_data *data)
{
	char	*m1;
	char	*m2;

	m1 = "-------------------\nCongratulations.\nYou Found all the Coins.\n";
	m2 = "You Won\n-------------------\n";
	ft_print_move(data);
	ft_pstr(m1);
	ft_pstr(m2);
	ft_free(&data->map);
	ft_free_nodes(data->_node_map);
	free(data->mlx);
}

void	ft_free_before_exit(t_data *data)
{
	ft_free_nodes(data->_node_map);
	ft_free(&data->map);
	free(data->mlx);
}

void	ft_load_images(t_data *data)
{
	ft_render_image(*data, &data->txt[0], "./textures/bkg.xpm");
	ft_render_image(*data, &data->txt[1], "./textures/wall.xpm");
	ft_render_image(*data, &data->txt[2], "./textures/counter.xpm");
	ft_render_image(*data, &data->txt[3], "./textures/enemy_01.xpm");
	ft_render_image(*data, &data->txt[4], "./textures/enemy_02.xpm");
	ft_render_image(*data, &data->txt[5], "./textures/enemy_03.xpm");
	ft_render_image(*data, &data->txt[6], "./textures/enemy_04.xpm");
	ft_render_image(*data, &data->txt[7], "./textures/closed.xpm");
	ft_render_image(*data, &data->txt[8], "./textures/opened.xpm");
	ft_render_image(*data, &data->txt[9], "./textures/key_01.xpm");
	ft_render_image(*data, &data->txt[10], "./textures/key_02.xpm");
	ft_render_image(*data, &data->txt[11], "./textures/key_03.xpm");
	ft_render_image(*data, &data->txt[12], "./textures/key_04.xpm");
	ft_render_image(*data, &data->txt[13], "./textures/hero_01.xpm");
	ft_render_image(*data, &data->txt[14], "./textures/hero_02.xpm");
	ft_render_image(*data, &data->txt[15], "./textures/hero_03.xpm");
	ft_render_image(*data, &data->txt[16], "./textures/hero_04.xpm");
}
