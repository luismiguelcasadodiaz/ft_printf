/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write_int_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:18:47 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/05 18:18:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ssize_t	digits;

	digits = 0;
	printf("<-->%ld<\n", ft_write_int_base(125789, 10, "0123456789", &digits));
	digits = 0;
	printf("<-->%ld<\n", ft_write_int_base(-125789, 10, "0123456789", &digits));
	digits = 0;
	printf("<-->%ld<\n", ft_write_num_hex(2047));
	digits = 0;
	printf("<-->%ld<\n", ft_write_num_HEX(-2047));
	return (0);
}
