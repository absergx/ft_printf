/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:23:40 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:22:56 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_unint(t_printf_total *total)
{
	unsigned long long	num;

	if (total->flags->longer == 1)
		num = va_arg(total->specs->params, unsigned long);
	else if (total->flags->longer > 1)
		num = va_arg(total->specs->params, unsigned long long);
	else
		num = va_arg(total->specs->params, unsigned int);
	if (num == 0)
		total->flags->num_is_zero = 1;
	return (ft_itoa_u(num));
}
