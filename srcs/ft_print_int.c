/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:39:48 by acornil           #+#    #+#             */
/*   Updated: 2022/03/04 12:19:30 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int num;
	int ndigits;

	num = va_arg(tab->args, int);
	ndigits = ft_get_ndigits(num);
	tab->is_num = true;
	if (tab->is_zero)
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if ((tab->width > 0 || tab->precision > 0) && !tab->dash)
	{
		if (num < 0)
		{	
			tab->sign = 1;
			num = -num;
			if (tab->precision > 0 && !tab->is_zero)
				ndigits --;
		}
		ft_right_indent(tab, ndigits);
	}
	tab->length += ndigits;
	ft_putnbr_fd(num, 1);
	if (tab->width > 0 && tab->dash)
	{
		ft_format_precision(tab, ndigits);
		ft_left_indent(tab, tab->length);	
	}
	ft_reset_tab(tab);
}
