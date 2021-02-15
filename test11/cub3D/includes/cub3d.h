#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include "../mlx/mlx.h"

# define _ESC		53
# define _W			13
# define _A			0
# define _S			1
# define _D			2
# define _UP		126
# define _LEFT		123
# define _DOWN		125
# define _RIGHT		124
# define _SPACE		49
# define _M			46
# define _SHIFT		257
# define _ENTER		36
# define _MIN		27
# define _PLS		24
# define _E			14
# define _QUES		44

/*
	t_cub3d
			t_win
				- pointer for mlx library
						: mlx, win
				- informations for window
						: wid, hei
				- 
*/
typedef struct		s_map
{
	char			**map;
	char			*nam;
	int				wid;
	int				hei;
	double			siz;
}					t_map;
typedef struct		s_key
{
	int				_w;
	int				_s;
	int				_a;
	int				_d;
	int				_left;
	int				_right;
	int				_up;
	int				_down;
	int				_help;
	int				_map;
}					t_key;
typedef struct		s_pos
{
	double			pox;
	double			poy;
	double			spd;
	double			dix;
	double			diy;
	double			plx;
	double			ply;
	double			rot;
	double			cam;
	int				hel;
	int				hun;
	int				last_walk_sound;
	int				last_heal;
	int				last_hungry;
	int				last_hungry_hurt;
	int				last_hurt;
	int				last_eat;
	int				left_food;
}					t_pos;
typedef struct		s_img
{
	int				wid;
	int				hei;
	int				siz;
	int				bpp;
	int				end;
	void			*img;
	char			*dat;
}					t_img;
typedef struct		s_spr
{
	int				pox;
	int				poy;
	struct s_spr	*nxt;
}					t_spr;
typedef struct		s_snd
{
	clock_t			clo;
}					t_snd;
typedef struct		s_cub3d
{
	void			*mlx;
	void			*win;
	int				wid;
	int				hei;

	int				clr_floor;
	int				clr_ceiling;
	int				sav;

	int				opt;
	int				sig;
	int				is_game_playing;
	int				idx;
	int				intro_time;
	int				intro_wid;
	int				outro_time;

	t_map			*map;
	t_key			*key;
	t_pos			*pos;
	t_img			*img;
	t_img			**txt;
	t_img			*spr;
	t_spr			*spr_scr;
	t_snd			*snd;
}					t_cub3d;


/*
	t_lst
*/
typedef	struct		s_lst
{
	void			*dat;
	struct s_lst	*nxt;
}					t_lst;

/*
	t_ray
*/
typedef struct		s_ray
{
	int				pix;
	int				hit;
	int				sid;
	int				hei;
	int				stt;
	int				end;
	int				map_pox;
	int				map_poy;
	double			cam_pox;
	double			ray_dix;
	double			ray_diy;
	double			sid_pox;
	double			sid_poy;
	double			dlt_pox;
	double			dlt_poy;
	double			perp_wd;
	int				stp_pox;
	int				stp_poy;
	double			*z_buffr;
}					t_ray;

/*
	t_lin
*/
typedef struct		s_lin
{
	int				pox;
	int				poy;
	int				py0;
	int				py1;
	int				txx;
	int				txy;
}					t_lin;

/*
	t_drs
*/
typedef struct		s_drs
{
	t_spr			*spr;
	int				idx;
	double			spr_pox;
	double			spr_poy;
	double			inv_det;
	double			trn_pox;
	double			trn_poy;
	int				scr_pox;
	int				spr_wid;
	int				spr_hei;
	int				stt_pox;
	int				stt_poy;
	int				end_pox;
	int				end_poy;
	int				stripes;
	int				poy;
	int				d;
	int				txx;
	int				txy;
	int				clr;
	int				tot_clr;
}					t_drs;

/*
	t_sps
*/
typedef struct		s_sps
{
	int				pox;
	int				poy;
	struct s_spr	*nxt;
}					t_sps;

/*
	t_num
*/
typedef struct		s_num
{
	int				n1;
	int				n2;
}					t_num;

