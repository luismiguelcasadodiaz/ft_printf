/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uns_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:41 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/03 21:00:47 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

ssize_t	ft_write_(int num)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_int_base(num, 10, "0123456789", &digits));
}
