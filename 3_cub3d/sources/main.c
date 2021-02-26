/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:26:41 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/25 23:20:11 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_init_image(t_env *e)
{
    if (!(e->mlx.new_image = mlx_new_image(e->mlx.ptr,
                    e->axes.axe_x, e->axes.axe_y)))
    {
        ft_exit("Error mlx_new_image", -1);
    }
    if (!(e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
            &e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian)))
    {
        ft_exit("Error mlx_get_data_addr", -1);
    }
    if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
    {
        ft_exit("Error malloc e->spt.dist_wall", -1);
    }
    ft_raycasting(e);
    ft_sprite(e);
    mlx_put_image_to_window(e->mlx.ptr, e->mlx.win_ptr,
            e->mlx.new_image, 0, 0);
    mlx_do_sync(e->mlx.ptr);
    mlx_destroy_image(e->mlx.ptr, e->mlx.new_image);
}

void    ft_open_window(t_env *e)
{
    if (!(e->mlx.ptr = mlx_init()))
    {
        ft_exit("Error mlx_init", -1);
    }
    ft_check_resolution_next(e);
    if (!(e->mlx.win_ptr = mlx_new_window(e->mlx.ptr, e->axes.axe_x,
            e->axes.axe_y, "cub3D")))
    {
        ft_exit("Error mlx_new_window", -1);
    }
    ft_textures(e);
    ft_init_sprite(e);
    ft_check_wall(e);
    ft_check_space(e);
    mlx_do_key_autorepeatoff(e->mlx.ptr);
    mlx_hook(e->mlx.win_ptr, 2, 1, &ft_key_down, e);
    mlx_hook(e->mlx.win_ptr, 3, 2, &ft_key_up, e);
    mlx_hook(e->mlx.win_ptr, 33, 0, ft_exit, "ESC");
    mlx_loop_hook(e->mlx.ptr, &ft_deplacement, e);
    mlx_loop(e->mlx.ptr);
}

int     ft_exit(char *s1, int i)
{
    printf("%s", s1);
    exit(i);
}

void    ft_push_bmp(t_env *e)
{
    e->mlx.ptr = mlx_init();
    if (!(e->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite),
                    e->map.nbr_sprite)))
    {
        ft_exit("Error push_bmp func malloc sprite", -1);
    }
    ft_textures(e);
    ft_init_sprite(e);
    e->mlx.new_image = mlx_new_image(e->mlx.ptr, e->axes.axe_x, e->axes.axe_y);
    e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
            &e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian);
    if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
    {
        ft_exit("Error malloc e->spt.dist_wall", -1);
    }
    ft_raycasting(e);
    ft_sprite(e);
    ft_bmp(e);
    ft_exit("Created BMP", 0);
}

int     main(int argc, char **argv)
{
    t_env   e;
    int     len;

    memset(&e, 0, sizeof(t_env));
    if (argv[2] && !ft_strcmp(argv[2], "--save") && argc < 4)
    {
         ft_read_map(argv[1], &e);
         ft_push_bmp(&e);
    }
    if (argc < 2 || argc > 2)
    {
        ft_exit("Error numbers of argc incorrect", -1);
    }
    len = (ft_strlen(argv[1]) - 4);
    if (!argv[1] || (ft_strncmp(argv[1] + len, ".cub", 4)))
    {
        ft_exit("ERROR no map or no file .cub", -1);
    }
    ft_read_map(argv[1], &e);
    ft_check_malloc(&e);
    ft_open_window(&e);
    return (0);
}