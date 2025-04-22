/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:02:44 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/22 10:02:45 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->length += write(1, &a, 1);
	ft_reset_tab(tab);
}
