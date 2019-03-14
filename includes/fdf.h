/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:16:04 by nristorc          #+#    #+#             */
/*   Updated: 2018/01/25 18:41:02 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

# define CHECK_ERROR(x) if (!x) error();
# define CHECK_NULL(x) if (x == NULL) error();

# define FDF_BUFF_SIZE 4096

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED  0xFF0000
# define COLOR_BLUE 0x0000FF
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_PINK 0xFF00FF
# define COLOR_CYAN 0x00FFFF
# define COLOR_ORANGE 0xFF90FF
# define COLOR_PURPLE 0xA437FF

# define KEYBOARD_ESC 53
# define KEYBOARD_W 13
# define KEYBOARD_B 11
# define KEYBOARD_R 15
# define KEYBOARD_G 5
# define KEYBOARD_H 4
# define KEYBOARD_Y 16
# define KEYBOARD_C 8
# define KEYBOARD_P 35
# define KEYBOARD_ARROW_LEFT 123
# define KEYBOARD_ARROW_RIGHT 124
# define KEYBOARD_ARROW_UP 125
# define KEYBOARD_ARROW_DOWN 126
# define KEYBOARD_ZOOM_IN 69
# define KEYBOARD_ZOOM_OUT 78
# define KEYBOARD_DEPTH_UP 47
# define KEYBOARD_DEPTH_DOWN 43
# define KEYBOARD_INC_LENGHT 86
# define KEYBOARD_DEC_LENGHT 88
# define KEYBOARD_INC_HEIGHT 91
# define KEYBOARD_DEC_HEIGHT 84
# define KEYBOARD_ROT_LEFT 83
# define KEYBOARD_ROT_RIGHT 82

typedef struct		s_point
{
	int				dx;
	int				dy;
	int				i;
	int				f;
	int				inc_1;
	int				inc_2;
	int				inc_x;
	int				inc_y;
	int				cumul;
	int				x;
	int				y;
}					t_point;

typedef struct		s_map
{
	int				fd;
	char			*line;
	int				x;
	int				y;
	int				index;
}					t_map;

typedef struct		s_matrice
{
	double			x;
	double			xd;
	double			xf;
	double			y;
	double			yd;
	double			yf;
	double			z;
	double			zf;
	int				color;
}					t_matrice;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				depth;
	double			const_1;
	double			const_2;
	int				value_x;
	int				value_y;
	int				max_x;
	int				max_y;
	int				**array;
	char			**str;
	int				zoom;
	int				x_move;
	int				y_move;
	double			x_rotation;
	int				color_1;
	int				color_2;
	t_matrice		**tab;
}					t_mlx;

void				error(void);
void				set_variables(t_mlx *init);
void				display_control(t_mlx *init);
char				**convert_to_array(char *argv);
void				set_map_dimensions(t_mlx *init, char **str);
void				convert_str_int(char *argv, t_mlx *init);
t_matrice			**set_tab_coord(t_mlx *init);
void				play_with_map(t_mlx *init);
int					keyboard_actions(int keycode, t_mlx *init);
int					expose_funct(t_mlx *init);

#endif
