#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
} 
int is_float(char *str)
{
    int i;
    int i_float;

    i_float = 0;
    
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
	if (!ft_isdigit(str[i]) && str[i] != '.')
		return (0);
    while(str[i])
    {
        if (str[i] == '.')
        {
            if (i_float)
                return (0);
            i_float = 1;
        }
        else if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

double ft_atof(char *str)
{
    int i;
    double rs2;
    double rs;
    int div;
    int sign;

	if (!is_float(str))
	{
		printf("Invalid float format\n");
		return (0.0); // Or handle the error properly
	}
    (1) && (rs = 0.0, rs2 = 0.0, sign = 1, div = 1, i = 0);
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i++] == '-')
            sign = -1;
    }
	while (ft_isdigit(str[i]))
		rs= rs * 10 + (str[i++] - '0');
    if (str[i] == '.')
    {
        while (ft_isdigit(str[++i]))
            (1) && (rs2 = rs2 * 10 + (str[i] - '0'), div *= 10);
        rs += rs2 / div;
    }
    return (rs * sign);
}

int main()
{
    char *test1 = "  -123.45";
    char *test2 = "42";
    char *test3 = "+0.987";
    char *test4 = "12.34.56"; // Invalid
    char *test5 = "abc";      // Invalid
    char *test6 = ".";        // Invalid
    char *test7 = "-.";       // Invalid
    char *test8 = "10.";      // Valid (should be 10.0)
    char *test9 = ".5";       // Valid (should be 0.5)

    printf("Result 1: %f\n", ft_atof(test1));
    printf("Result 2: %f\n", ft_atof(test2));
    printf("Result 3: %f\n", ft_atof(test3));
    printf("Result 4: %f\n", ft_atof(test4));
    printf("Result 5: %f\n", ft_atof(test5));
    printf("Result 6: %f\n", ft_atof(test6));
    printf("Result 7: %f\n", ft_atof(test7));
    printf("Result 8: %f\n", ft_atof(test8));
    printf("Result 9: %f\n", ft_atof(test9));

    return 0;
}
