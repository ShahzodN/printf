#include "include/ft_printf.h"

void	p_handler(t_specs *specs, int *length, va_list args)
{
	void	*p_address;
	char				arr[32];
	int					i;
	int					arr_len;

	p_address = va_arg(args, void *);
	if (p_address == NULL)
	{
		write(1, "null", 4);
		return ;
	}
	arr[0] = '0';
	arr[1] = 'x';
	i = 2;
	to_hex((unsigned long long)p_address, arr, specs->type, &i);
	arr[i] = 0;
	arr_len = ft_strlen(arr);
	start_print(specs, arr, arr_len);
	if (specs->width > arr_len)
		*length += specs->width;
	else
		*length += arr_len;
}
