/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/22 06:08:39 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int parsin(int ac, char **av, t_data  *data)
{
    if (ac < 2)
        return (0);
    if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
    {
        data->fractol = MANDELBROT;
        data->zoom = 0.6;
        data->offset.real = -0.5;
        data->offset.imag = 0.0;
        return (1);
    }
    return (0);
}