#include "include/ft_printf.h"

void	c_handler(t_specs *specs, int *length, va_list args)
{
	char character[2];

	character[0] = va_arg(args, int);
	character[1] = 0;
	*length += 1;
	start_print(specs, character, 1);
}
