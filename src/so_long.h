/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:12:27 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/18 15:21:54 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include "../mlx/mlx_int.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define UP			1
# define DOWN		2
# define LEFT		3
# define RIGHT		4

typedef struct s_imgs
{
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bites_per_pxl;
	int		endian;
	int		line_len;
}				t_imgs;

typedef struct s_player
{
	t_imgs	*head1;
	t_imgs	*head2;
	t_imgs	*head3;
	t_imgs	*head4;
	t_imgs	*body1;
	t_imgs	*body2;
	t_imgs	*body3;
	t_imgs	*body4;
	t_imgs	*body5;
	t_imgs	*body6;
	t_imgs	*tail1;
	t_imgs	*tail2;
	t_imgs	*tail3;
	t_imgs	*tail4;
}				t_player;

typedef struct s_map
{
	t_imgs	*wall;
	t_imgs	*grnd;
	t_imgs	*coll;
	t_imgs	*exit;
}				t_map;

typedef struct s_timeval
{
	time_t			tv_sec;
	suseconds_t		tv_usec;
}				t_timeval;

typedef struct s_vars
{
	t_imgs		*bkgrnd;
	t_list		*pos;
	t_map		*map;
	t_player	*player;
	t_timeval	*timer;
	char		**og_map;
	char		**p_map;
	int			last_move;
	int			last_kc;
	int			moves;
	int			player_size;
	int			speed;
	long		frame;
	void		*mlx;
	void		*win;
}				t_vars;

//map validation
int				check_file_name(char *map_name);
int				validate_map(char **map);
int				is_retangular(char **map);
int				check_for_stuff(char **map);
int				check_for_walls(char **map);
int				check_for_invalid_content(char **map);
int				check_for_exit_and_colect(char **map);
int				check_walls_in_bottom_and_top(char **map);
int				there_is_a_way(char **map);
int				check_for_path(char **map);
void			print_error(int mode);

//map creation
int				map_lines_counter(char *map);
char			**create_map(char *file_name);
char			**duplicate_map(char **map);

//map management
int				get_map_height(char **map);
int				get_map_width(char **map);
void			get_player_pos(char **map, int *player_x, int *player_y);
void			flood_fill(char	**map, int x, int y);
void			free_map(char **map);
void			change_map(t_vars *vars, int move);
void			create_player_map(t_vars *vars);
void			fill_p_map(t_vars *vars, char **map);

//image loading
void			load_frame(t_vars vars, int move);
void			load_imgs(t_vars *vars, int move);
t_map			*load_map_imgs(t_vars *vars);
t_player		*load_player_imgs(t_vars *vars);
void			load_bkgrnd(char **map, t_map *img, t_imgs *bkgrnd);
void			load_layer2(t_vars *vars, int move);
void			free_map_imgs(t_vars *mlx, t_map *map);
void			player_put(t_vars *vars, int move);
void			load_player_imgs_aftermove(t_vars *vars, int width,
					int height, int move);

//player loading
void			load_player_head(t_player *p, t_vars *vars);
void			load_player_body(t_player *p, t_vars *vars);
void			load_player_tail(t_player *p, t_vars *vars);
void			free_player(t_vars *vars);
void			free_head(t_vars *vars);
void			free_body(t_vars *vars);
void			free_tail(t_vars *vars);

//transparency handling
t_imgs			*new_img(int w, int h, t_vars *mlx, t_vars *window);
t_imgs			*new_file_img(char *path, void *mlx, void *window);
void			put_pixel_img(t_imgs *img, int x, int y, int color);
unsigned int	get_pixel_img(t_imgs *img, int x, int y);
void			put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y);

//image putting
void			put_player_left_or_right(t_vars *vars, int wh,
					int ht, int move);
void			put_player_up_or_down(t_vars *vars, int wh,
					int ht, int move);
void			print_body(t_vars *vars, int width, int height);
void			print_v_or_h(t_vars *vars, t_list *tmp, int *wh, int *ht);
void			print_dr_or_lu(t_vars *vars, t_list *tmp, int *wh, int *ht);
void			print_ld_or_ur(t_vars *vars, t_list *tmp, int *wh, int *ht);
void			remove_collectible(t_vars *vars, int x, int y);
void			remove_collectible_player_map(t_vars *vars, int x, int y);
void			remove_pos_coll(t_vars *vars, int n, int i);

//movement
int				check_key(int kc, t_vars *vars);
int				repeat_key(t_vars *vars);
void			check_up_or_down(t_vars *vars, int kc);
void			check_left_or_right(t_vars *vars, int kc);
void			move_player(t_vars *vars, int move, char **map);
void			do_the_move(t_vars *vars, int move);
void			check_move(t_vars *vars, int move, int x, int y);
int				decide_move(t_vars *vars, int move);
int				get_head_x(char **map);
int				get_head_y(char **map);
int				is_there_a_wall(t_vars *vars, int x, int y);
int				is_move_possible(t_list *pos, int x, int y, t_vars *vars);
void			change_map_up(t_vars *vars, int n, int i);
void			change_map_down(t_vars *vars, int n, int i);
void			change_map_right(t_vars *vars, int n, int i);
void			change_map_left(t_vars *vars, int n, int i);

//quiting
int				quit_game(t_vars *vars, int signal);
void			print_msg(t_vars *vars, int mode);
void			ft_clear_lst(t_list *pos);

#endif