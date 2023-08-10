/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:46:08 by macarval          #+#    #+#             */
/*   Updated: 2022/09/23 22:48:12 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		s++;
		r++;
	}
	return (r);
}
