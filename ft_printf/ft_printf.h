/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:46:22 by memilio           #+#    #+#             */
/*   Updated: 2020/05/26 02:18:22 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct			s_printf_flags
{
	char				ch;
	int					number_sign;
	int					zero;
	int					minus;
	int					length;
	int					width;
	int					precision;
	int					num_is_zero;
	int					num_is_negative;
	int					hashtag;
	int					plus;
	int					space;
	int					longer;
}						t_printf_flags;

typedef struct			s_printf_specs
{
	const char			*format;
	va_list				params;
	int					written;
	int					end;
}						t_printf_specs;

typedef struct			s_printf_total
{
	t_printf_flags		*flags;
	t_printf_specs		*specs;
	size_t				*index;
}						t_printf_total;

size_t					ft_strlcpy(char *dst, const char *src, size_t size);
void					ft_printf_parse(t_printf_specs	*specs, size_t *i);
char					*ft_strchr(const char *string, int symbol);
int						ft_printf(char *format, ...);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar_pf(char c, int fd, t_printf_total *total);
char					*ft_itoa_u(unsigned long long n);
char					*ft_itoa_hex(unsigned long adr);
void					ft_printf_char(t_printf_total *total);
char					*ft_printf_string(t_printf_total *total);
char					*ft_printf_pointer(t_printf_total *total);
char					*ft_printf_sint(t_printf_total *total);
char					*ft_printf_unint(t_printf_total *total);
char					*ft_printf_hexs(t_printf_total *total);
char					*ft_printf_hexb(t_printf_total *total);
int						ft_toupper(int ch);
size_t					ft_numlen(unsigned long long n);
char					*ft_printf_addprefix(t_printf_total *total, char *src);
char					*ft_strlcut(char *src, size_t len);
char					*ft_strdup(char const *src);
size_t					ft_strlen(const char *str);
char					*ft_printf_specifiers(t_printf_total *total);
char					*ft_strchr(const char *string, int symbol);
void					ft_printf_parse_format(t_printf_total *total);
void					*ft_printf_n(t_printf_total *total);
int						ft_atoi(const char *str);
void					ft_printf_print_param(t_printf_total *total);
char					*ft_printf_padding(char *src, size_t len_dst,
						char padder, int f);

#endif
