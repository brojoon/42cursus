/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:58:19 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 11:41:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_draw_sprite(t_cub3d *cub, t_ray *ray)
{
	t_drs			*drs;

	if (!(drs = (t_drs *)malloc(sizeof(t_drs))))
		return (0);
	ft_util_bzero(drs, sizeof(t_drs));
	drs->idx = 0;
	drs->spr = ft_sprite_lst_tab(cub);
	ft_sprite_sort(cub, drs->spr, ft_util_lstsize((t_lst *)cub->spr_scr));
	while (drs->idx < ft_util_lstsize((t_lst *)cub->spr_scr))
	{
		ft_draw_sprite_make(cub, ray, drs);
		++drs->idx;
	}
	free(drs->spr);
	return (1);
}

void				ft_draw_sprite_make(t_cub3d *cub, t_ray *ray, t_drs *drs)
{
	drs->spr_pox = drs->spr[drs->idx].pox - (cub->pos->pox - 0.5);
	drs->spr_poy = drs->spr[drs->idx].poy - (cub->pos->poy - 0.5);
	ft_draw_sprite_make_calcul(cub, drs);
	while (drs->stripes < drs->end_pox)
	{
		drs->txx = (int)(cub->spr->siz *
			(drs->stripes - (-drs->spr_wid / 2 + drs->scr_pox))
			* cub->spr->wid / drs->spr_wid) / cub->spr->siz;
		if (drs->trn_poy > 0 && drs->stripes > 0 && drs->stripes < cub->wid &&
			drs->trn_poy < ray->z_buffr[drs->stripes])
		{
			drs->poy = drs->stt_poy;
			while (drs->poy < drs->end_poy)
			{
				ft_draw_sprite_make_pix(cub, drs);
				if (drs->tot_clr != 0)
					ft_draw_sprite_make_is_black(cub, drs);
				++drs->poy;
			}
		}
		++drs->stripes;
	}
}

void				ft_draw_sprite_make_calcul(t_cub3d *cub, t_drs *drs)
{
	drs->inv_det = 1.0 /
		(cub->pos->plx * cub->pos->diy - cub->pos->dix * cub->pos->ply);
	drs->trn_pox = drs->inv_det *
		(cub->pos->diy * drs->spr_pox - cub->pos->dix * drs->spr_poy);
	drs->trn_poy = drs->inv_det *
		(-cub->pos->ply * drs->spr_pox + cub->pos->plx * drs->spr_poy);
	drs->scr_pox = (int)((cub->wid / 2) * (1 + drs->trn_pox / drs->trn_poy));
	drs->spr_hei = abs((int)(cub->hei / drs->trn_poy));
	drs->stt_poy = -drs->spr_hei / 2 + ((cub->hei / 2) * cub->pos->cam);
	if (drs->stt_poy < 0)
		drs->stt_poy = 0;
	drs->end_poy = drs->spr_hei / 2 + ((cub->hei / 2) * cub->pos->cam);
	if (drs->end_poy >= cub->hei)
		drs->end_poy = cub->hei - 1;
	drs->spr_wid = abs((int)(cub->hei / drs->trn_poy));
	drs->stt_pox = -drs->spr_wid / 2 + drs->scr_pox;
	if (drs->stt_pox < 0)
		drs->stt_pox = 0;
	drs->end_pox = drs->spr_wid / 2 + drs->scr_pox;
	if (drs->end_pox >= cub->wid)
		drs->end_pox = cub->wid - 1;
	drs->stripes = drs->stt_pox;
}

void				ft_draw_sprite_make_pix(t_cub3d *cub, t_drs *drs)
{
	drs->d = drs->poy * cub->spr->siz -
		(cub->hei * cub->pos->cam) *
		(cub->spr->siz / 2) + drs->spr_hei * cub->spr->siz / 2;
	drs->txy = ((drs->d * cub->spr->hei) / drs->spr_hei) / cub->spr->siz;
	drs->tot_clr =
	cub->spr->dat[drs->txy * cub->spr->siz + drs->txx * cub->spr->bpp / 8] +
		cub->spr->dat[drs->txy * cub->spr->siz +
			drs->txx * cub->spr->bpp / 8 + 1]
		+ cub->spr->dat[drs->txy * cub->spr->siz +
			drs->txx * cub->spr->bpp / 8 + 2];
}

void				ft_draw_sprite_make_is_black(t_cub3d *cub, t_drs *drs)
{
	cub->img->dat[drs->poy * cub->img->siz +
		drs->stripes * cub->img->bpp / 8 + 0] =
			cub->spr->dat[drs->txy * cub->spr->siz +
				drs->txx * cub->spr->bpp / 8 + 0];
	cub->img->dat[drs->poy * cub->img->siz +
		drs->stripes * cub->img->bpp / 8 + 1] =
			cub->spr->dat[drs->txy * cub->spr->siz +
				drs->txx * cub->spr->bpp / 8 + 1];
	cub->img->dat[drs->poy * cub->img->siz +
		drs->stripes * cub->img->bpp / 8 + 2] =
			cub->spr->dat[drs->txy * cub->spr->siz +
				drs->txx * cub->spr->bpp / 8 + 2];
}
