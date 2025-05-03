/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:38:45 by acornil           #+#    #+#             */
/*   Updated: 2022/03/17 13:23:25 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_print_num(unsigned int num, char *base)
{
	int	lengthbase;

	lengthbase = 16;
	if (num >= (unsigned int)lengthbase)
	{
		ft_print_num(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

static int	ft_get_ndigits_hex(unsigned int num)
{
	int	ndigits;

	ndigits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_lowhex(t_print *tab)
{
	unsigned int	num;
	int				ndigits;
	int				len;

	num = va_arg(tab->args, unsigned int);
	ndigits = ft_get_ndigits_hex(num);
	len = ndigits;
	tab->is_num = true;
	if (num != 0)
		ft_print_num(num, "0123456789abcdef");
	ft_reset_tab(tab);
}

void	ft_print_uphex(t_print *tab)
{
	unsigned int	num;
	int				ndigits;
	int				len;

	num = va_arg(tab->args, unsigned int);
	ndigits = ft_get_ndigits_hex(num);
	len = ndigits;
	tab->is_num = true;
	if (num != 0)
		ft_print_num(num, "0123456789ABCDEF");
	ft_reset_tab(tab);
}
