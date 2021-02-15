/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:26:41 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/08 19:44:58 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
    t_env   e;
    int     len;

    ft_bzero(&e, sizeof(t_env));
    // if (argv[2] && !ft_strcmp(argv[2], "--save") && argc < 4)
    // {
    //     ft_read_map(argv, &e);
    // }
    if (argc < 2 || argc > 2)
    {
        ft_putstr("Error\nNumbers of argc incorrect");
        ft_exit_before(&e);
    }
    len = (ft_strlen(argv[1]) - 4);
    ft_read_map(argv, &e);
    if (!argv[1] || (ft_strncmp(argv[1] + len, ".cub", 4)))
    {
        ft_putstr("ERROR\nNo map or no file .cub");
        ft_exit_before(&e);
    }
    ft_check_malloc(&e);
    ft_open_window(&e);
    return (0);
}