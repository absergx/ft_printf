/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:46:10 by memilio           #+#    #+#             */
/*   Updated: 2020/05/22 04:23:41 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_printf_specs	specs;
	size_t			i;
	unsigned char	letter;

	specs.format = format;
	specs.written = 0;
	va_start(specs.params, format);
	i = 0;
	specs.end = 0;
	while ((letter = specs.format[i]) && !specs.end)
	{
		i++;
		if (letter != '%')
		{
			ft_putchar_fd((char)letter, 1);
			specs.written += 1;
		}
		else if (letter == '\0')
			specs.end = 1;
		else
			ft_printf_parse(&specs, &i);
	}
	va_end(specs.params);
	return (specs.written);
}
