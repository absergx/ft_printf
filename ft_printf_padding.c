/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:16:03 by memilio           #+#    #+#             */
/*   Updated: 2020/05/23 15:30:02 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_padding(char *src, size_t len_dst, char padder, int f)
{
	size_t		len_src;
	size_t		len_diff;
	size_t		i;
	char		*dst;

	if ((dst = (char *)malloc(sizeof(char) * len_dst + 1)))
	{
		len_src = ft_strlen(src);
		len_diff = len_dst - len_src;
		i = 0;
		while (i < len_dst)
		{
			if (f && i < len_src)
				dst[i] = src[i];
			else if ((f && i >= len_src) || (!f && i < len_diff))
				dst[i] = padder;
			else if (!f && i >= len_diff)
				dst[i] = src[i - len_diff];
			i++;
		}
		dst[i] = '\0';
	}
	free(src);
	return (dst);
}
