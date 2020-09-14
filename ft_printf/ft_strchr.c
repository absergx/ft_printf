/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:15:23 by memilio           #+#    #+#             */
/*   Updated: 2020/05/25 23:15:28 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string != '\0')
	{
		if (symbol == *string)
			return ((char *)string);
		++string;
	}
	if (symbol == *string)
		return ((char *)string);
	return (NULL);
}
