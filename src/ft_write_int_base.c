/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:47:05 by luicasad          #+#    #+#             */
/*   Updated: 2023/11/26 13:56:05 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num >= base)
	{
		*digits = *digits + 1;
		return (ft_write_int_base(num / base, base, basechars, digits));
	}
	else
	{
		pos = num % base;
		result = ft_write_c(basechars[pos]);
		if (result == 1)
			result = *digits + 1;
		return (result);
	}
}
