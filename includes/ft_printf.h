#ifndef FT_PRINTF
# define FT_PRINTF
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	bool	is_num;
	bool	dash;
	int		length;
	bool	sign;
	bool	is_zero;
	bool	percentage;
	bool	space;
}	t_print;

int	ft_printf(const char *format, ...);
int	ft_get_format(t_print *tab, const char *str, int pos);
void	ft_right_indent(t_print *tab, int len_elem);
void	ft_left_indent(t_print *tab, int len_elem);
void	ft_print_char(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_uint(t_print *tab);
void	ft_print_str(t_print *tab);
void 	ft_print_ptr(t_print *tab);
void	ft_print_lowhex(t_print *tab);
void	ft_print_uphex(t_print *tab);
void	ft_print_percent(t_print *tab);
int	ft_get_ndigits(int num);
int	ft_get_factor(unsigned int num);
void	ft_reset_tab(t_print *tab);
void	ft_format_precision(t_print *tab, int len_elem);

#endif
