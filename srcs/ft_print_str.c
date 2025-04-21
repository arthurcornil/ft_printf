/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:54 by acornil           #+#    #+#             */
/*   Updated: 2022/03/03 18:14:37 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	if (tab->precision == 0)
		str = "";
	len = ft_strlen(str);
	if (tab->precision > 0 && tab->precision < len)
		len = tab->precision;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, len);
	tab->length += len;
	i = 0;
	while (i < len)
	{
		ft_putchar_fd(*str, 1);
		str ++;
		i ++;
	}
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}
