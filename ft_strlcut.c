/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:06:31 by memilio           #+#    #+#             */
/*   Updated: 2020/05/23 15:31:36 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strlcut(char *src, size_t len)
{
	char	*dst;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (len_src < len)
		return (src);
	if ((dst = (char *)malloc(sizeof(char) * len + 1)))
	{
		i = 0;
		while (src[i] != '\0' && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	free(src);
	return (dst);
}
