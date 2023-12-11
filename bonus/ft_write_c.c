/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <luicasad@student.42barcelona.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:50 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 16:03:35 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
/* ft_write_c() writes a char in the file FD                                  */
/*                                                                            */
/* GETS                                                                       */
/* char c: the char to  print                                                 */
/*                                                                            */
/* RETURNS:                                                                   */
/* Teh result of writing one char on FD                                      */
/* ************************************************************************** */
ssize_t	ft_write_c(char c)
{
	return (write(FD, &c, 1));
}