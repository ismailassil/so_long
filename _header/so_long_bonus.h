/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:44 by iassil            #+#    #+#             */
/*   Updated: 2024/02/18 20:28:30 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../bonus/get_next_line/get_next_line_bonus.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include </usr/local/include/mlx.h>
# define KEYRELEASE 2
# define KEYRELEASEMASK 0
# define CROSSKEY 17
# define COLOR 0x0000FF

/**	Structures for MLX	**/
typedef struct s_tex_img
{
	char	*wall;
	char	*coin;
	char	*player;
	char	*exit;
	char	*background;
}			t_tex_img;

typedef struct s_cc
{
	int	i;
	int	j;
}		t_cc;

typedef struct s_direction
{
	int	x;
	int	y;
}		t_direction;

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
	int		window_width;
	int		window_height;
	void	*txt[17];
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

/**	Linked List functions	*/
t_list	*ft_lstnew(char *data);
void	ft_lstadd_back(t_list **lst, t_list *_new);
int		ft_listlen(t_list **map);

/**	MLX functions	**/
void	ft_check_coin(t_data *data, t_direction d);
int		on_keypress(int keysym, t_data *data);
void	ft_inner_loop(t_data data, t_direction d, int i);
void	ft_mlx_window(t_data data);
void	ft_mlx(t_list **map);
int		ft_destroy(t_data *data);
void	ft_print_move(t_data *data);
void	ft_check_exit(t_data *data, char c);
bool	ft_check_coin_for_exit(t_data *data);
bool	ft_render_map(t_data *d, char c, int x, int y);
void	ft_render_image(t_data data, void **texture, char *img);
void	ft_norme__p2(t_data *data, t_direction d, char c);
void	ft_norme_render_map_image(t_data *data,
			t_direction d, char c);
void	ft_render(t_data *data, t_direction d, char c);
int		ft_escape(t_data *data);
void	ft_load_images(t_data *data);

/**	MLX Animation functions	**/
int		ft_next_frame(void *data_);
void	ft_coin(t_data *data, t_tex dd);
void	ft_enemy(t_data *data, t_tex dd);
void	ft_player(t_data *data, t_tex dd);
void	ft_check_enemy(t_data *data, char c);
char	*ft_itoa(int n);
void	ft_mlx_hook(t_data *data);

/**	Enemy Movement	**/
void	ft_move_enemy(t_data *data);
void	ft_render_the_move(t_data *data, int *i, int *j);
void	ft_move_right(t_data *data, int *i, int *j, int *k);
void	ft_move_left(t_data *data, int *i, int *j, int *k);
void	ft_check_path_v2(char ***_map, int x, int y);
int		check_validity_v2(char **_map);
void	ft_check_path_v3(char ***_map, int x, int y);
int		check_validity_v3(char **_map);

/**	Parsing functions	*/
void	ft_parse_map(int fd, t_list **map);
void	ft_check_if_rectangle(t_list **map);
t_cp	ft_count_components(t_list **map);
void	ft_check_char(t_list **map);
void	ft_check_walls(t_list **map);
int		ft_is_character(char c);
char	**ft_get_map(t_list **map);
void	ft_get_player_position(char **map, int *x, int *y);
void	ft_get_exit_position(char **map, int *x, int *y);
int		ft_last_row(char **arr);
void	ft_free(char ***str);
int		*ft_get_coordination(char **str);
void	ft_check_path(char ***_map, int x, int y);
int		check_validity(char **_map);
void	ft_valid_path(t_list **map);
void	ft_exit(t_data *data);
void	ft_free_before_exit(t_data *data);

/**	Main file	**/
void	ft_free_nodes(t_list **map);
bool	ft_check_ber(char *str);
void	ft_pstr(char *str);

/**	Utils functions	**/
int		ft_listlen(t_list **map);
void	ft_lstadd_back(t_list **lst, t_list *_new);
t_list	*ft_lstnew(char *data);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strlen(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char **s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_putnbr(int nbr);

#endif