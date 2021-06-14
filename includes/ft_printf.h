#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_specs
{
	char	flag;
	int		width;
	int		precision;
	char	type;
}				t_specs;

int		ft_printf(const char *fmt, ...);
void	parse(const char *fmt, int *length, va_list args);
void	make_str(t_specs *specs, int *length, va_list args);
void	start_print(t_specs *specs, char *con_int, int dig_count);
void	to_hex(unsigned long long n, char arr[], char type, int *i);
void	d_handler(t_specs *specs, int *length, va_list args);
void	s_handler(t_specs *specs, int *length, va_list args);
void	c_handler(t_specs *specs, int *length, va_list args);
void	u_handler(t_specs *specs, int *length, va_list args);
void	x_handler(t_specs *specs, int *length, va_list args);
void	p_handler(t_specs *specs, int *length, va_list args);
void	start_write(t_specs *specs, int *length, char *con_int, int dig_count);
#endif