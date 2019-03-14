/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:09:30 by nristorc          #+#    #+#             */
/*   Updated: 2018/01/25 18:42:50 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		reload(t_mlx *init)
{
	mlx_clear_window(init->mlx, init->win);
	display_control(init);
	play_with_map(init);
	expose_funct(init);
}

void		change_colors(int keycode, t_mlx *init)
{
	if (keycode == KEYBOARD_W)
		init->color_1 = COLOR_WHITE;
	if (keycode == KEYBOARD_B)
		init->color_1 = COLOR_BLUE;
	if (keycode == KEYBOARD_R)
		init->color_1 = COLOR_RED;
	if (keycode == KEYBOARD_G)
		init->color_1 = COLOR_GREEN;
	if (keycode == KEYBOARD_H)
		init->color_2 = COLOR_WHITE;
	if (keycode == KEYBOARD_Y)
		init->color_2 = COLOR_YELLOW;
	if (keycode == KEYBOARD_C)
		init->color_2 = COLOR_CYAN;
	if (keycode == KEYBOARD_P)
		init->color_2 = COLOR_PINK;
}

void		keyboard_moves(int keycode, t_mlx *init)
{
	if (keycode == KEYBOARD_ZOOM_IN)
		init->zoom += 3;
	if (keycode == KEYBOARD_ZOOM_OUT)
		init->zoom -= 3;
	if (keycode == KEYBOARD_ARROW_LEFT)
		init->x_move -= 30;
	if (keycode == KEYBOARD_ARROW_RIGHT)
		init->x_move += 30;
	if (keycode == KEYBOARD_ARROW_UP)
		init->y_move += 30;
	if (keycode == KEYBOARD_ARROW_DOWN)
		init->y_move -= 30;
	if (keycode == KEYBOARD_DEPTH_UP)
		init->depth += 1;
	if (keycode == KEYBOARD_DEPTH_DOWN)
		init->depth -= 1;
	if (keycode == KEYBOARD_ROT_LEFT)
		init->x_rotation += 0.1;
	if (keycode == KEYBOARD_ROT_RIGHT)
		init->x_rotation -= 0.1;
}

void		free_array_tab(t_mlx *init)
{
	int	i;

	i = 0;
	while (init->array[i])
	{
		free(init->array[i]);
		i++;
	}
	free(init->array);
	i = 0;
	while (init->tab[i])
	{
		free(init->tab[i]);
		i++;
	}
	free(init->tab);
	free(init);
}

int			keyboard_actions(int keycode, t_mlx *init)
{
	change_colors(keycode, init);
	keyboard_moves(keycode, init);
	if (keycode == KEYBOARD_ESC)
	{
		mlx_clear_window(init->mlx, init->win);
		free_array_tab(init);
		exit(0);
	}
	if (keycode == KEYBOARD_INC_LENGHT)
		init->const_1 += 0.1;
	if (keycode == KEYBOARD_DEC_LENGHT)
		init->const_1 -= 0.1;
	if (keycode == KEYBOARD_INC_HEIGHT)
		init->const_2 += 0.1;
	if (keycode == KEYBOARD_DEC_HEIGHT)
		init->const_2 -= 0.1;
	reload(init);
	return (0);
}
