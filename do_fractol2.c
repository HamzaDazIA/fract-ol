/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:13:13 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/24 21:44:37 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int multibrot(t_complex c)
{
    int i;
    double  tmp;
    t_complex z;
    
    z.real = 0;
    z.imag = 0;
    i = 0;

    while(z.real * z.real + z.imag * z.imag <= 4 && i <= MAX_ITER)
    {
        tmp = (z.real * z.real * z.real) - (3 * z.real * z.imag * z.imag) + c.real;
        z.imag = (3 * z.real * z.real * z.imag) - (z.imag * z.imag * z.imag) + c.imag;
        z.real = tmp;
        i++;
    }
    return (i);        
}

void    draw_multibrot(t_data  *data)
{
    int x;
    int y;
    t_complex c;
    unsigned int color;
    int iter;
    unsigned int *pixel;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            c = pixel_to_complex(x, y, data);
            iter = multibrot(c);
            color = get_color(iter, data);
            pixel = (unsigned int *)(data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
            *pixel = color;
        }
    }
    mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}
