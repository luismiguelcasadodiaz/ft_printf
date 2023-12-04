/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/03 20:56:49 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

ssize_t	ft_write_num_hex(int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_int_base(num, 16, "0123456789abcdef", &digits));
}
