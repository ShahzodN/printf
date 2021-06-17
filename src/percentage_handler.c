#include "../includes/ft_printf.h"

void	has_width_perc(t_specs *specs)
{
	int	spaces;

	spaces = specs->width - 1;
	if (specs->flag == '-')
		minus_flag(0, spaces, "%");
	else if (specs->flag == '0')
		zero_flag(specs->width - 1, "%");
	else
	{
		while (spaces--)
			write(1, " ", 1);
		write(1, "%", 1);
	}
}

void	percentage_handler(t_specs *specs, int *length)
{
	char	*str;

	str = "%";
	if (specs->width > 1)
	{
		*length += specs->width;
		has_width_perc(specs);
	}
	
}