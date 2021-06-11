#include "include/ft_printf.h"

void	make_str(t_specs *specs, int *length, va_list args)
{
	if (specs->type == 'd' || specs->type == 'i')
		d_handler(specs, length, args);
}