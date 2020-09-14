/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:29:19 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 03:25:14 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_parse_format_sub(t_printf_total *total, int f)
{
	int		tmp;

	if (total->flags->ch == '*')
		tmp = va_arg(total->specs->params, int);
	else
	{
		tmp = ft_atoi(&(total->specs->format[*(total->index)]));
		*(total->index) += ft_numlen(tmp) - 1;
	}
	if (!f)
	{
		if (tmp < 0)
		{
			total->flags->minus = 1;
			tmp = -tmp;
		}
		total->flags->width = tmp;
	}
	else if (f == 1)
	{
		if (tmp < 0)
			total->flags->precision = 0;
		total->flags->length = tmp;
	}
}

void		ft_printf_parse_format(t_printf_total *total)
{
	int		f;

	if (total->flags->precision)
		f = 1;
	else
		f = 0;
	if (total->flags->ch == '-' && !f)
		total->flags->minus = 1;
	else if (total->flags->ch == '0' && !f && !(total->flags->minus))
		total->flags->zero = 1;
	else if (total->flags->ch == '.')
	{
		total->flags->precision = 1;
		f = 1;
	}
	else if (total->flags->ch == '#')
		total->flags->hashtag = 1;
	else if (total->flags->ch == '+')
		total->flags->plus = 1;
	else if (total->flags->ch == ' ')
		total->flags->space = 1;
	else if (ft_strchr("0123456789*", total->flags->ch))
		ft_printf_parse_format_sub(total, f);
}
