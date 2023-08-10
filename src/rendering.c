/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:16:20 by macarval          #+#    #+#             */
/*   Updated: 2022/10/26 15:12:24 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			data->frac.pr = data->frac.min_r + (double)x
				* (data->frac.max_r - data->frac.min_r) / WIN_W;
			data->frac.pi = data->frac.min_i + (double)y
				* (data->frac.max_i - data->frac.min_i) / WIN_H;
			if (data->type == JULIA)
				julia(data, x, y);
			else if (data->type == MANDELBROT)
				mandelbrot(data, x, y);
			else if (data->type == TRICORN)
				tricorn(data, x, y);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	int	i;

	i = 0;
	if (data->win_ptr == NULL)
		return (1);
	render_fractal(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
