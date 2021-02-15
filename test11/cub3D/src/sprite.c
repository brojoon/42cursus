/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:31:01 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:56:35 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_sprites_set(t_cub3d *cub, char *pth)
{
	if (!(cub->spr->img = mlx_xpm_file_to_image(cub->mlx, pth,
		&cub->spr->wid, &cub->spr->hei)))
		return (0);
	cub->spr->dat = mlx_get_data_addr(cub->spr->img, &cub->spr->bpp,
		&cub->spr->siz, &cub->spr->end);
	return (1);
}

t_spr				*ft_sprite_lst_tab(t_cub3d *cub)
{
	t_spr			*rst;
	t_spr			*sav;
	int				cnt;

	sav = cub->spr_scr;
	cnt = -1;
	if (!(rst = (t_spr *)malloc(sizeof(t_spr) *
		ft_util_lstsize((t_lst *)cub->spr_scr))))
		return (0);
	ft_util_bzero(rst, sizeof(t_spr) *
		ft_util_lstsize((t_lst *)cub->spr_scr));
	while (++cnt > -1)
	{
		if (cub->spr_scr)
		{
			rst[cnt].pox = cub->spr_scr->pox;
			rst[cnt].poy = cub->spr_scr->poy;
		}
		if (cub->spr_scr->nxt)
			cub->spr_scr = cub->spr_scr->nxt;
		else
			break ;
	}
	cub->spr_scr = sav;
	return (rst);
}

void				ft_sprite_sort(t_cub3d *cub, t_spr *spr, int num)
{
	int				idx;
	double			ds1;
	double			ds2;
	t_spr			tmp;

	idx = 0;
	while (idx < num && idx + 1 != num)
	{
		ds1 = ((cub->pos->pox - spr[idx].pox) * (cub->pos->pox - spr[idx].pox)
			+ (cub->pos->poy - spr[idx].poy) * (cub->pos->poy - spr[idx].poy));
		ds2 = ((cub->pos->pox - spr[idx + 1].pox) *
			(cub->pos->pox - spr[idx + 1].pox)
			+ (cub->pos->poy - spr[idx + 1].poy) *
			(cub->pos->poy - spr[idx + 1].poy));
		if (ds1 < ds2)
		{
			tmp = spr[idx];
			spr[idx] = spr[idx + 1];
			spr[idx + 1] = tmp;
			idx = 0;
		}
		else
			++idx;
	}
}

void				ft_sprite_next(t_spr *act, t_spr *new, t_ray *ray)
{
	while (1)
	{
		if (act->pox == ray->map_pox && act->poy == ray->map_poy)
		{
			free(new);
			break ;
		}
		if ((act->pox != ray->map_pox || act->poy != ray->map_poy) && !act->nxt)
		{
			act->nxt = new;
			break ;
		}
		if (act->nxt)
			act = act->nxt;
		else
		{
			free(new);
			break ;
		}
	}
}

void				ft_sprite(t_cub3d *cub, t_ray *ray)
{
	t_spr			*new;
	t_spr			*act;

	if (!(new = (t_spr *)malloc(sizeof(t_spr))))
		return ;
	new->nxt = NULL;
	new->pox = ray->map_pox;
	new->poy = ray->map_poy;
	act = cub->spr_scr;
	if (act->pox == -1 && act->poy == -1)
	{
		act->pox = ray->map_pox;
		act->poy = ray->map_poy;
	}
	else
		ft_sprite_next(act, new, ray);
}
