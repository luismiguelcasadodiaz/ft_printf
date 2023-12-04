/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:40:17 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/03 21:01:29 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>

# define FD 0

ssize_t	ft_write_c(char c);
ssize_t	ft_write_str(char *str);
ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits);
ssize_t	ft_write_num_hex(int num);
ssize_t	ft_write_num_HEX(int num);

#endif
