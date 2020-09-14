/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:29:51 by memilio           #+#    #+#             */
/*   Updated: 2020/05/25 21:48:28 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_specifiers(t_printf_total *total)
{
	char	*str;
	char	specifier;

	specifier = total->flags->ch;
	if (specifier == 's')
		str = ft_printf_string(total);
	else if (specifier == 'p')
		str = ft_printf_pointer(total);
	else if (specifier == 'd' || specifier == 'i')
		str = ft_printf_sint(total);
	else if (specifier == 'u')
		str = ft_printf_unint(total);
	else if (specifier == 'x')
		str = ft_printf_hexs(total);
	else if (specifier == 'X')
		str = ft_printf_hexb(total);
	else if (specifier == '%')
		str = ft_strdup("%");
	else
		str = ft_printf_n(total);
	return (str);
}
