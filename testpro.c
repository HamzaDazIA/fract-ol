#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define ZOOM_FACTOR 1.1
#define MANDELBROT 1
#define Julia    2
#define	Multibrot 3
#define N_MAX 2.0
#define N_MIN -2.0
#define MAX_ITER 100
# define ESC 53
#define WIDTH 1080
#define HEIGHT  1080 

typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data {
    void *mlx_con;
    void *mlx_win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    double zoom;
    double offset_x;
    double offset_y;
} t_data;

int multibrot(t_complex c, t_data *data)
{
    int i;
    double tmp;
    t_complex z;

    z.real = 0;
    z.imag = 0;
    i = 0;

    while (z.real * z.real + z.imag * z.imag <= 4 && i <= MAX_ITER)
    {
        tmp = (z.real * z.real * z.real) - (3 * z.real * z.imag * z.imag) + c.real;
        z.imag = (3 * z.real * z.real * z.imag) - (z.imag * z.imag * z.imag) + c.imag;
        z.real = tmp;
        i++;
    }
    return (i);
}

unsigned int get_color(int iter)
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    
    if (iter == MAX_ITER)
        return (0x042940);
        
    double t = (double)iter / MAX_ITER;  
    
    r = (unsigned int)(225 * t);
    g = (unsigned int)(225 * (1 - t));
    b = (unsigned int)(255 * t * (1 - t) * 4); 

    return (((r << 16) | (g << 8)) | b);
}
t_complex pixel_to_complex(int x, int y, t_data *data)
{
    t_complex c;
    c.real = (x - WIDTH / 2.0) * (4.0 / WIDTH) / data->zoom + data->offset_x;
    c.imag = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) / data->zoom + data->offset_y;
    return c;
}

void draw_multibrot(t_data *data)
{
    int y;
    int x;
    t_complex c;
    int iter;
    unsigned int color;
    unsigned int *pixel;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c = pixel_to_complex(x, y, data);
            iter = multibrot(c, data);
            color = get_color(iter);

            pixel = (unsigned int *)(data->addr + 
                (y * data->line_length) + (x * (data->bits_per_pixel / 8)));
            *pixel = color;
            
            x++; // Increment x
        }
        y++; // Increment y
    }
    mlx_put_image_to_window(data->mlx_con, data->mlx_win, data->img, 0, 0);
}

int handle_keys(int button, t_data *data)
{
    if (button == 4) // Scroll up (zoom in)
    {
        data->zoom *= ZOOM_FACTOR; // Increase zoom
    }
    else if (button == 5) // Scroll down (zoom out)
    {
        data->zoom *= ZOOM_FACTOR; // Decrease zoom
    }
    draw_multibrot(data);
    return (0);
}

int main()
{
    t_data data;

    data.mlx_con = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_con, WIDTH, HEIGHT, "Multibrot Set");
    data.img = mlx_new_image(data.mlx_con, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    data.zoom = 1.0;
    data.offset_x = 0.0;
    data.offset_y = 0.0;
    
    draw_multibrot(&data);
    mlx_mouse_hook(data.mlx_win, handle_keys, &data);
    mlx_loop(data.mlx_con);
    return (0);
}
