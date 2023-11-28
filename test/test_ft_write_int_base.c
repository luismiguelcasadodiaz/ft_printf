/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write_int_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:luicasad<luicasad@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:39:21 by luicasad          #+#    #+#             */
/*   Updated: 2023/11/26 11:47:15 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../src/libprintf.h"
#include <stdio.h>

int main(void)
{
	ssize_t	digits;

	digits = 0;
	printf("\n>%ld<\n",ft_write_int_base(125789, 10, "0123456789", &digits));
	digits = 0;
	printf("\n>%ld<\n",ft_write_int_base(2047, 16, "0123456789abcdef", &digits));
	digits = 0;
	printf("\n>%ld<\n",ft_write_int_base(2047, 16, "0123456789ABCDEF", &digits));
	return (0);
}
