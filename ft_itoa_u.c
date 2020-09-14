/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:30:42 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:04:25 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_u(unsigned long long n)
{
	char	*res;
	size_t	len;

	len = ft_numlen(n);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len != 0)
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		--len;
	}
	return (res);
}
