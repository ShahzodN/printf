#include "../includes/ft_printf.h"



void	only_precision(t_specs *specs, char *con_int)
{
	int	zero_count;

	if (*con_int == '-')
		write(1, con_int++, 1);
	zero_count = specs->precision - get_dig_count(con_int);
	while (zero_count--)
		write(1, "0", 1);
	while (*con_int)
		write(1, con_int++, 1);
}

void	only_width(t_specs *specs, char *con_int, int dig_count)
{
	int		spaces;
	int		zero_count;
	
	spaces = specs->width - dig_count;
	zero_count = specs->width - dig_count;
	if (specs->flag == '-')
		minus_flag(0, spaces, con_int);
	else if (specs->flag == '0' && specs->precision == -1)
		zero_flag(zero_count, con_int);
	else
	{
		while (spaces--)
			write(1, " ", 1);
		while (*con_int)
			write(1, con_int++, 1);
	}
}

void	precision_in_width(t_specs *specs, char *con_int)
{
	int	spaces;
	int	zero_count;

	zero_count = specs->precision - get_dig_count(con_int);
	spaces = specs->width - zero_count - ft_strlen(con_int);
	if (specs->flag == '-')
		minus_flag(zero_count, spaces, con_int)	;
	else
	{
		while (spaces--)
			write(1, " ", 1);
		if (*con_int == '-')
			write(1, con_int++, 1);
		while (zero_count--)
			write(1, "0", 1);
		while (*con_int)
			write(1, con_int++, 1);
	}
}

void	start_print(t_specs *specs, char *con_int, int dig_count)
{
	if (specs->precision == 0 && *con_int == '0' && dig_count--)
		con_int++;
	if (specs->precision > dig_count)
	{
		if (specs->precision > specs->width)
			only_precision(specs, con_int);
		else
			precision_in_width(specs, con_int);
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
