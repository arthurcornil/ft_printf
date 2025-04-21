/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:59:48 by acornil           #+#    #+#             */
/*   Updated: 2022/03/03 14:28:38 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_ptr_to_hex(size_t num, char *base)
{
	size_t lengthbase;

	lengthbase = 16;
	if (num > lengthbase)
	{
		ft_ptr_to_hex(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

unsigned int	ft_get_ndigits_ptr_to_hex(size_t ptr)
{
	int ndigits;

	ndigits = 0;
	if (ptr == 0)
		return (1);
	while (ndigits > 0)
	{
		ptr /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_ptr(t_print *tab)
{
	size_t	ptr;
	int	ndigits_hex;

	ptr = va_arg(tab->args, size_t);
	ndigits_hex = ft_get_ndigits_ptr_to_hex(ptr);
	ndigits_hex += 2;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, ndigits_hex);
	tab->length += ndigits_hex;
	write(1, "0x", 2);
	ft_ptr_to_hex(ptr, "0123456789abcdef");
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, ndigits_hex);
	ft_reset_tab(tab);
}
