/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 01:16:39 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:26:31 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_hexb(t_printf_total *total)
{
	char	*str;
	size_t	i;

	str = ft_printf_hexs(total);
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*ft_printf_hexs(t_printf_total *total)
{
	unsigned long long	num;

	if (total->flags->longer > 1 || total->flags->ch == 'p')
		num = va_arg(total->specs->params, unsigned long long);
	else if (total->flags->longer == 1)
		num = va_arg(total->specs->params, unsigned long);
	else
		num = va_arg(total->specs->params, unsigned int);
	if (num == 0)
		total->flags->num_is_zero = 1;
	return (ft_itoa_hex(num));
}
