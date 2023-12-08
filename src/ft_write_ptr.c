/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/06 16:02:49 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

ssize_t	ft_write_ptr(void *num)
{
	ssize_t				digits;
	unsigned long long	my_num;

	my_num = (unsigned long long)num;
	if (ft_write_str("0x") != 2)
		return (-1);
	digits = 2;
	return (ft_write_uns_base(my_num, 10, "0123456789", &digits));
}
