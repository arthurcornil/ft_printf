/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:39:48 by acornil           #+#    #+#             */
/*   Updated: 2025/04/22 10:06:09 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int	num;
	int	ndigits;
	int	len;

	num = va_arg(tab->args, int);
	ndigits = ft_get_ndigits(num);
	len = ndigits;
	tab->is_num = true;
	if (num == -2147483648)
	{
		ft_format_precision(tab, 10);
		write(1, "2147483648", 10);
	}
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}
