/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:18:53 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/26 01:15:51 by hdazia           ###   ########.fr       */
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
    t_complex c;

    // Calculate the visible range based on zoom
    double range_real = (N_MAX - N_MIN) / data->zoom;
    double range_imag = (N_MAX - N_MIN) / data->zoom;

    // Map pixel (x, y) to the complex plane centered at data->offset
    c.real = ((double)x / WIDTH) * range_real + (data->offset.real - range_real / 2);
    c.imag = ((double)y / HEIGHT) * range_imag + (data->offset.imag - range_imag / 2);

    return (c);
}