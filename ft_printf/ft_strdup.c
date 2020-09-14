/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:04:07 by memilio           #+#    #+#             */
/*   Updated: 2020/05/12 19:37:54 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char const *src)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(src) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
