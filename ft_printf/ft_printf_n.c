/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:42:27 by memilio           #+#    #+#             */
/*   Updated: 2020/05/25 21:49:08 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_printf_n(t_printf_total *total)
{
	unsigned long	*p;

	if (total->flags->ch == 'n')
	{
		p = va_arg(total->specs->params, void *);
		*p = total->specs->written;
	}
	return (NULL);
}
