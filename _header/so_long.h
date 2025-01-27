/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:44 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:40:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mandatory/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include </usr/local/include/mlx.h>
# define KEYRELEASE 2
# define KEYRELEASEMASK 0
# define CROSSKEY 17

/**	Structures for MLX	**/
typedef struct s_tex_img
{
	char	*wall;
	char	*coin;
	char	*player;
	char	*exit;
	char	*background;
}			t_tex_img;

typedef struct s_direction
{
	int	x;
	int	y;
}		t_direction;

typedef struct s_img
{
	int	width;
	int	height;
}		t_img;

typedef struct s_tex
{
	int	width;
	int	height;
	int	x;
	int	y;
}		t_tex;

/**	Structures for parsing	**/
typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

/**	Foundamental Structures for MLX	**/
typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	*img;
	char	**map;
	void	*pic[10];
	t_list	**_node_map;
}			t_data;

typedef struct s_cp
{
	int	e;
	int	c;
	int	p;
}		t_cp;

typedef struct s_count
{
	int		current;
	int		prev;
}			t_count;

/**	MLX functions	**/
int		on_keypress(int keysym, t_data *data);
int		ft_is_character(char c);
int		ft_last_row(char **arr);
void	ft_mlx(t_list **map);
void	ft_mlx_window(t_data data);
void	ft_inner_loop(t_data data, t_direction d, int i);
void	ft_mlx_hook(t_data *data);
void	ft_get_player_position(char **map, int *x, int *y);
void	ft_get_exit_position(char **map, int *x, int *y);
char	**ft_get_map(t_list **map);
void	ft_check_coin(t_data *data, t_direction d);
bool	ft_check_coin_for_exit(t_data *data);
void	ft_check_exit(t_data *data, char c);
void	ft_render(t_data *data, t_direction d, char c);
void	ft_norme_render_map_image(t_data *data, t_direction d, char c);
void	ft_norme__p2(t_data *data, t_direction d, char c);
bool	ft_render_map(t_data *d, char c, int x, int y);
void	ft_render_image(t_data data, void **texture, char *img);
int		ft_escape(t_data *data);
int		ft_destroy(t_data *data);
void	ft_free_before_exit(t_data *data);
void	ft_load_images(t_data *data);

/**	Parsing functions	*/
bool	ft_check_ber(char *str);
void	ft_parse_map(int fd, t_list **map);
void	ft_check_if_rectangle(t_list **map);
void	ft_check_char(t_list **map);
void	ft_check_walls(t_list **map);
void	ft_print_move(void);
void	ft_check_path(char ***_map, int x, int y);
void	ft_valid_path(t_list **map);
t_cp	ft_count_components(t_list **map);
int		*ft_get_coordination(char **str);
int		check_validity(char **_map);
void	ft_check_path_v2(char ***_map, int x, int y);
int		check_validity_v2(char **_map);

/**	Utils functions	**/
int		ft_strlen(char *str);
int		ft_listlen(t_list **map);
int		ft_putnbr(int nbr);
void	ft_free(char ***str);
void	ft_free_nodes(t_list **map);
void	ft_lstadd_back(t_list **lst, t_list *_new);
void	ft_print(int fd, char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char **s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
t_list	*ft_lstnew(char *data);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif