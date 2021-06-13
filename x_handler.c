#include "include/ft_printf.h"

char	get_hex(unsigned int x, char c)
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

void	recursion(unsigned int value, char arr[], char c, int *i)
{
	if (value == 0)
		return ;
	else
	{
		recursion(value / 16, arr, c, i);
		arr[*i] = get_hex(value % 16, c);
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
	recursion(value, arr, specs->type, &i);
	arr[i] = 0;
	arr_len = ft_strlen(arr);
	if (specs->width > arr_len)
		*length += specs->width;
	else
		*length += arr_len;
	start_print(specs, arr, ft_strlen(arr));
}