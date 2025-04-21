/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:38:45 by acornil           #+#    #+#             */
/*   Updated: 2022/02/24 12:21:08 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_num(unsigned int num, int lengthbase, char *base)
{
	if (num > (unsigned int)lengthbase)
	{
		ft_print_num(num / lengthbase, lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

void	ft_putnbr_hex(int nbr, char *base)
{
	int				lengthbase;

	lengthbase = 16;

	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		ft_print_num((unsigned int)nbr, lengthbase, base);
	}
	else
		ft_print_num((unsigned int)nbr, lengthbase, base);
}

static int	ft_get_ndigits_hex(int num)
{
	int ndigits;

	ndigits = 0;
	if (num < 0)
		num = -num;
	while(num > 0)
	{
		num /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_lowhex(t_print *tab)
{
	int	num;
	int ndigits_hex;

	num = va_arg(tab->args, int);
	ndigits_hex = ft_get_ndigits_hex(num);
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, ndigits_hex);
	tab->length += ndigits_hex;
	ft_putnbr_hex(num, "0123456789abcdef");
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, ndigits_hex);
	ft_reset_tab(tab);
}

void	ft_print_uphex(t_print *tab)
{
	int	num;
	int ndigits_hex;

	num = va_arg(tab->args, int);
	ndigits_hex = ft_get_ndigits_hex(num);
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, ndigits_hex);
	tab->length += ndigits_hex;
	ft_putnbr_hex(num, "0123456789ABCDEF");
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, ndigits_hex);
	ft_reset_tab(tab);
}

