#include "../includes/ft_printf.h"

void	only_width_s(t_specs *specs, char *str, int char_count, int *length)
{
	int	spaces;

	spaces = specs->width - char_count;
	*length += spaces + char_count;
	if (specs->flag == '-')
	{
		while (char_count--)
			write(1, str++, 1);
		while (spaces--)
			write(1, " ", 1);
	}
	else
	{
		while (spaces--)
			write(1, " ", 1);
		while (char_count--)
			write(1, str++, 1);
	}
}

void	has_precision(t_specs *specs, char *str, int char_count, int *length)
{
	int	spaces;

	spaces = 0;
	if (char_count <= specs->width)
		spaces = specs->width - char_count;
	*length += spaces + char_count;
	if (specs->flag == '-')
	{
		while (char_count--)
			write(1, str++, 1);
		while (spaces--)
			write(1, " ", 1);
	}
	else
	{
		while (spaces--)
			write(1, " ", 1);
		while (char_count--)
			write(1, str++, 1);
	}
}

void	s_handler(t_specs *specs, int *length, va_list args)
{
	char	*str;
	int		str_len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	if (specs->precision < str_len && specs->precision > -1)
		has_precision(specs, str, specs->precision, length);
	else if (specs->width > str_len)
		only_width_s(specs, str, str_len, length);
	else
	{
		*length += str_len;
		while (str_len--)
			write(1, str++, 1);
	}
}
