/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 20:39:47 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:21:21 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_sint(t_printf_total *total)
{
	long long			num;
	unsigned long long	unum;

	if (total->flags->longer == 1)
		num = va_arg(total->specs->params, long);
	else if (total->flags->longer > 1)
		num = va_arg(total->specs->params, long long);
	else
		num = va_arg(total->specs->params, int);
	if (num == 0)
		total->flags->num_is_zero = 1;
	if (num < 0)
	{
		total->flags->num_is_negative = 1;
		unum = -num;
	}
	else
		unum = num;
	return (ft_itoa_u(unum));
}
