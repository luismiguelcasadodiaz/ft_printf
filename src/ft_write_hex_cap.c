/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/05 16:36:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

ssize_t	ft_write_hex_cap(unsigned int num)
{
	ssize_t			digits;
	unsigned long	my_num;

	my_num = (unsigned long)num;
	digits = 0;
	return (ft_write_uns_base(my_num, 16, "0123456789ABCDEF", &digits));
}
