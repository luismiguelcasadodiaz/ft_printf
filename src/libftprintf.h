/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:40:17 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/06 19:50:29 by luicasad         ###   ########.fr       */
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
ssize_t	ft_write_dec(int num);
ssize_t	ft_write_int(int num);
ssize_t	ft_write_uns(unsigned int num);
ssize_t	ft_write_hex_low(int num);
ssize_t	ft_write_hex_cap(int num);
int		ft_printf(const char *fmt, ...)__attribute__((format (printf, 1, 2)));
#endif
