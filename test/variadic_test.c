/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:14:34 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/05 18:23:06 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	tlog(const char *fmt, ...)
{
	int		num;
	size_t	counter;
	va_list	args;

	va_start(args, fmt);
	num = va_arg(args, int);
	counter = 0;
	while (num)
	{
		counter++;
		printf("%zu.- %d\n", counter, num);
		num = va_arg(args, int);
	}
	va_end(args);
}

int	main(void)
{
	void	*null_ptr;

	null_ptr = NULL;
	tlog("logging %d %d %s...\n", 1, 7, 56, 11, 9, null_ptr);
}
