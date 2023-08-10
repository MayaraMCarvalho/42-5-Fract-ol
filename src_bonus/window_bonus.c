/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:17:55 by macarval          #+#    #+#             */
/*   Updated: 2022/10/26 23:15:48 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	config_win(int type, int j_type)
{
	t_data		data;

	data.type = type;
	data.j_type = j_type;
	data.mlx_ptr = mlx_init();
	set_variables(&data);
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "*Fract-ol_42*");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	create_img(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &close_window, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

void	set_variables(t_data *data)
{
	if (data->type == JULIA)
	{
		data->frac.min_r = -2.0;
		data->frac.max_r = 2.0;
		data->frac.min_i = -2.0;
	}
	else
	{
		data->frac.min_r = -2.0;
		data->frac.max_r = 1.0;
		data->frac.min_i = -1.5;
	}
	data->frac.max_i = data->frac.min_i
		+ (data->frac.max_r - data->frac.min_r) * WIN_H / WIN_W;
	data->color1 = BLACK_PIXEL;
	data->color2 = 0xA;
	data->click_color = 1;
}

int	close_window(t_data	*data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
