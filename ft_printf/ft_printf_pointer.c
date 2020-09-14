/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:48:38 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 03:52:32 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_pointer(t_printf_total *total)
{
	char			*str;
	unsigned long	tmp;

	tmp = (unsigned long)va_arg(total->specs->params, void *);
	if (tmp == 0)
		total->flags->num_is_zero = 1;
	str = ft_itoa_hex(tmp);
	return (str);
}
