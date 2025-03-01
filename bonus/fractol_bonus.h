/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:15:21 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 06:51:43 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H_BONUS
# define FRACTOL_H_BONUS

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# ifndef N_MAX
#  define N_MAX 2.0
# endif

# ifndef N_MIN
#  define N_MIN -2.0
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
#include <limits.h>

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	void			*mlx_con;
	void			*mlx_win;
	int				fractol;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_complex		offset;
	double			zoom;
	t_complex		julia_n;
	int				number;
	unsigned int	color;
}				t_data;

void		print_usage_bonus(void);
int			ft_strcmp_bonus(char *s1, char *s2);
int			parsin_bonus(int ac, char **av, t_data *data);
int			mlx_initialization_bonus(t_data *data);
void		do_fractol_bonus(t_data *data);
int			key_events_bonus(int key, t_data *data);
int			mouse_zoom_bonus(int button, int x, int y, t_data *data);
t_complex	pixel_to_complex_bonus(int x, int y, t_data *data);
int			close_window_bonus(t_data *data);
int			mandelbrot_bonus(t_complex c);
int			julia_bonus(t_complex z0, t_complex c_julia);
int			multibrot_bonus(t_complex c);
int			chck_ovrflw_bonus(long long value);

#endif