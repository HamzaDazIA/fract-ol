#include "fractol.h"

t_complex pixel_to_complex(int x, int y, t_data *data)
{
    t_complex c;
    
    c.real = (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom + data->offset.real;
    c.imag = (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom + data->offset.imag;
    
    return (c);
}

int mandelbrot(t_complex c)
{
    t_complex z = {0, 0};
    int i = 0;
    while (z.real * z.real + z.imag * z.imag <= 4 && i < MAX_ITER) {
        double tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag; 
        z.real = tmp;
        i++;
    }
    return i;
}

unsigned int get_color(int iter) {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    
    if (iter == MAX_ITER)
        return (0x000000);
        
    double t = (double)iter / MAX_ITER;  
    
    r = (unsigned int)(255 * t);
    g = (unsigned int)(255 * (1 - t));
    b = (unsigned int)(255 * t * (1 - t) * 4); 

    return (((r << 16) | (g << 8)) | b);
}

void draw_mandelbrot(t_data *data) {
    int x;
    int y;
    t_complex c;
    unsigned int color;
    int iter;
    unsigned int *pixel;

    y = -1;
    while (++y < HEIGHT) {
        x = -1;
        while (++x < WIDTH) {
            c = pixel_to_complex(x, y, data);
            iter = mandelbrot(c);
            color = get_color(iter);
            pixel = (unsigned int *)(data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
            *pixel = color;
        }
    }
    mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void do_fractol(t_data *data) {
    if (data->fractol == MANDELBROT)
        draw_mandelbrot(data);
}
