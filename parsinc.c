/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/23 04:15:43 by hdazia           ###   ########.fr       */
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
        data->offset.real = 0;
        data->offset.imag = 0;
        return (1);
    }
    else if (ft_strcmp(av[1] , "julia") == 0 && ac == 4)
    {
        data->fractol = Julia;
        data->zoom = 0.5;
        data->julia_n.real =  ft_atof(av[2]);
        data->julia_n.imag = ft_atof(av[3]);
        printf("%f",  data->offset.real);
        
        return (1);
    }
    return (0);
}