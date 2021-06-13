#include "include/ft_printf.h"

void	make_str(t_specs *specs, int *length, va_list args)
{
	if (specs->type == 'd' || specs->type == 'i')
		d_handler(specs, length, args);
	else if (specs->type == 'u')
		u_handler(specs, length, args);
	else if (specs->type == 's')
		s_handler(specs, length, args);
	// else if (specs->type == 'p')
	// 	p_handler(specs, length, args);
	else if (specs->type == 'x' || specs->type == 'X')
		x_handler(specs, length, args);
	else if (specs->type == 'c')
		c_handler(specs, length, args);
}