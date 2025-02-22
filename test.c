#include <mlx.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100
#define N_MAX 2.0
#define N_MIN -2.0

typedef struct s_complex {
    double real;
    double i;
} t_complex;

typedef struct s_data {
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    double      zoom;
    t_complex   offset;
} t_data;

int get_color(int iter, int max_iter)
{
    if (iter == max_iter)
        return 0x000000; // Return black if inside the set

    double t = (double)iter / max_iter; // Normalize iteration count (0 to 1)

    int r = (int)(255 * t);     // Red increases from 0 to 255
    int g = (int)(255 * (1 - t)); // Green decreases from 255 to 0
    int b = (int)(255 * t * (1 - t) * 4); // Blue follows a smooth curve

    return (r << 16) | (g << 8) | b; // Combine RGB into a hex color
}


// Convert screen coordinates to complex plane
t_complex pixel_to_complex(int x, int y, t_data *data)
{
    t_complex c;
    
    // Map pixel to [-2, 2] range
    c.real = (x * (N_MAX - N_MIN) / WIDTH + N_MIN) * data->zoom + data->offset.real;
    c.i = (y * (N_MAX - N_MIN) / HEIGHT + N_MIN) * data->zoom + data->offset.i;
    
    return (c);
}

// Mandelbrot calculation
int mandelbrot(t_complex c)
{
    t_complex z = {0, 0};
    int iter = 0;

    while (z.real * z.real + z.i * z.i <= 4 && iter < MAX_ITER)
    {
        double tmp = z.real * z.real - z.i * z.i + c.real;
        z.i = 2 * z.real * z.i + c.i;
        z.real = tmp;
        iter++;
    }
    return (iter);
}

// Draw fractal to image buffer
void draw_fractal(t_data *data)
{
    int x, y;
    int *pixel;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            t_complex c = pixel_to_complex(x, y, data);
            int iter = mandelbrot(c);
            int color = get_color(iter, MAX_ITER);
            
            // Write pixel to image buffer
            pixel = (int *)(data->addr + 
                   (y * data->line_length) + 
                   (x * (data->bits_per_pixel / 8)));
            *pixel = color;
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

// Mouse hook for zooming
int mouse_hook(int button, int x, int y, t_data *data)
{
    (void)x;
    (void)y;
    
    if (button == 4)
        data->zoom *= 0.9;
    else if (button == 5)
        data->zoom *= 1.1;
    
    draw_fractal(data);
    return (0);
}

// Key hook for exit
int key_hook(int key, t_data *data)
{
    if (key == 65307) // ESC key
    {
        mlx_destroy_window(data->mlx, data->win);
        return (0);
    }
    return (0);
}

int main()
{
    t_data data;
    
    // Initialize MLX
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
                                &data.line_length, &data.endian);
    
    // Initialize view parameters
    data.zoom = 0.5;
    data.offset.real = 0;
    data.offset.i = 0.0;
    
    // Draw initial fractal
    draw_fractal(&data);
    
    // Set up hooks
    mlx_key_hook(data.win, key_hook, &data);
    mlx_mouse_hook(data.win, mouse_hook, &data);
    
    // Start main loop
    mlx_loop(data.mlx);
    
    return (0);
}