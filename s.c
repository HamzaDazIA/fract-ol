#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_float(char *str)
{
	int	i = 0;
	int	float_flag = 0;

	// Skip spaces
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	// Handle optional sign
	if (str[i] == '+' || str[i] == '-')
		i++;

	// Check digits and at most one dot
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (0);

	while (str[i])
	{
		if (str[i] == '.')
		{
			if (float_flag) // More than one dot is invalid
				return (0);
			float_flag = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	result = 0.0;
	double	fraction = 0.0;
	int		sign = 1;
	int		divisor = 1;
	int		i = 0;

	if (!is_float(str))
	{
		printf("Invalid float format\n");
		return (0.0); // Or handle the error properly
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
		{
			fraction = fraction * 10 + (str[i] - '0');
			divisor *= 10;
		}
		result += fraction / divisor;
	}

	return (result * sign);
}

