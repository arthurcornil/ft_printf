/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:39 by acornil           #+#    #+#             */
/*   Updated: 2022/02/25 08:57:13 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_get_ndigits(int num)
{
	int i;
	
	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
		i ++;
	while (num != 0)
	{
		num /= 10;
		i ++;	
	}
	return (i);
}

int	ft_get_factor(unsigned int num)
{
	int factor;

	factor = 1;
	while (num >= 10)
	{
		num /= 10;
		factor *= 10;
	}
	return (factor);
}


void	ft_reset_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = -1;
	tab->is_num = 0;
	tab->dash = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->percentage = 0;
	tab->space = 0;
}
