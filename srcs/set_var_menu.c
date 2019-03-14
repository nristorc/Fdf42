/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:00:55 by nristorc          #+#    #+#             */
/*   Updated: 2018/02/01 10:43:37 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_variables(t_mlx *init)
{
	init->zoom = 17;
	init->x_move = WIN_WIDTH / 2;
	init->y_move = WIN_HEIGHT / 2;
	init->depth = -2;
	init->color_1 = COLOR_BLUE;
	init->color_2 = COLOR_PINK;
	init->const_1 = 1;
	init->const_2 = 2;
	init->value_x = 0;
	init->value_y = 0;
	init->x_rotation = 0;
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF NR");
}

void		display_control(t_mlx *init)
{
	mlx_string_put(init->mlx, init->win, 5, 125, COLOR_WHITE,
	"Color_Basis: W = White, B = Blue, R = Red, G = Green");
	mlx_string_put(init->mlx, init->win, 5, 145, COLOR_WHITE,
	"Color_Altitude: H = White, Y = Yellow, C = Cyan, P = Pink");
	mlx_string_put(init->mlx, init->win, 5, 25, COLOR_WHITE,
	"Moves: Directional Arrows");
	mlx_string_put(init->mlx, init->win, 5, 5, COLOR_WHITE,
	"Zoom In & Out: + & -");
	mlx_string_put(init->mlx, init->win, 5, 65, COLOR_WHITE,
	"Increase & Decrease Depth: < & >");
	mlx_string_put(init->mlx, init->win, 5, 85, COLOR_WHITE,
	"Increase & Decrease Lenght: 4 & 6");
	mlx_string_put(init->mlx, init->win, 5, 105, COLOR_WHITE,
	"Increase & Decrease Height: 8 & 2");
	mlx_string_put(init->mlx, init->win, 5, 45, COLOR_WHITE,
	"Rotation X axis: 1 & 0");
}
