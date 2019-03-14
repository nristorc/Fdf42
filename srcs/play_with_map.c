/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:14:10 by nristorc          #+#    #+#             */
/*   Updated: 2018/01/25 14:35:57 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		play_with_map(t_mlx *init)
{
	int		index;

	index = 0;
	while (init->tab[index])
	{
		init->tab[index]->xf = init->tab[index]->x + (init->tab[index]->x
		* init->zoom);
		init->tab[index]->yf = init->tab[index]->y + (init->tab[index]->y
		* init->zoom);
		init->tab[index]->zf = init->tab[index]->z * init->depth;
		init->tab[index]->xd = (init->const_1 * init->tab[index]->xf)
		- (init->const_2 * init->tab[index]->yf);
		init->tab[index]->yd = (init->tab[index]->zf + ((init->const_1 / 2)
		* init->tab[index]->xf) + ((init->const_2 / 2) * init->tab[index]->yf));
		init->tab[index]->xd = ((init->tab[index]->xd * cos(init->x_rotation))
		- (init->tab[index]->yd * sin(init->x_rotation)));
		init->tab[index]->yd = ((init->tab[index]->xd * sin(init->x_rotation))
		+ (init->tab[index]->yd * cos(init->x_rotation)));
		init->tab[index]->xd += init->x_move;
		init->tab[index]->yd += init->y_move;
		index++;
	}
}
