/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:54:18 by acornil           #+#    #+#             */
/*   Updated: 2022/03/04 11:06:49 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_get_format(t_print *tab, const char *str, int pos)
{
	while (!(str[pos] == 'c' || str[pos] == 's' || str[pos] == 'p'
			|| str[pos] == 'd' || str[pos] == 'i' || str[pos] == 'u'
			|| str[pos] == 'x' || str[pos] == 'X' || str[pos] == '%'))
	{
		if (str[pos] == '.')
			tab->precision = 0;
		else if (str[pos] == '-')
			tab->dash = 1;
		else if (str[pos] == '0' && !ft_isdigit(str[pos - 1]))
			tab->is_zero = 1;
		else if (str[pos] == ' ')
			tab->space = 1;
		while (ft_isdigit(str[pos]))
		{
			if (tab->precision == -1)
				tab->width = tab->width * 10 + str[pos] - '0';
			else if (tab->precision > -1 || tab->is_zero)
				tab->precision = tab->precision * 10 + str[pos] - '0';
			if (ft_isdigit(str[pos + 1]))
				pos ++;
			else
				break;
		}
		pos ++;
	}
	if (str[pos] == 'c')
		ft_print_char(tab);
	else if (str[pos] == 'd' || str[pos] == 'i')
		ft_print_int(tab);
	else if (str[pos] == 's')
		ft_print_str(tab);
	else if (str[pos] == 'u')
		ft_print_uint(tab);
	else if (str[pos] == '%')
		ft_print_percent(tab);
	else if (str[pos] == 'x')
		ft_print_lowhex(tab);
	else if (str[pos] == 'X')
		ft_print_uphex(tab);
	else if (str[pos] == 'p')
		ft_print_ptr(tab);
	return (pos);
}
