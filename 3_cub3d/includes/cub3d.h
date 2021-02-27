/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:28:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 20:00:37 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_identifier
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
	int				m;
	int				perso;
}					t_identifier;

typedef struct		s_window
{
	int				x;
	int				y;
}					t_window;

typedef struct		s_root_textures
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
}					t_root_textures;

typedef struct		s_colors
{
	int				color_sol;
	int				color_plafond;
	int				color_west;
	int				color_east;
	int				color_south;
	int				color_north;
	int				wall;
}					t_colors;

typedef struct		s_map
{
	char			**tab_map;
	double			plan_x;
	double			plan_y;
	char			*buff;
	double			pos_n_x;
	double			pos_n_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				texture_line;
	int				draw_start;
	int				draw_end;
	int				nbr_sprite;
}					t_map;

typedef struct		s_orientation
{
	double			dir_x;
	double			dir_y;
	char			orientation_perso;
}					t_orientation;

typedef struct		s_raycasting
{
	int				x;
	int				y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_x;
	double			delta_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
}					t_raycasting;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	void			*new_image;
	int				*get_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				color;
	int				h;
	int				w;
	int				sizex;
	int				sizey;
}					t_mlx;

typedef struct		s_mvt
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				rot_right;
	int				rot_left;
	double			old_dir_x;
	double			old_plan_x;
	double			vit_rot;
}					t_mvt;

typedef struct		s_textures
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*win_ptr;
	int				*get_data;
	int				w;
	int				h;
}					t_textures;

typedef struct		s_bmp
{
	int				size;
	char			*image;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_sprite
{
	int				sprite_order;
	double			sprite_distance;
	t_coord			coord;
	t_mlx			image;
}					t_sprite;

typedef struct		s_spt
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				height;
	int				start_y;
	int				start_x;
	int				end_y;
	int				end_x;
	int				width;
	int				tex_x;
	int				tex_y;
	double			*dist_wall;
}					t_spt;

typedef struct		s_env
{
	t_identifier	identifier;
	t_window		window;
	t_root_textures	root_textures;
	t_colors		colors;
	t_map			map;
	t_orientation	orientation;
	t_mlx			mlx;
	t_raycasting	raycasting;
	int				key;
	t_mvt			mvt;
	t_textures		texture_north;
	t_textures		texture_south;
	t_textures		texture_east;
	t_textures		texture_west;
	t_sprite		*sprite;
	t_spt			spt;
}					t_env;

void				ft_parsing_line_r(t_env *e, char *line);
void				ft_parsing_line_no(t_env *e, char *line, int i);
void				ft_parsing_line_ea(t_env *e, char *line, int i);
void				ft_parsing_line_so(t_env *e, char *line, int i);
void				ft_parsing_line_we(t_env *e, char *line, int i);
void				ft_parsing_line_f(t_env *e, char *line, int i);
void				ft_parsing_line_s(t_env *e, char *line, int i);
void				ft_parsing_line_c(t_env *e, char *line, int i);
void				ft_parsing_line_m(t_env *e, char *line, int i);
void				ft_read_map(char *argv, t_env *e);
void				ft_recup_axes(t_env *e, char *line);
char				*ft_recup_root(char *line, int i);
int					ft_recup_color(char *line, int i);
void				ft_recup_map(char *line, t_env *e);
void				ft_init_window(t_env *e);
void				ft_recup_map_2(t_env *e);
void				ft_pos_perso(t_env *e);
void				ft_orientation_perso(t_env *e);
int					ft_check_perso(t_env *e, int i, int j);
void				ft_raycasting(t_env *e);
int					ft_deplacement(t_env *e);
int					ft_key_up(int keycode, t_env *e);
int					ft_key_down(int keycode, t_env *e);
void				ft_init_image(t_env *e);
void				ft_until_wall(t_env *e);
void				ft_draw_texture(t_env *e, int x, int y);
void				ft_textures(t_env *e);
void				ft_put_textures(t_env *e, int x);
void				ft_bmp(t_env *e);
void				ft_complete_header(t_env *e, t_bmp *bmp);
int					ft_exit(char *s1, int i);
void				ft_sprite_distance(t_env *e);
void				ft_swap_sprite(t_env *e);
void				ft_sprite(t_env *e);
void				ft_coord_sprite(t_env *e);
void				ft_check_wall(t_env *e);
void				ft_check_resolution(t_env *e);
void				ft_check_wall_next(t_env *e);
void				ft_check_map(t_env *e, int i, char *line);
char				**ft_map_size(t_env *e);
int					ft_rgb_color(char *line, int *i);
void				ft_space(char *line, int *i);
void				ft_mv_up(t_env *e);
void				ft_mv_down(t_env *e);
void				ft_mv_left(t_env *e);
void				ft_mv_right(t_env *e);
void				ft_free_sprite(t_env *e);
void				ft_free(t_env *e);
void				ft_check(t_env *e);
void				ft_parsing_check(t_env *e);
int					ft_check_identifier(t_env *e);
void				ft_check_wall_again(t_env *e);
int					is_charset(char *charset, char c);
void				ft_check_space(t_env *e);
void				ft_check_resolution_next(t_env *e);
void				ft_sprite_malloc(t_env *e);
void				ft_parsing_line_check(char *line);
float				ft_power(float nb, int power);
void				ft_push_bmp(t_env *e);
void				ft_map_fill(t_env *e, char **tmp);

#endif