/*
	ALL PROTOTYPES (except tool, util, error, ...) SORTED BY CALL

	function prototypes:
		return		ft_(file)_functionName(parameters);

	init
		init1.c
			ft_init_cub_win
			ft_init_textures
			ft_init_sprites
			ft_init_map
			ft_init_keybuff
		init2.c
			ft_init_player
			ft_init_win_img
			ft_init_sound
	util.c
		util1.c
			ft_util_bzero
			ft_util_strlen
			ft_util_memcpy
			ft_util_strjoin
			ft_util_strdup
		util2.c
			ft_util_strlcpy
			ft_util_strlcat
			ft_util_is_empty
			ft_util_is_number
			ft_util_is_printable
		util3.c
			ft_util_str_size
			ft_util_str_to_int
			ft_util_substr
			ft_util_strncmp
			ft_util_lstsize
		util4.c
			ft_util_num_length
			ft_util_itoa
			ft_util_atoi
*/

/*
	tool.c
*/
void				ft_tool_exit(int mod, t_cub3d *cub, int err, char *msg);

/*
	util.c	
*/
void				*ft_util_bzero(void *s, size_t n);
size_t				ft_util_strlen(const char *str);
void				*ft_util_memcpy(void *d, const void *s, size_t n);
char				*ft_util_strjoin(char *st1, char *st2);
char				*ft_util_strdup(char *str);
size_t				ft_util_strlcpy(char *dst, const char *src, size_t siz);
size_t				ft_util_strlcat(char *dst, const char *src, size_t siz);
int					ft_util_is_empty(char c);
int					ft_util_is_number(char c);
int					ft_util_is_printable(char c);
int					ft_util_str_size(char *str, int idx);
int					ft_util_str_to_int(char *str, int idx);
char				*ft_util_substr(char const *str, unsigned int stt, size_t len);
int					ft_util_strncmp(const char *st1, const char *st2, size_t num);
int					ft_util_lstsize(t_lst *lst);
size_t				ft_util_num_length(int nbr);
char				*ft_util_itoa(int n);
int					ft_util_atoi(const char *str);

/*
	error.c
*/
void				ft_error_input(void);

