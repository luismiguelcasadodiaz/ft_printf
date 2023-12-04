/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/03 21:02:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_write_digit(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num < 0)
	{
		num = -1 * num;
		result = ft_write_c('-');
		if (result == -1)
			return (-1);
		if (result == 1)
			result = *digits + 1;
	}
	pos = num % base;
	result = ft_write_c(basechars[pos]);
	if (result == -1)
		return (-1);
	if (result == 1)
		result = *digits + 1;
	return (result);
}

ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if ((num <= -base) || (num >= base))
	{
		*digits = *digits + 1;
		result = ft_write_int_base(num / base, base, basechars, digits);
		pos = num % base;
		result = ft_write_c(basechars[pos]);
		if (result == 1)
			result = *digits + 1;
	}
	else
		result = ft_write_digit(num, base, basechars, digits);
	return (result);
}
