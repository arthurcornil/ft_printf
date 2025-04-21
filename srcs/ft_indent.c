/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:54:36 by acornil           #+#    #+#             */
/*   Updated: 2022/03/04 12:33:53 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_format_precision(t_print *tab, int len_elem)
{
	if (tab->sign)
		tab->length += write(1, "-", 1);
	while (tab->precision > len_elem)
	{
		tab->length += write(1, "0", 1);
		tab->precision --;
	}
}

void	ft_right_indent(t_print *tab, int len_elem)
{
	int width = tab->width;

	if (tab->precision == -1 || !tab->is_num)
		tab->precision = 0;
	while (width > tab->precision && width > len_elem)
	{
		if (!tab->is_zero)
			tab->length += write(1, " ", 1);
		else if (tab->is_zero)
			tab->length += write(1, "0", 1);
		width --;
	}

	if (tab->is_num)
		ft_format_precision(tab, len_elem);
}

void	ft_left_indent(t_print *tab, int len_elem)
{
	int width = tab->width;
	while (width - len_elem > 0)
	{
		tab->length += write(1, " ", 1);
		width --;
	}
}
