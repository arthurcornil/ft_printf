/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/22 10:00:16 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)ft_malloc(sizeof(t_print));
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
			ret += write(1, (format + i), 1);
		i ++;
	}
	va_end(tab->args);
	ret += tab->length;
	ft_free(tab);
	return (ret);
}
