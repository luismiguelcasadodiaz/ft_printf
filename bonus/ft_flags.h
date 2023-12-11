/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:01:35 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/11 12:17:09 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FLAGS_H
# define FT-FLAGS_H

# define WIDTH_MAX 11

typedef struct s_flags
{
	short	hash;
	short	zero;
	short	minus;
	short	plus;
	short	space;
	short	dot;
	short	asterisk;
	short	width;
	char	str_width[WIDTH_MAX];
	size_t	idx_width;
}	t_flags;

ssize_t	flags_set(const char c, t_flags *r);
void	flags_init(t_flags *r);
#endif
