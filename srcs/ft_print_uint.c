/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:41:10 by acornil           #+#    #+#             */
/*   Updated: 2022/03/02 23:46:43 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putuint(unsigned int num)
{
	int		factor;
	char	digit;

	factor = ft_get_factor(num);
	while (factor != 0)
	{
		digit = (num / factor) + '0';
		write(1, &digit, 1);
		num %= factor;
		factor /= 10;
	}
}

void	ft_print_uint(t_print *tab)
{
	unsigned int num;
	int	ndigits;

	num = va_arg(tab->args, unsigned int);
	ndigits = ft_get_ndigits(num);
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, ndigits);
	tab->length += ndigits;
	ft_putuint(num);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, ndigits);
	ft_reset_tab(tab);
}
