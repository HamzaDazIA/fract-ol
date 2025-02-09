#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>


#define HIGHT 500
#define WIDTH 500
int main()
{
    void *mlx_ptr;
    void *win;
    int y  = 0;
    int x = 0;
    // Initialize MLX
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        printf("Error: Failed to initialize MiniLibX.\n");
        return (1);
    }

    // Create Window
    win = mlx_new_window(mlx_ptr, HIGHT, WIDTH, "Hamza");
    if (!win)
    {
        printf("Error: Failed to create window.\n");
        return (1);
    }


    while (++y < HIGHT )
    {
        x = 0;
        while (++x < WIDTH)
            mlx_pixel_put(mlx_ptr, win, x, y, rand() % 0x1f0000);
    }
    // Enter the event loop (infinite loop)
    mlx_string_put(mlx_ptr, win, HIGHT * 0.9 , WIDTH * 0.9, 0xF9CB43, "Hamza dazia");
    mlx_loop(mlx_ptr);

    return (0);
}
