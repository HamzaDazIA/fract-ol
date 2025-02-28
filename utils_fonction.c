/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:18:53 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/27 20:27:14 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_complex pixel_to_complex(int x, int y, t_data *data)
{
	t_complex	c;

	c.real = (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom
		+ data->offset.real;
	c.imag = (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom
		+ data->offset.imag;
    return (c);
}

int check_overflow(long long value)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		write(2, "Error: number too large\n", 24);
		exit(1);
	}
	return (1);
}