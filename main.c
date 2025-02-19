#include "fractol.h"


int main(int argc, char **argv)
{
    t_data  data;

    if (!idef_mlx(&data))
    {
        write(2, "I have a Error with  initializing MiniLibX \n", 46);
        return(1);
    }

    
}