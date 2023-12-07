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
#include "libftprintf.h"

ssize_t	ft_write_uns(unsigned int num)
{
	ssize_t	digits;
	int		my_num;

	my_num = (int)num;
	digits = 0;
	return (ft_write_int_base(my_num, 10, "0123456789", &digits));
}
