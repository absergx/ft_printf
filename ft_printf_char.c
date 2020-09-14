/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:29:14 by memilio           #+#    #+#             */
/*   Updated: 2020/05/22 16:45:30 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_printf_total *total)
{
	int		i;
	char	c;

	i = 1;
	c = (char)va_arg(total->specs->params, int);
	if (total->flags->width > i)
	{
		while (i < total->flags->width && !total->flags->minus)
		{
			ft_putchar_pf(' ', 1, total);
			i++;
		}
		ft_putchar_pf(c, 1, total);
		while (i < total->flags->width && total->flags->minus)
		{
			ft_putchar_pf(' ', 1, total);
			i++;
		}
	}
	else
		ft_putchar_pf(c, 1, total);
}
