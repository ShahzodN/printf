#include "../includes/ft_printf.h"

void	u_handler(t_specs *specs, int *length, va_list args)
{
	char	*con_int;
	int		max_len;
	int		dig_count;

	con_int = ft_itoa(va_arg(args, unsigned int));
	max_len = (int)ft_strlen(con_int);
	dig_count = max_len;
	if (specs->width > max_len || specs->precision > max_len)
	{
		if (specs->precision > specs->width)
			max_len = specs->precision;
		else
			max_len = specs->width;
	}
	*length += max_len;
	start_print(specs, con_int, dig_count);
}
