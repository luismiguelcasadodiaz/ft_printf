/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <luicasad@student.42barcelona.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:50 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/06 14:58:37 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

ssize_t	ft_write_str(char *str)
{
	ssize_t	result;
	ssize_t	strlen;

	strlen = 0;
	if (!str)
		return (ft_write_str("(null)"));
	while (str[strlen] != '\0')
	{
		result = write(FD, &str[strlen], 1);
		if (result == -1)
			return (result);
		strlen++;
	}
	return (strlen);
}
