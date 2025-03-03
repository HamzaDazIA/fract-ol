int	is_float(char *str)
{
	int	i_float;
	int	i;
	int	has_digit;

	i_float = 0;
	has_digit = 0;
	i = 0;
	// Skip leading whitespace
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// Check for optional sign
	if (str[i] == '-' || str[i] == '+')
		i++;
	// Check first character is a digit or dot
	if (str[i] == '.')
		i_float = 1;
	else if (ft_isdigit(str[i]))
		has_digit = 1;
	else
		return (0); // Not a digit or dot
	// Process remaining characters for number part
	i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (i_float)
				return (0); // Multiple dots
			i_float = 1;
		}
		else if (ft_isdigit(str[i]))
			has_digit = 1;
		else
			break ; // End of number part
		i++;
	}
	// Skip trailing whitespace
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// Check if all characters are processed and at least one digit is present
	return (str[i] == '\0' && has_digit);
}
