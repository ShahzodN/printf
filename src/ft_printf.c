#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		length;

	va_start(args, fmt);
	length = 0;
	parse(fmt, &length, args);
	va_end(args);
	return (length);
}
