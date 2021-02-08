/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:28:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/08 20:31:56 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdio.h>

typedef struct      s_identifiants
{
    int             r;
    int             no;
    int             so;
    int             we;
    int             ea;
    int             s;
    int             f;
    int             c;
    int             m;
    int             perso;
}                   t_identifiants;

typedef struct      s_axes
{
    int             axe_x;
    int             axe_y;
}                   t_axes;

typedef struct      s_root_textures
{
    char            *north;
    char            *south;
    char            *east;
    char            *west;
    char            *sprite;
}                   t_root_textures;

typedef struct      s_colors
{
    int             color_sol;
    int             color_plafond;
    int             color_west;
    int             color_east;
    int             color_south;
    int             color_north;
    int             wall;
}                   t_colors;

typedef struct      s_map
{
    char            **tab_map;
    double          plan_x;
    double          plan_y;
    char            *buff;
    double          pos_n_x;
    double          pos_n_y;
    double          camera_x;
    double          ray_dir_x;
    double          ray_dir_y;
    int             hauteur_line;
    int             draw_start;
    int             draw_end;
    int             nbr_sprite;
}                   t_map;

typedef struct      s_orientation
{
    double          dir_x;
    double          dir_y;
    char            orientation_perso;
}                   t_orientation;

typedef struct      s_raycasting
{
    int             x;
    int             y;
    int             map_x;
    int             map_y;
    double          side_dist_x;
    double          side_dist_y;
    double          delta_x;
    double          delta_y;
    double          perp_wall_dist;
    int             step_x;
    int             step_y;
    int             side;
}                   t_raycasting;

typedef struct      s_mlx
{
    void            *ptr;
    void            *win_ptr;
    void            *new_image;
    int             *get_data;
    int             bits_per_pixel;
    int             size_line;
    int             endian;
    int             color;
    int             h;
    int             w;
    int             sizex;
    int             sizey;
}                   t_mlx;

typedef struct      s_mvt
{
    int             up;
    int             down;
    int             left;
    int             right;
    int             rot_right;
    int             rot_left;
    double          old_dir_x;
    double          old_plan_x;
    double          vit_rot;
}                   t_mvt;

typedef struct      s_textures
{
    int             bits_per_pixel;
    int             size_line;
    int             endian;
    void            *win_ptr;
    int             *get_data;
    int             w;
    int             h;
}                   t_textures;

typedef struct      s_bmp
{
    int             size;
    char            *image;
    unsigned char   header[14];
    unsigned char   info[40];
    unsigned char   pad[3];
    int             color;
    int             fd;
}                   t_bmp;

typedef struct      s_coord
{
    double          x;
    double          y;
}                   t_coord;

typedef struct      s_sprite
{
    int             sprite_order;
    double          sprite_distance;
    t_coord         coord;
    t_mlx           image;
}                   t_sprite;

typedef struct      s_spt
{
    double          x;
    double          y;
    double          inv_def;
    double          transform_x;
    double          transform_y;
    int             screen_x;
    int             height;
    int             start_y;
    int             start_x;
    int             end_y;
    int             end_x;
    int             width;
    int             tex_x;
    int             tex_y;
    double          *dist_wall;
}                   t_spt;

typedef struct      s_env
{
    t_identifiants  identifiants;
    t_axes          axes;
    t_root_textures root_textures;
    t_colors        colors;
    t_map           map;
    t_orientation   orientation;
    t_mlx           mlx;
    t_raycasting    raycasting;
    int             key;
    t_mvt           mvt;
    t_textures      texture_north;
    t_textures      texture_south;
    t_sprite        *sprite;
    t_spt           stp;
}                   t_env;

#endif
