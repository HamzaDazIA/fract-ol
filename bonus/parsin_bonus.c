/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:21:56 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/01 06:42:48 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_isdigit_bonus(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_float_bonus(char *str)
{
	int		i_float;
	int		i;
	double	v;

	(1) && (i_float = 0, i = 0, v = 0.0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit_bonus(str[i]) && str[i] != '.')
		return (0);
	while (str[++i])
	{
		if (str[i] == '.')
		{
			if (i_float)
				return (0);
			i_float = 1;
		}
		else if (!(ft_isdigit_bonus(str[i])))
			return (0);
		else
			(1) && (v = v * 10 + (str[i] - '0'), chck_ovrflw_bonus(v));
	}
	return (1);
}

double	ft_atof_bonus(char *str)
{
	int		i;
	double	rs2;
	double	rs;
	int		div;
	int		sign;

	if (is_float_bonus(str) == 0)
		print_usage_bonus();
	(1) && (rs = 0.0, rs2 = 0.0, sign = 1, div = 1, i = 0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit_bonus(str[i]))
		rs = rs * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (ft_isdigit_bonus(str[++i]))
			(1) && (rs2 = rs2 * 10 + (str[i] - '0'), div *= 10);
		rs += rs2 / div;
	}
	return (rs * sign);
}

int	parsin_bonus(int ac, char **av, t_data *data)
{
	if (ft_strcmp_bonus(av[1], "mandelbrot") == 0 && ac == 2)
	{
		data->fractol = 1;
		data->zoom = 1.0;
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		return (1);
	}
	else if (ft_strcmp_bonus(av[1], "julia") == 0 && ac == 4)
	{
		data->fractol = 2;
		data->zoom = 0.9;
		data->julia_n.real = ft_atof_bonus(av[2]);
		data->julia_n.imag = ft_atof_bonus(av[3]);
		data->offset.real = 0.0;
		data->offset.imag = 0.0;
		return (1);
	}
	return (0);
}
