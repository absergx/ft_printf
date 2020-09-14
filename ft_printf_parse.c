/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:50:11 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:27:20 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_flags_new(t_printf_flags *flags)
{
	flags->ch = 0;
	flags->number_sign = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->length = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->num_is_zero = 0;
	flags->num_is_negative = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->longer = 0;
}

void		ft_printf_parse(t_printf_specs *specs, size_t *i)
{
	t_printf_flags			flags;
	t_printf_total			total;

	total.index = i;
	total.specs = specs;
	total.flags = &flags;
	ft_printf_flags_new(&flags);
	while ((flags.ch = specs->format[*i]))
	{
		if (ft_strchr("0123456789.*-+# ", flags.ch))
			ft_printf_parse_format(&total);
		else if (flags.ch == 'l')
			total.flags->longer += 1;
		else if (ft_strchr("ncspdiuxX%", flags.ch))
		{
			if (flags.ch == 'c')
				ft_printf_char(&total);
			else
				ft_printf_print_param(&total);
			*i += 1;
			break ;
		}
		*i += 1;
	}
}
