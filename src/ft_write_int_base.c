/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 12:38:16 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_win(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num <= -base)
	{
		if (ft_win(num / base, base, basechars, digits) == -1)
			return (-1);
	}
	pos = num % base;
	result = write(FD, &basechars[-pos], 1);
	if (result == -1)
		return (-1);
	else if (result == 1)
	{
		*digits = *digits + 1;
		result = *digits;
	}
	return (result);
}

static ssize_t	ft_wip(int num, int base, char *basechars, ssize_t *digits)
{
	size_t	pos;
	ssize_t	result;

	if (num >= base)
	{
		if (ft_wip(num / base, base, basechars, digits) == -1)
			return (-1);
	}
	pos = num % base;
	result = write(FD, &basechars[pos], 1);
	if (result == -1)
		return (-1);
	else if (result == 1)
	{
		*digits = *digits + 1;
		result = *digits;
	}
	return (result);
}

/* ************************************************************************** */
/*  ft_write_int_base() is a generic function that prints numeric value in    */
/*  different numeric bases using the right base digits.                      */
/*                                                                            */
/*  This funciton uses two recursive functions, one for positive numbers and  */
/*  one for negative numbers                                                  */
/*                                                                            */
/*  GETS                                                                      */
/*   int     num          Num to transform into chars if a base               */
/*   int     base         Base of num (10 decimal, 16,  octal                 */
/*   char    *basechars   set of char the base is made of                     */
/*   ssize_t *digits      passed by ref integer to return num of printed char */
/*                                                                            */
/*  RETURNS                                                                   */
/*    number of printed digits                                                */
/*                                                                            */
/*  OPERATES                                                                  */
/*    When num to print is positive call to recursive function for positives. */
/*                                                                            */
/*    When num to print is negative:                                          */
/*     1.- write negative sing. if problems retunr -1.                        */
/*     2.- Writting the sign increases printed digits in one unit.            */
/*     3.- call to recursive function for negatives.                          */
/*                                                                            */
/* ************************************************************************** */

ssize_t	ft_write_int_base(int num, int base, char *basechars, ssize_t *digits)
{
	ssize_t	result;

	if (0 <= num & num <= INT_MAX)
		result = ft_wip(num, base, basechars, digits);
	else if (INT_MIN <= num)
	{
		if (write(FD, "-", 1) != 1)
			return (-1);
		*digits = *digits + 1;
		result = ft_win(num, base, basechars, digits);
	}
	else
		return (-1);
	if (0 < result)
		result = *digits;
	return (result);
}
