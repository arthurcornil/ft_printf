/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:45:16 by acornil           #+#    #+#             */
/*   Updated: 2022/02/17 13:43:37 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, 1);
	tab->length += write(1, &a, 1);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, 1);
	ft_reset_tab(tab);
}
