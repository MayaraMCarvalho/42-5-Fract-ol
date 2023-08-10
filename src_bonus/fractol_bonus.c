/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:14:57 by macarval          #+#    #+#             */
/*   Updated: 2022/10/26 23:52:28 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	int			i;
	const char	*types[3] = {"mandelbrot", "julia", "tricorn"};

	i = 0;
	while (i < 3)
	{
		if (argc > 1 && !strncmp(argv[1], types[i], 20))
		{
			if (argc == 3)
				return (config_win(i, argv[2][0]));
			else
				return (config_win(i, '1'));
		}
		else if (i == 2)
		{
			perror("\nUsage: ./fractol [mandelbrot / julia / tricorn]\n\n");
			return (1);
		}
		i++;
	}
	return (0);
}
