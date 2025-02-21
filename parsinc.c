/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsinc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/20 22:08:33 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int parsin(int ac, char **av, t_data  *data)
{
    if((ft_strcmp(av[1], "Mandelbrot") == 0) && ac == 2 )
    {
        //do Mandelbrot
        (*data).fractol = Mandelbrot;
        return (1);
    }

    data->zoom = 1.0;
    data->offcet.i = 0;
    data->offcet.real = 0;
     
    return (0);
    
}