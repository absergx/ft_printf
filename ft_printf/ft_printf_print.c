/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:54:16 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 03:53:34 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_print_width(t_printf_total *total, char *str)
{
	size_t		len_src;
	size_t		len_dst;

	len_src = ft_strlen(str);
	len_dst = (size_t)(total->flags->width);
	if (len_dst > len_src)
	{
		if (total->flags->minus)
			str = ft_printf_padding(str, len_dst, ' ', 1);
		else if (total->flags->zero && !total->flags->precision &&
			ft_strchr("diuxX%", total->flags->ch))
		{
			if (total->flags->num_is_negative || total->flags->plus
			|| total->flags->space)
				len_dst -= 1;
			else if (total->flags->hashtag && !total->flags->num_is_zero)
				len_dst -= 2;
			str = ft_printf_padding(str, len_dst, '0', 0);
		}
		else
			str = ft_printf_padding(str, len_dst, ' ', 0);
	}
	return (str);
}

static char	*ft_printf_print_precision(t_printf_total *total, char *str)
{
	size_t		len_src;

	len_src = ft_strlen(str);
	if (ft_strchr("pdiuxX", total->flags->ch))
	{
		if (total->flags->length == 0 && total->flags->num_is_zero)
			return (ft_strlcut(str, 0));
		else if ((size_t)total->flags->length > len_src)
			return (ft_printf_padding(str, (size_t)total->flags->length, '0',
				0));
	}
	else if (total->flags->ch == 's' && (size_t)total->flags->length < len_src)
		return (ft_strlcut(str, (size_t)total->flags->length));
	return (str);
}

static int	check_prefix(t_printf_total *total, int f)
{
	int booli;

	if (total->flags->zero && total->flags->minus)
		total->flags->zero = 0;
	if (!f)
		booli = (!(total->flags->zero) || total->flags->precision ||
		total->flags->minus);
	else
		booli = (total->flags->zero && !total->flags->precision);
	return (((ft_strchr("di", total->flags->ch) &&
		(total->flags->num_is_negative || total->flags->plus ||
		total->flags->space)) || total->flags->ch == 'p'
		|| (ft_strchr("xX", total->flags->ch) && total->flags->hashtag &&
		!total->flags->num_is_zero)) && booli);
}

void		ft_printf_print_param(t_printf_total *total)
{
	char		*str;
	size_t		i;

	str = ft_printf_specifiers(total);
	if (total->flags->precision && str)
		str = ft_printf_print_precision(total, str);
	if (check_prefix(total, 0) && str)
		str = ft_printf_addprefix(total, str);
	if (total->flags->width && str)
		str = ft_printf_print_width(total, str);
	if (check_prefix(total, 1) && str)
		str = ft_printf_addprefix(total, str);
	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			ft_putchar_pf(str[i], 1, total);
			i++;
		}
		free(str);
	}
}
