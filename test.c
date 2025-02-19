#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

typedef struct s_data {
    void    *mlx;
    void    *win;
} t_data;

int mandelbrot(double cr, double ci) {
    double zr = 0;
    double zi = 0;
    int i = 0;

    while (zr * zr + zi * zi < 4 && i < MAX_ITER) {
        double temp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return i;
}

void render_fractal(t_data *data) {
    int x, y;
    double scale = 4.0 / WIDTH;  // Adjust zoom

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double cr = (x - WIDTH / 2) * scale;
            double ci = (y - HEIGHT / 2) * scale;
            int iter = mandelbrot(cr, ci);

            int color = (iter == MAX_ITER) ? 0x000000 : (0xFFFFFF * iter / MAX_ITER);
            mlx_pixel_put(data->mlx, data->win, x, y, color);
        }
    }
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");

    render_fractal(&data);
    mlx_loop(data.mlx);

    return 0;
}
