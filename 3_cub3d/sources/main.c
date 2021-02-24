/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:26:41 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/23 20:23:18 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_init_image(t_env *e)
{
    if (!(e->mlx.new_image = mlx_new_image(e->mlx.ptr,
                    e->axes.axe_x, e->axes.axe_y)))
    {
        ft_putstr_fd("Error\nmlx_new_image", 1);
        ft_exit(e);
    }
    if (!(e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
            &e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian)))
    {
        ft_putstr_fd("Error\nmlx_get_data_addr", 1);
        ft_exit(e);
    }
    if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
    {
        ft_putstr_fd("Error\nMalloc e->spt.dist_wall", 1);
        ft_exit(e);
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
        ft_putstr_fd("Error\nmlx_init", 1);
        ft_exit(e);
    }
    ft_check_resolution_next(e);
    if (!(e->mlx.win_ptr = mlx_new_window(e->mlx.ptr, e->axes.axe_x,
            e->axes.axe_y, "Cub3D")))
    {
        ft_putstr_fd("Error\nmlx_new_window", 1);
        ft_exit(e);
    }
    ft_textures(e);
    ft_init_sprite(e);
    ft_check_wall(e);
    ft_check_space(e);
    mlx_do_key_autorepeatoff(e->mlx.ptr);
    mlx_hook(e->mlx.win_ptr, 2, 1, &ft_key_down, e);
    mlx_hook(e->mlx.win_ptr, 3, 2, &ft_key_up, e);
    mlx_hook(e->mlx.win_ptr, 33, 0, &ft_exit, e);
    mlx_loop_hook(e->mlx.ptr, &ft_deplacement, e);
    mlx_loop(e->mlx.ptr);
}

int     ft_exit(t_env *e)
{
    int i;

    i = 0;
    while(i < e->map.nbr_sprite)
    {
        if (e->sprite[i].image.get_data)
            mlx_destroy_image(e->mlx.ptr, e->sprite[i].image.win_ptr);
        if (e->sprite[i].image.win_ptr == NULL)
        {
            ft_putstr_fd("error", 1);
            return (-1);
        }
        if (e->mlx.ptr && e->mlx.win_ptr)
            mlx_clear_window(e->mlx.ptr, e->mlx.win_ptr);
        i++;
    }
    if (e->sprite)
        free(e->sprite);
    if (e->map.buff)
        free(e->map.buff);
    ft_exit_free(e);
    exit(0);
    return (0);
}

void    ft_push_bmp(t_env *e)
{
    e->mlx.ptr = mlx_init();
    if (!(e->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite),
                    e->map.nbr_sprite)))
    {
        ft_putstr_fd("Error\nMalloc sprite", 1);
        ft_exit(e);
    }
    ft_textures(e);
    ft_init_sprite(e);
    e->mlx.new_image = mlx_new_image(e->mlx.ptr, e->axes.axe_x, e->axes.axe_y);
    e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
            &e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian);
    if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->axes.axe_x)))
    {
        ft_putstr_fd("Error\nMalloc e->spt.dist_wall", 1);
        ft_exit(e);
    }
    ft_raycasting(e);
    ft_sprite(e);
    ft_bmp(e);
    free(e->mlx.new_image);
    ft_exit(e);
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
        ft_putstr_fd("Error\nNumbers of argc incorrect", 1);
        exit(0);
    }
    len = (ft_strlen(argv[1]) - 4);
    if (!argv[1] || (ft_strncmp(argv[1] + len, ".cub", 4)))
    {
        ft_putstr_fd("ERROR\nNo map or no file .cub", 1);
        exit(0);
    }
    ft_read_map(argv[1], &e);
    ft_check_malloc(&e);
    ft_open_window(&e);
    return (0);
}