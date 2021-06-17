#include "../includes/ft_printf.h"

void	percentage_handler(t_specs *specs, int *length)
{

	int		spaces;
	char	*str;

	str = "%";
	*length += 1;
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