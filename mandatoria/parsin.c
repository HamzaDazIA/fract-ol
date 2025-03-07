/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/03 23:51:31 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_float(char *str, int i, double v, int i_float)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (0);
	while (str[++i] && str[i] != ' ')
	{
		if (str[i] == '.')
		{
			if (i_float)
				return (0);
			i_float = 1;
		}
		else if (!(ft_isdigit(str[i])))
			return (0);
		else
			(1) && (v = v * 10 + (str[i] - '0'), chck_ovrflw(v));
	}
	while (str[i] == ' ' )
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

double	ft_atof(char *str)
{
	int		i;
	double	rs2;
	double	rs;
	int		div;
	int		sign;

	if (is_float(str, 0, 0.0, 0) == 0)
		print_usage();
	(1) && (rs = 0.0, rs2 = 0.0, sign = 1, div = 1, i = 0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		rs = rs * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
			(1) && (rs2 = rs2 * 10 + (str[i] - '0'), div *= 10);
		rs += rs2 / div;
	}
	return (rs * sign);
}

int	parsin(int ac, char **av, t_data *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
	{
		data->fractol = 1;
		data->zoom = 1.0;
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		return (1);
	}
	else if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
	{
		data->fractol = 2;
		data->zoom = 0.9;
		data->julia_n.real = ft_atof(av[2]);
		data->julia_n.imag = ft_atof(av[3]);
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		return (1);
	}
	return (0);
}
