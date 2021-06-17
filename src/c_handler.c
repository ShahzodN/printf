#include "../includes/ft_printf.h"

void	has_width_c(t_specs *specs, int character)
{
	int	spaces;

	spaces = specs->width - 1;
	if (specs->flag == '-')
	{
		write(1, &character, 1);
		while (spaces--)
			write(1, " ", 1);
	}
	else
	{
		while (spaces--)
			write(1, " ", 1);
		write(1, &character, 1);
	}
}

void	c_handler(t_specs *specs, int *length, va_list args)
{
	int	character;

	character = va_arg(args, int);
	if (specs->width > 0)
	{
		*length += specs->width;
		has_width_c(specs, character);
	}
	else
	{
		*length += 1;
		write(1, &character, 1);
	}
}
