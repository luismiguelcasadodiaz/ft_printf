/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/06 16:00:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

ssize_t	ft_write_dec(int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_int_base(num, 10, "0123456789", &digits));
}
