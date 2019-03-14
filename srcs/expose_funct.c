/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:18:55 by nristorc          #+#    #+#             */
/*   Updated: 2018/02/22 18:36:50 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		vertical(t_mlx *init, t_point *point, int color)
{
	mlx_pixel_put(init->mlx, init->win, point->x, point->y, color);
	point->f = 2 * point->dx - point->dy;
	point->inc_1 = 2 * (point->dx - point->dy);
	point->inc_2 = 2 * point->dx;
	point->i = 0;
	while (point->i < point->dy)
	{
		if (point->f >= 0)
		{
			point->x += point->inc_x;
			point->f += point->inc_1;
		}
		else
			point->f += point->inc_2;
		point->y += point->inc_y;
		mlx_pixel_put(init->mlx, init->win, point->x, point->y, color);
		point->i++;
	}
}

void		horizontal(t_mlx *init, t_point *point, int color)
{
	mlx_pixel_put(init->mlx, init->win, point->x, point->y, color);
	point->f = 2 * point->dy - point->dx;
	point->inc_1 = 2 * (point->dy - point->dx);
	point->inc_2 = 2 * point->dy;
	point->i = 0;
	while (point->i < point->dx)
	{
		if (point->f >= 0)
		{
			point->y += point->inc_y;
			point->f += point->inc_1;
		}
		else
			point->f += point->inc_2;
		point->x += point->inc_x;
		mlx_pixel_put(init->mlx, init->win, point->x, point->y, color);
		point->i++;
	}
}

void		line(t_matrice *m1, t_matrice *m2, t_mlx *init)
{
	t_point	*point;

	CHECK_ERROR((point = (t_point*)malloc(sizeof(t_point))));
	point->dx = m2->xd - m1->xd;
	point->dy = m2->yd - m1->yd;
	point->dx = ft_abs(point->dx);
	point->dy = ft_abs(point->dy);
	point->inc_x = (m2->xd < m1->xd) ? -1 : 1;
	point->inc_y = (m2->yd < m1->yd) ? -1 : 1;
	point->x = m1->xd;
	point->y = m1->yd;
	if (point->dx > point->dy)
		horizontal(init, point, m1->color);
	else
		vertical(init, point, m1->color);
	if (point)
	{
		free(point);
		point = NULL;
	}
}

void		draw(t_mlx *init)
{
	int		index;

	index = 0;
	while (init->tab[index])
	{
		if (init->tab[index]->zf > 3 || init->tab[index]->zf < (-3))
		{
			init->tab[index]->color = init->color_2;
		}
		else
			init->tab[index]->color = init->color_1;
		if ((index + 1) % init->max_x != 0)
			line(init->tab[index], init->tab[index + 1], init);
		if (index < ((init->max_x * init->max_y) - init->max_x))
			line(init->tab[index], init->tab[index + init->max_x], init);
		index++;
	}
}

int			expose_funct(t_mlx *init)
{
	draw(init);
	return (0);
}
