/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:21:17 by macarval          #+#    #+#             */
/*   Updated: 2022/10/27 01:08:11 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MLX_ERROR 1

/* Window */
# define WIN_W 600
# define WIN_H 600
# define MAX_ITER 500

/* Events */
# define LEFT_CLICK 1
# define MIDDLE_CLICK 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* Models */
# define MANDELBROT 0
# define JULIA 1
# define TRICORN 2

/* Colors */
# define BLACK_PIXEL 0x000000
# define BG_PIXEL 0x00FFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	pr;
	double	pi;
	double	zr;
	double	zi;	
}	t_fractol;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fractol	frac;
	int			type;
	int			j_type;
	int			click_color;
	int			color1;
	int			color2;
	int			n_iter;
}	t_data;

/* Window */
void	create_win(t_data *data);
int		close_window(t_data *data);
void	set_variables(t_data *data);
int		config_win(int type, int j_type);

/* Images */
void	create_img(t_data *data);
void	img_pix_put(t_data *data, int x, int y, int color);

/* Rendering */
int		render(t_data *data);
void	render_fractal(t_data *data);

/* Models */
int		calc_frac(t_data *data);
void	julia(t_data *data, int x, int y);
void	tricorn(t_data *data, int x, int y);
void	mandelbrot(t_data *data, int x, int y);
void	create_frac(t_data	*data, int x, int y);

/* Colors */
int		get_color(t_data *data);
void	change_color(t_data	*data);

/* Events */
void	zoom_frac(double zoom, t_data *data);
void	move_zoom(int x, int y, t_data	*data);
int		handle_keypress(int keysym, t_data *data);
void	move_frac(int keysym, t_data *data, double dist);
int		handle_mouse(int button, int x, int y, t_data *data);

/* Libft */
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);

#endif