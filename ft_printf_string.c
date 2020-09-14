/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:43:14 by memilio           #+#    #+#             */
/*   Updated: 2020/05/12 19:38:45 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_string(t_printf_total *total)
{
	char *str;

	str = va_arg(total->specs->params, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_strdup(str));
}
