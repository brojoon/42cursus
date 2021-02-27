/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_identifier_util2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:41:36 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:46 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_identifier(t_env *e)
{
	if (e->identifier.r != 1 || e->identifier.no != 1 ||
			e->identifier.so != 1 || e->identifier.we != 1
			|| e->identifier.ea != 1 || e->identifier.s != 1
			|| e->identifier.f != 1 || e->identifier.c != 1
			|| e->identifier.m != 1)
		return (0);
	else
		return (1);
}

void		ft_parsing_line_check(char *line)
{
	int			i;

	i = 0;
	if ((line[i] != 'R' && line[i] != ' ' && line[i] != '\n'
	&& line[i] != '\0' && line[i] != 'C' && line[i] != 'F' &&
	line[i] != 'S' && line[i] != '1' && (line[i] != 'N' &&
	line[i + 1] != 'O') && (line[i] != 'S' && line[i + 1] != 'O')
	&& (line[i] != 'W' && line[i + 1] != 'E')
	&& (line[i] != 'E' && line[i + 1] != 'A')))
	{
		ft_exit("Error wrong information in maps.cub\n", -1);
	}
}

void		ft_space(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
}

int			ft_exit(char *s1, int i)
{
	printf("%s", s1);
	exit(i);
}

float		ft_power(float nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
