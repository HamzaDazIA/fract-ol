/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:06:19 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/22 04:01:18 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   pixel_to_complex(int x, int y, t_data *data)
{
    t_complex c;
    
    c.real =  x * ((N_MAX - N_MIN) / (WIDTH + N_MIN)) * data->zoom + data->offcet.real;
    c.i = y * ((N_MAX - N_MIN) / (WIDTH + N_MIN)) * data->zoom + data->offcet.i;
    return (c);
    
}
int mandelbrot(t_complex c)
{
    t_complex z;
    int i;
    double tmp;
    
    i = 0;
    z.real = 0;
    z.i = 0;

    while (z.real * z.real + z.i * z.i && i < MAX_ITER) 
    {
        tmp = z.real * z.real - z.i * z.i + c.real;
        z.i = 2 * z.real * z.i + c.i;
        z.real =  tmp;
        i++;
    }
    return (i);
}

unsigned int  get_color(int iter)
{
    unsigned int r;
    unsigned int g;
    unsigned int b;

    double t = (iter / MAX_ITER);
    
    r = (unsigned int)(255 * t) ;
    g = (unsigned int)(255 * (1 - t));
    b = (unsigned int)(225 * t * (1 - t) * 4);

    return (((r << 16) | (g << 8) ) | b );
}

void   draw_mandelbrot(t_data   *data)
{
    int x;
    int y;
    t_complex c;
    unsigned int color;
    int iter;
    unsigned int *pixel;
    
    y = 0;
    while(y++ < HEIGHT)
    {
        x = 0;
        while (x++ < WIDTH)
        {
            c = pixel_to_complex(x, y, data);
            iter = mandelbrot(c);
            color = get_color(iter);
            pixel = (unsigned int *)(data->addr + (y * data->line_length) + (x * data->bits_per_pixel / 8));
            *pixel = color;
        }
    }
    mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void    do_fractol(t_data *data)
{
    
    if (data->fractol == Mandelbrot)
    {
        draw_mandelbrot(data);
    }
}
