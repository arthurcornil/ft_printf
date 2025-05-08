/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:54 by acornil           #+#    #+#             */
/*   Updated: 2022/03/10 14:35:47 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	tab->length += len;
	write(1, str, len);
}
