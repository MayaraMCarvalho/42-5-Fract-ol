/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:40:39 by macarval          #+#    #+#             */
/*   Updated: 2022/10/26 23:12:31 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *data, int x, int y)
{
	data->frac.zr = data->frac.pr;
	data->frac.zi = data->frac.pi;
	if (data->j_type == '2')
	{
		data->frac.pr = -0.100000;
		data->frac.pi = -0.651000;
	}
	else if (data->j_type == '3')
	{
		data->frac.pr = 0.096667;
		data->frac.pi = -0.613333;
	}
	else if (data->j_type == '4')
	{
		data->frac.pr = -1.250000;
		data->frac.pi = 0.000000;
	}
	else
	{
		data->frac.pr = -0.766667;
		data->frac.pi = -0.090000;
	}
	create_frac(data, x, y);
}

void	mandelbrot(t_data *data, int x, int y)
{
	data->frac.zr = 0;
	data->frac.zi = 0;
	create_frac(data, x, y);
}

void	tricorn(t_data *data, int x, int y)
{
	data->frac.zr = data->frac.pr;
	data->frac.zi = data->frac.pi;
	create_frac(data, x, y);
}

void	create_frac(t_data	*data, int x, int y)
{
	if (calc_frac(data) == 1)
		img_pix_put(data, x, y, BLACK_PIXEL);
	else
		img_pix_put(data, x, y, get_color(data));
}

int	calc_frac(t_data	*data)
{
	double	tmp;

	data->n_iter = 0;
	while (data->n_iter < MAX_ITER)
	{
		if ((data->frac.zr * data->frac.zr
				+ data->frac.zi * data->frac.zi) > 4.0)
			return (0);
		if (data->type == TRICORN)
			tmp = (-2) * data->frac.zr * data->frac.zi + data->frac.pi;
		else
			tmp = 2 * data->frac.zr * data->frac.zi + data->frac.pi;
		data->frac.zr = data->frac.zr * data->frac.zr
			- data->frac.zi * data->frac.zi + data->frac.pr;
		data->frac.zi = tmp;
		data->n_iter++;
	}
	return (1);
}
