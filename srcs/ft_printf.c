/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:43:18 by acornil           #+#    #+#             */
/*   Updated: 2022/03/03 17:12:55 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = -1;
	tab->is_num = 0;
	tab->dash = 0;
	tab->length = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->percentage = 0;
	tab->space = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int 	i;
	int		ret;

	tab = (t_print *) malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_get_format(tab, format, i + 1);
		else
			ret = write(1, (format + i), 1);
		i ++;
	}
	va_end(tab->args);
	free(tab);
	return(ret);
}
