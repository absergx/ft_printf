/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:18:41 by memilio           #+#    #+#             */
/*   Updated: 2020/05/22 02:35:14 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hexlen(unsigned long num)
{
	size_t	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char			*ft_itoa_hex(unsigned long num)
{
	char	*str;
	char	*hex;
	size_t	len;

	len = ft_hexlen(num);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	hex = "0123456789abcdef";
	str[len] = '\0';
	while (len != 0)
	{
		str[len - 1] = hex[num % 16];
		num /= 16;
		len--;
	}
	return (str);
}
