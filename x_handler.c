#include "include/ft_printf.h"

char	int_to_hex(unsigned int x, char c)
{
	if (x > 9)
	{
		if (c == 'X')
			return (55 + x);
		else
			return (87 + x);
	}
	return ('0' + x);
}

void	to_hex(unsigned long long n, char arr[], char type, int *i)
{
	if (n == 0)
		return ;
	else
	{
		to_hex(n / 16, arr, type, i);
		arr[*i] = int_to_hex(n % 16, type);
		(*i)++;
	}
}

void	x_handler(t_specs *specs, int *length, va_list args)
{
	unsigned int	value;
	char			arr[32];
	int				i;
	int				arr_len;

	i = 0;
	value = va_arg(args, unsigned int);
	to_hex(value, arr, specs->type, &i);
	arr[i] = 0;
	arr_len = (int)ft_strlen(arr);
	if (specs->width > arr_len)
		*length += specs->width;
	else
		*length += arr_len;
	start_print(specs, arr, arr_len);
}