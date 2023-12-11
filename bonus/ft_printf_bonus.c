/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:39:17 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/11 11:57:50 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include <stdarg.h>

static short	not_in_csdipx(const char c)
{
	short	r;

	r = 1;
	r = r & (c != '%');
	r = r & (c != 'c');
	r = r & (c != 's');
	r = r & (c != 'd');
	r = r & (c != 'i');
	r = r & (c != 'p');
	r = r & (c != 'x');
	r = r & (c != 'X');
	return (r);
}

void	init_modifiers_vars(size_t *idx_width, size_t **i, t_flags *r)
{
	*idx_width = 0;
	**i = **i + 1;
	r->hash = 0;
	r->zero = 0;
	r->minus = 0;
	r->plus = 0;
	r->space = 0;
	r->dot = 0;
	r->asterisk = 0;
	r->width = 0;
	while (*idx_width < (WIDTH_MAX - 1))
	{
		r->str_width[*idx_width] = ' ';
		*idx_width = *idx_width + 1;
	}
	r->str_width[*idx_width] = '\0';
	*idx_width = 0;
}

static short	modifiers(const char *fmt, size_t *i, t_flags *r_flags)
{
	size_t	idx_width;

	init_modifiers_vars(&idx_width, &i, r_flags);
	while (not_in_csdipx(fmt[*i]))
	{
		if (fmt[*i] == '#')
			r_flags->hash = 1;
		else if (fmt[*i] == '0')
			r_flags->zero = 1;
		else if (fmt[*i] == '-')
			r_flags->minus = 1;
		else if (fmt[*i] == '+')
			r_flags->plus = 1;
		else if (fmt[*i] == ' ')
			r_flags->space = 1;
		else if (fmt[*i] == '.')
			r_flags->dot = 1;
		else if (fmt[*i] == '*')
			r_flags->asterisk = 1;
		else if (('0' <= fmt[*i]) & (fmt[*i] <= '9'))
		{
			r_flags->str_width[idx_width] = fmt[*i];
			idx_width++;
		}
		else
			return (-1);
		*i = *i +1;
	}
	return (0);
}

/* ************************************************************************** */
/* analiza() calls the right function  with the right argument according to   */
/* the value of c.                                                            */
/*                                                                            */
/* GETS:                                                                      */
/* char c : the formater char that defines the funcion to print and the type  */
/*          to cast the argument to.                                          */
/*                                                                            */
/* OPERATES:                                                                  */
/* Only chars csdiupxX% select a function.                                    */
/* if %, a % has to be printed. 37 is the ascii value of %.                   */
/*                                                                            */
/*                                                                            */
/* RETURNS:                                                                   */
/* 0 when char is not in csdiupxX%.                                           */
/* The returned value from called function.                                   */
/*                                                                            */
/* ************************************************************************** */
ssize_t	analiza(const char *fmt, size_t *i, va_list args)
{
	char	c;
	t_flags	r_flags;

	if (modifiers(fmt, i, &r_flags) == -1)
		return (-1);
	c = fmt[*i + 1];
	if (c == '%')
		return (ft_write_c(37));
	if (c == 'c')
		return (ft_write_c(va_arg(args, int)));
	if (c == 's')
		return (ft_write_str(va_arg(args, char *)));
	if (c == 'd')
		return (ft_write_dec(va_arg(args, int)));
	if (c == 'i')
		return (ft_write_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_write_uns(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_write_hex_low(va_arg(args, int)));
	if (c == 'X')
		return (ft_write_hex_cap(va_arg(args, unsigned int)));
	return (0);
}

/* ************************************************************************** */
/* ft_printf() is a variadic functions that emulates printf() from stdio.h    */
/*                                                                            */
/* GETS                                                                       */
/*  *fmt is a pointe to a string with formaters that start by %               */
/*  ...  an undefined number of arguments                                     */
/*                                                                            */
/* RETURNS:                                                                   */
/*  The number of printed chars when sucess, -1 when fails                    */
/*                                                                            */
/* OPERATES:                                                                  */
/*  Initializes the treatement of the arguments starting after fmt.           */
/*                                                                            */
/*  Loops fmt printing, char by char, whatever different from %.              */
/*  When % shows up analizes next char                                        */
/*                                                                            */
/*  Ends the treatment of the arguments starting after fmt                    */
/* ************************************************************************** */
int	ft_printf(const char *fmt, ...)
{
	int		tot_chars;
	ssize_t	result;
	size_t	i;
	va_list	args;

	i = 0;
	tot_chars = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		result = 0;
		if (fmt[i] != '%')
			result = ft_write_c(fmt[i]);
		else
		{
			result = analiza(fmt, &i, args);
			i++;
		}
		i++;
		if (result < 0)
			return (-1);
		tot_chars = tot_chars + result;
	}
	va_end(args);
	return (tot_chars);
}
