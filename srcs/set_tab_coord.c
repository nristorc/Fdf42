/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:45:10 by nristorc          #+#    #+#             */
/*   Updated: 2018/01/19 13:31:11 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		adjustment(t_matrice **tab, t_map *map, t_mlx *init)
{
	t_matrice	*point;

	CHECK_ERROR((point = (t_matrice*)malloc(sizeof(t_matrice))));
	point->x = map->x;
	point->y = map->y;
	point->z = init->array[map->y][map->x];
	tab[map->index] = point;
	map->index++;
	map->x++;
}

t_matrice	**set_tab_coord(t_mlx *init)
{
	t_matrice	**tab;
	t_map		map;

	map.index = 0;
	map.y = 0;
	CHECK_ERROR((tab = (t_matrice**)malloc(sizeof(t_matrice) * init->max_x *
		init->max_y)));
	while (map.y < init->max_y)
	{
		map.x = 0;
		while (map.x < init->max_x)
			adjustment(tab, &map, init);
		map.y++;
	}
	tab[map.index] = NULL;
	return (tab);
}
