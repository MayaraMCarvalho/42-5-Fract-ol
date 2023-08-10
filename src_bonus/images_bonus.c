/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:15:36 by macarval          #+#    #+#             */
/*   Updated: 2022/10/16 15:38:15 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img(t_data	*data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr,
			WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
}

void	img_pix_put(t_data	*data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = data->img.bpp - 8;
	pixel = data->img.addr
		+ y * data->img.line_len + x * (data->img.bpp / 8);
	while (i >= 0)
	{
		if (data->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
	*(int *)pixel = color;
}
