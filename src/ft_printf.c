/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:39:17 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 10:05:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>

ssize_t	analiza(char c, va_list args)
{
	if (c == '%')
		return (ft_write_c(37));
	if (c == 'c')
		return (ft_write_c(va_arg(args, int)));
	if (c == 's')
		return (ft_write_str(va_arg(args, char *)));
	if (c == 'd')
		return (ft_write_dec(va_arg(args, int)));
	if (c == 'i')
		return (ft_write_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_write_uns(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_write_hex_low(va_arg(args, int)));
	if (c == 'X')
		return (ft_write_hex_cap(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		tot_chars;
	ssize_t	result;
	size_t	i;
	va_list	args;

	i = 0;
	tot_chars = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		result = 0;
		if (fmt[i] != '%')
			result = ft_write_c(fmt[i]);
		else
		{
			result = analiza(fmt[i + 1], args);
			i++;
		}
		i++;
		if (result < 0)
			return (-1);
		tot_chars = tot_chars + result;
	}
	va_end(args);
	return (tot_chars);
}