/*
	all prototypes
*/
t_cub3d				*ft_init_cub_win(void);
int					ft_init_textures(t_cub3d *cub, int num);
int					ft_init_sprites(t_cub3d *cub);
int					ft_init_map(t_cub3d *cub, char *map_name);
int					ft_init_keybuff(t_cub3d *cub);
int					ft_init_player(t_cub3d *cub);
int					ft_init_win_img(t_cub3d *cub);
char				*ft_cub_reader(char *fil, t_cub3d *cub);
int					ft_cub_read(char *lin, char **map, int rst_gnl, t_cub3d *cub);
int					get_next_line(int file, char **line);
int					ft_cub_read_sub(char *lin, char idx, t_cub3d *cub);
int					ft_cub_read_window_size(char *lin, t_cub3d *cub);
int					ft_cub_read_window_size_check(char *lin);
int					ft_cub_read_path(char *lin, t_num *num, int idx, t_cub3d *cub);
int					ft_cub_read_path_check(char *lin);
int					ft_cub_read_path_file_exist(char *pth);
int					ft_cub_read_path_other(t_cub3d *cub, t_num *num, char *pth);
int					ft_texture_set(t_cub3d *cub, char *pth, int opt);
int					ft_sprites_set(t_cub3d *cub, char *pth);
int					ft_cub_read_color(char *lin, int chr, int idx, t_cub3d *cub);
int					ft_cub_read_color_check(char *str, int chr, int idx, t_cub3d *cub);
int					ft_cub_read_color_get_rgb_sep(int spc, char *lin, int *i, t_cub3d *cub);
int					ft_cub_read_color_get_rgb(int r, int g, int b);
int					ft_cub_read_map(char *l, char **map, int i, int rst_gnl);
int					ft_cub_read_other(char *lin, int idx, t_cub3d *cub);
char				**ft_translate_map(char *str, t_cub3d *cub);
void				ft_translate_map_get_size(char *map, t_cub3d *cub);
char				**ft_translate_map_malloc(t_cub3d *cub);
char				**ft_translate_map_init(char *str, char **map, t_cub3d *cub);
void				ft_player_set_start(t_cub3d *cub, char dir, int cur, int u);
void				ft_camera_set_start(t_cub3d *cub, double dix, double plx, double ply);
int					ft_translate_map_check(t_cub3d *cub, char **map);
t_img				*ft_image_new(t_cub3d *cub, int wid, int hei);
int					ft_init_sound(t_cub3d *cub);
void				ft_save(t_cub3d *cub, char *arv[]);
int					ft_raycasting(t_cub3d *cub);
void				ft_raycasting_main(t_cub3d *cub, t_ray *ray);
void				ft_raycasting_main_init(t_cub3d *cub, t_ray *ray);
void				ft_raycasting_main_step(t_cub3d *cub, t_ray *ray);
void				ft_raycasting_main_hit_(t_cub3d *cub, t_ray *ray);
void				ft_raycasting_main_hit_wall(t_ray *ray);
void				ft_sprite(t_cub3d *cub, t_ray *ray);
void				ft_raycasting_main_perp(t_cub3d *cub, t_ray *ray);
void				ft_texture(t_cub3d *cub, t_ray *ray);
void				ft_texture_side(t_cub3d *cub, t_ray *ray, t_lin *lin, double wlx);
void				ft_image_lin_txt_clr(t_cub3d *cub, t_ray *ray, t_lin *lin, t_img *txt);
void				ft_image_texture_on_img(t_cub3d *cub, t_ray *ray, t_lin *lin, t_img *txt);
void				ft_image_color(t_cub3d *cub, t_lin *lin, int clr);
void				ft_image_pixel_img(int clr, int pox, int poy, t_img *img);
int					ft_draw_sprite(t_cub3d *cub, t_ray *ray);
t_spr				*ft_sprite_lst_tab(t_cub3d *cub);
void				ft_sprite_sort(t_cub3d *cub, t_spr *spr, int num);
void				ft_draw_sprite_make(t_cub3d *cub, t_ray *ray, t_drs *drs);
void				ft_draw_sprite_make_calcul(t_cub3d *cub, t_drs *drs);
void				ft_draw_sprite_make_pix(t_cub3d *cub, t_drs *drs);
void				ft_draw_sprite_make_is_black(t_cub3d *cub, t_drs *drs);
int					ft_bitmap_save(t_img *img, char *nam);
int					ft_bitmap_info_header(t_img *img, int fil);
int					ft_bitmap_verti(t_img *img);
void				ft_bitmap_verti_sub(t_img *img, int lin, int *idx, int jdx);
int					ft_bitmap_data(t_img *img, int fil);
int					ft_event_key_press(int key, t_cub3d *cub);
void				ft_health_change(t_cub3d *cub, int opt, int amt);
int					ft_event_key_press_opt(t_cub3d *cub, int opt);
int					ft_event_key_release(int key, t_cub3d *cub);
int					ft_event_destroy(t_cub3d *cub);
int					ft_loop(t_cub3d *cub);
void				ft_special_intro(t_cub3d *cub);
void				ft_special_intro_print_welcome(t_cub3d *cub, int *w);
void				ft_special_intro_print_cub3d(t_cub3d *cub, int *w);
void				ft_loop_health(t_cub3d *cub);
void				ft_loop_draw(t_cub3d *cub);
void				ft_loop_draw_string_put(t_cub3d *cub);
void				ft_health_draw(t_cub3d *cub);
void				ft_hungry_draw(t_cub3d *cub);
int					ft_key_manager(t_cub3d *cub);
void				ft_player_move_front_back(t_cub3d *cub, int opt);
void				ft_player_move_left_right(t_cub3d *cub, int opt);
void				ft_player_move_sound(t_cub3d *cub, int now);
void				ft_camera_turn_left_right(t_cub3d *cub, int opt);
void				ft_camera_turn_up_down(t_cub3d *cub, int opt);
void				ft_music_play(t_cub3d *cub);
void				ft_special_outro(t_cub3d *cub);
void				ft_special_outro2(t_cub3d *cub);

#endif