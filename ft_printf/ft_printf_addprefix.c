/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addprefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:16:37 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:58:38 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_addprefix_hex(t_printf_total *total, char *src,
	size_t len_src)
{
	char		*dst;

	if ((dst = (char *)malloc(sizeof(char) * (len_src + 2))))
	{
		dst[0] = '0';
		dst[1] = (total->flags->ch == 'X') ? 'X' : 'x';
	}
	ft_strlcpy(&(dst[2]), src, (len_src));
	return (dst);
}

char		*ft_printf_addprefix(t_printf_total *total, char *src)
{
	size_t		len_src;
	char		*dst;

	len_src = ft_strlen(src) + 1;
	if (ft_strchr("pxX", total->flags->ch))
		dst = ft_printf_addprefix_hex(total, src, len_src);
	else if ((dst = (char *)malloc(sizeof(char) * (len_src + 1))))
	{
		if (total->flags->num_is_negative)
			dst[0] = '-';
		else if (!total->flags->num_is_negative)
		{
			if (total->flags->plus)
				dst[0] = '+';
			else if (total->flags->space)
				dst[0] = ' ';
		}
		ft_strlcpy(&(dst[1]), src, (len_src));
	}
	free(src);
	return (dst);
}
