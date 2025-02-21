/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:06:19 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/21 13:46:00 by hdazia           ###   ########.fr       */
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

int get_color(int iter)
{
    if ()
}
void   draw_mandelbrot(t_data   *data)
{
    int x;
    int y;
    t_complex c;
    
    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c = pixel_to_complex(x, y, data);
            
        }
    }
}
void    do_fractol(t_data *data)
{
    
    if (data->fractol == Mandelbrot)
    {
        
    }
}
