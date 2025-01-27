/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:26:09 by iassil            #+#    #+#             */
/*   Updated: 2024/02/20 10:44:45 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_header/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	char	***mlx_map;
	t_list	*map;

	mlx_map = NULL;
	if (ac != 2)
		(ft_print(2, "Error: too few Arguments.\n"), exit(EXIT_FAILURE));
	if (ft_check_ber(av[1]) == false)
		(ft_print(2, "Error: extension unsupported.\n"), exit(EXIT_FAILURE));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		(perror(av[1]), exit(EXIT_FAILURE));
	map = NULL;
	ft_parse_map(fd, &map);
	ft_mlx(&map);
	ft_free_nodes(&map);
}

bool	ft_check_ber(char *str)
{
	size_t	len;
	int		index;

	len = ft_strlen(str);
	if (len < 4)
		return (false);
	index = len - 4;
	if (ft_strnstr(str + index, ".ber", 4) != NULL)
		return (true);
	return (false);
}
