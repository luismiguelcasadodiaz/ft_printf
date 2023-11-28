/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:15:03 by luicasad          #+#    #+#             */
/*   Updated: 2023/11/26 10:32:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *formater, int param)
{
	return (printf(formater, param));
}

int	main(int argc, char **argv)
{
	char	*formater;
	float	num;
	int	libnumchars;
	int	my_numchars;

	if (argc != 3)
	{
		printf("Usage: float_print <formater> <value>\n");
		return (0);
	}
	num = atof(argv[2]);
	formater = argv[1];
	printf("lib print ==>");
	libnumchars = printf(formater, num);
	printf("<\n");
	printf("my  print ==>");
	my_numchars = ft_printf(formater, num);
	printf((libnumchars != my_numchars)? "<\n\033[1;91mKO": "<\n\033[1;92mOK");
	printf("\033[0m\n");
	return (0);
}
