#include "../includes/ft_printf.h"

int	get_dig_count(char *con_int)
{
	int	i;

	i = 0;
	while (*con_int)
	{
		if (*con_int != '-')
			i++;
		con_int++;
	}
	return (i);
}

void	zero_flag(int zero_count, char *con_int)
{
	if (*con_int == '-')
		write(1, con_int++, 1);
	while (zero_count--)
		write(1, "0", 1);
	while (*con_int)
		write(1, con_int++, 1);
}

void	minus_flag(int zero_count, int spaces, char *con_int)
{
	if (*con_int == '-' && con_int++)
		write(1, "-", 1);
	while (zero_count--)
		write(1, "0", 1);
	while (*con_int)
		write(1, con_int++, 1);
	while (spaces--)
		write(1, " ", 1);
}