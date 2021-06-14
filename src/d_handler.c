#include "../includes/ft_printf.h"

void	only_precision(t_specs *specs, char *con_int, int dig_count)
{
	int	zero_count;

	zero_count = specs->precision - dig_count;
	while (zero_count--)
		write(1, "0", 1);
	while (*con_int)
		write(1, con_int++, 1);
}

void	only_width(t_specs *specs, char *con_int, int dig_count)
{
	int		spaces;
	char	c;

	if (specs->flag == '0')
		c = '0';
	else if (specs->flag != '-')
		c = ' ';
	spaces = specs->width - dig_count;
	if (specs->flag == '-')
	{
		while (*con_int)
			write(1, con_int++, 1);
		while (spaces--)
			write(1, " ", 1);
	}
	else
	{
		while (spaces--)
			write(1, &c, 1);
		while (*con_int)
			write(1, con_int++, 1);
	}
}

void	precision_in_width(t_specs *specs, char *con_int, int dig_count)
{
	int	spaces;
	int	zero_count;

	spaces = specs->width - specs->precision;
	zero_count = specs->precision - dig_count;
	if (specs->flag == '-')
	{
		while (zero_count--)
			write(1, "0", 1);
		while (*con_int)
			write(1, con_int++, 1);
		while (spaces--)
			write(1, " ", 1);
	}
	else
	{
		while (spaces--)
			write(1, " ", 1);
		while (zero_count--)
			write(1, "0", 1);
		while (*con_int)
			write(1, con_int++, 1);
	}
}

void	start_print(t_specs *specs, char *con_int, int dig_count)
{
	if (specs->precision > dig_count)
	{
		if (specs->precision > specs->width)
			only_precision(specs, con_int, dig_count);
		else
			precision_in_width(specs, con_int, dig_count);
	}
	else if (specs->width > dig_count)
		only_width(specs, con_int, dig_count);
	else
		while (dig_count--)
			write(1, con_int++, 1);
}

void	d_handler(t_specs *specs, int *length, va_list args)
{
	char	*con_int;
	int		max_len;
	int		dig_count;

	con_int = ft_itoa(va_arg(args, int));
	max_len = ft_strlen(con_int);
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
