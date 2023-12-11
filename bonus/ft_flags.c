/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:05:46 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/11 12:17:11 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	flags_init(t_flags *r)
{
	r->idx_width = 0;
	r->hash = 0;
	r->zero = 0;
	r->minus = 0;
	r->plus = 0;
	r->space = 0;
	r->dot = 0;
	r->asterisk = 0;
	r->width = 0;
	while (r->idx_width < (WIDTH_MAX - 1))
	{
		r->str_width[r->idx_width] = ' ';
		r->idx_width++;
	}
	r->str_width[r->idx_width] = '\0';
	r->idx_width = 0;
}

ssize_t	flags_set(const char c, t_flags *r)
{
		if (c == '#')
			r_flags->hash = 1;
		else if (c == '0')
			r_flags->zero = 1;
		else if (c == '-')
			r_flags->minus = 1;
		else if (c == '+')
			r_flags->plus = 1;
		else if (c == ' ')
			r_flags->space = 1;
		else if (c == '.')
			r_flags->dot = 1;
		else if (c == '*')
			r_flags->asterisk = 1;
		else if (('0' <= c) & (c <= '9'))
		{
			r_flags->str_width[r->idx_width] = c;
			r->idx_width++;
		}
		else
			return (-1);
		return (0);
}
