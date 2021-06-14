#include "../includes/ft_printf.h"

void	p_handler(t_specs *specs, int *length, va_list args)
{
	unsigned long long	p_address;
	char				arr[32];
	int					i;
	int					arr_len;

	p_address = va_arg(args, unsigned long long);
	arr[0] = '0';
	arr[1] = 'x';
	i = 2;
	if (p_address == 0 && i++)
		arr[i - 1] = '0';
	to_hex(p_address, arr, specs->type, &i);
	arr[i] = 0;
	arr_len = ft_strlen(arr);
	start_print(specs, arr, arr_len);
	if (specs->width > arr_len)
		*length += specs->width;
	else
		*length += arr_len;
}
