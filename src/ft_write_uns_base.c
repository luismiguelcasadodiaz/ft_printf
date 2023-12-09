/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 09:23:00 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_uns_neg(unsigned long long n,
						unsigned long long b,
						char *c,
						ssize_t *d)
{
	size_t	pos;
	ssize_t	result;

	if (n <= -b)
	{
		ft_write_uns_neg(n / b, b, c, d);
	}
	pos = n % b;
	if (write(FD, &c[-pos], 1) != 1)
		return (-1);
	else
	{
		*d = *d + 1;
		result = *d;
	}
	return (result);
}

ssize_t	ft_write_uns_pos(unsigned long long n,
						unsigned long long b,
						char *c,
						ssize_t *d)
{
	size_t	pos;
	ssize_t	result;

	if (n >= b)
	{
		ft_write_uns_pos(n / b, b, c, d);
	}
	pos = n % b;
	if (write(FD, &c[pos], 1) != 1)
		return (-1);
	else
	{
		*d = *d + 1;
		result = *d;
	}
	return (result);
}

/* ************************************************************************** */
/*  ft_write_uns_base() is a generic function that prints UNSIGNED values in  */
/*  different numeric bases using the right base digits.                      */
/*                                                                            */
/*  This funciton uses two recursive functions, one for positive numbers and  */
/*  one for negative numbers                                                  */
/*                                                                            */
/*  GETS                                                                      */
/*   unsigned long long n       Num to transform into chars if a base         */
/*   unsigned long long n       Base of num (10 decimal, 16,  octal           */
/*   char               *c      set of char the base is made of               */
/*   ssize_t            *d      passed by ref int. Returns num printed chars  */
/*                                                                            */
/*  RETURNS                                                                   */
/*    number of printed digits                                                */
/*                                                                            */
/*  OPERATES                                                                  */
/*    When num to print is positive call to recursive function for positives. */
/*                                                                            */
/*    When num to print is negative:                                          */
/*     DO NOTHING AS UNSIGNED ARE NOT NEGATIVES                               */
/*                                                                            */
/* ************************************************************************** */

ssize_t	ft_write_uns_base(unsigned long long n,
						unsigned long long b,
						char *c,
						ssize_t *d)
{
	ssize_t	result;

	result = ft_write_uns_pos(n, b, c, d);
	if (0 < result)
		result = *d;
	return (result);
}
