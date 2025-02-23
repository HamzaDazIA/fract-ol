#include "fractol.h"

int mandelbrot(t_complex c)
{
    t_complex z;
    int i;

    z.imag = 0;
    z.real = 0;
    i = 0;
    while (z.real * z.real + z.imag * z.imag <= 4 && i < MAX_ITER) {
        double tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag; 
        z.real = tmp;
        i++;
    }
    return i;
}

unsigned int get_color(int iter)
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    
    if (iter == MAX_ITER)
        return (0x000000);
        
    double t = (double)iter / MAX_ITER;  
    
    r = (unsigned int)(225 * t);
    g = (unsigned int)(225 * (1 - t));
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

int julia(t_complex z0, t_complex c_julia) 
{
    int iter = 0;

    while (z0.real * z0.real + z0.imag * z0.imag <= 4 && iter < MAX_ITER) {
        double tmp = z0.real * z0.real - z0.imag * z0.imag + c_julia.real;
        z0.imag = 2 * z0.real * z0.imag + c_julia.imag;
        z0.real = tmp;
        iter++;
    }
    return (iter);
}

void draw_julia(t_data *data) 
{
    int x, y;
    //data->julia_n = (t_complex){-0.4, 0.6}; 
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            t_complex z = pixel_to_complex(x, y, data);
            int iter = julia(z, data->julia_n);
            unsigned int color = get_color(iter);
            unsigned int *pixel = (unsigned int *)(data->addr + 
                (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
            *pixel = color;
        }
    }
    mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

void do_fractol(t_data *data) {
    if (data->fractol == MANDELBROT)
        draw_mandelbrot(data);
    else if (data->fractol == Julia)
        draw_julia(data);
}
