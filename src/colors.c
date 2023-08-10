/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:58:50 by macarval          #+#    #+#             */
/*   Updated: 2022/10/27 01:06:19 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(t_data	*data)
{
	int	rgb_i[3];
	int	rgb_f[3];
	int	color;

	color = data->color1 * data->n_iter / MAX_ITER;
	rgb_i[0] = (data->color1 >> 16) & 0xFF;
	rgb_i[1] = (data->color1 >> 8) & 0xFF;
	rgb_i[2] = data->color1 & 0xFF;
	rgb_f[0] = (data->color2 >> 16) & 0xFF;
	rgb_f[1] = (data->color2 >> 8) & 0xFF;
	rgb_f[2] = data->color2 & 0xFF;
	rgb_i[0] = (rgb_f[0] - rgb_i[0]) * data->n_iter - rgb_i[0];
	rgb_i[1] = (rgb_f[1] - rgb_i[1]) * data->n_iter - rgb_i[1];
	rgb_i[2] = (rgb_f[2] - rgb_i[2]) * data->n_iter - rgb_i[2];
	return (0xFF << 24 | rgb_i[0] << 16 | rgb_i[1] << 8 | rgb_i[2]);
}

void	change_color(t_data	*data)
{
	if (data->click_color == 1)
	{		
		data->color1 = 0x36FF14;
		data->color2 = 0x32;
		data->click_color++;
	}
	else if (data->click_color == 2)
	{		
		data->color1 = 0xA;
		data->color2 = BG_PIXEL;
		data->click_color++;
	}
	else if (data->click_color == 3)
	{		
		data->color1 = BLACK_PIXEL;
		data->color2 = 0x5a07b8;
		data->click_color++;
	}
	else if (data->click_color == 4)
	{		
		data->color1 = BLACK_PIXEL;
		data->color2 = 0xA;
		data->click_color = 1;
	}
}
