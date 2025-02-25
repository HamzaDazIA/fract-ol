/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:21 by hdazia            #+#    #+#             */
/*   Updated: 2025/02/25 13:25:00 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
#define FRACTOL
#ifndef WIDTH
#define WIDTH 1080
#endif
#ifndef HEIGHT
#define HEIGHT  1080 
#endif
# ifndef MANDELBROT
#  define MANDELBROT 1
# endif
#define Julia    2
#define MULTIBROT	3

#define N_MAX 2.0
#define N_MIN -2.0
#define MAX_ITER 100
// don't tract macros , if I chang the value of ESC in the companition part the window it will never be close it with esc button
# ifndef ESC
#  define ESC 53
# endif

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
# include <math.h>

typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;


typedef struct	s_data {
    void    *mlx_con;
    void    *mlx_win;
    int     fractol;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_complex	offset;
	double	zoom;
	t_complex	julia_n;
	long    end_color;
	long	start_color;
	
}				t_data;

void	print_usage(void);
int ft_strcmp(char *s1, char *s2);
int parsin(int ac, char **av, t_data  *data);
int  mlx_conialization(t_data *data);
void    do_fractol(t_data *data);
int key_events(int key, t_data *data);
int	mouse_zoom(int button, int x, int y, t_data *data);
t_complex pixel_to_complex(int x, int y, t_data *data);
double ft_atof(char *str);
int	close_window(t_data *data);
void    draw_multibrot(t_data  *data);
unsigned int get_color(int iter, t_data *data);

#endif
