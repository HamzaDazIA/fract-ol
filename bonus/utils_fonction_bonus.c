/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fonction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:18:53 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 06:10:53 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_complex	pixel_to_complex(int x, int y, t_data *data)
{
	t_complex	c;
	double		scale_x;
	double		scale_y;

	scale_x = (N_MAX - N_MIN) / WIDTH;
	scale_y = (N_MAX - N_MIN) / HEIGHT;
	c.real = (x * scale_x + N_MIN) * data->zoom + data->offset.real;
	c.imag = ((HEIGHT - 1 - y) * scale_y + N_MIN) * data->zoom
		+ data->offset.imag;
	return (c);
}

int	chck_ovrflw(long long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		write(2, "Error: number too large\n", 24);
		exit(1);
	}
	return (1);
}
