#include "include/ft_printf.h"

void	set_type(t_specs *specs, const char **fmt, va_list args)
{
	if (**fmt)
		specs->type = **fmt;
	(*fmt)++;
}

void	set_precision(t_specs *specs, const char **fmt, va_list args)
{
	specs->precision = -1;
	if (**fmt == '.')
	{
		specs->precision = 0;
		(*fmt)++;
		if (**fmt == '*')
			specs->precision = va_arg(args, int);
		while (ft_isdigit(**fmt))
		{
			specs->precision = specs->precision * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	set_type(specs, fmt, args);
}

void	set_width(t_specs *specs, const char **fmt, va_list args)
{
	specs->width = 0;
	if (**fmt == '*')
	{
		specs->width = va_arg(args, int);
		(*fmt)++;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			specs->width = specs->width * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	set_precision(specs, fmt, args);
}

void	set_flag(t_specs *specs, const char **fmt, va_list args)
{
	if (**fmt && (**fmt == '-' || **fmt == '0'))
	{
		specs->flag = **fmt;
		(*fmt)++;
	}
	set_width(specs, fmt, args);
}

void	parse(const char *fmt, int *length, va_list args)
{
	t_specs	specs;

	while (*fmt)
	{
		if (*fmt == '%' && *++fmt != '%')
		{
			set_flag(&specs, &fmt, args);
			make_str(&specs, length, args);
		}
		else
		{
			write(1, fmt++, 1);
			(*length)++;
		}
	}
}