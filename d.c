int	is_float(char *str)
{
	int	i_float;
	int	i;
	double value;
	
	(1) && (i_float = 0, i = 0, value = 0.0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (0);
	while (str[i] && str[i] != ' ')
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
			(1) && (value = value * 10 + (str[i] - '0'), check_overflow(value));
		i++;
	}
	while(str[i])
	{
		if(str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
