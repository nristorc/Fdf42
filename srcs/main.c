/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2018/01/25 18:43:04 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_mlx	*init;
	char	**str;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments - Usage: ./fdf [map.fdf]", 2);
		exit(0);
	}
	CHECK_ERROR((init = (t_mlx*)malloc(sizeof(t_mlx))));
	set_variables(init);
	display_control(init);
	str = convert_to_array(argv[1]);
	set_map_dimensions(init, str);
	convert_str_int(argv[1], init);
	init->tab = set_tab_coord(init);
	play_with_map(init);
	mlx_hook(init->win, 2, 3, keyboard_actions, init);
	mlx_expose_hook(init->win, expose_funct, init);
	mlx_loop(init->mlx);
	return (0);
}
