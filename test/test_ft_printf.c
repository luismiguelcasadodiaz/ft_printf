/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:30:16 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/09 09:25:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			*test_str = "Luis Miguel";
	int				yo;
	int				el;
	char			c;
	char			d;
	unsigned int	u;
	int				num;
	int				*pint;
	char			*s = "@@@";
	char			*s2 = NULL;

	printf("============== testing %%       ====================\n");
	printf("\n1.-<");
	el = printf(" %% ");
	printf(">\n1.-<");
	yo = ft_printf(" %% ");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n2.-<");
	el = printf(" %%%% ");
	printf(">\n2.-<");
	yo = ft_printf(" %%%% ");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n3.-<");
	el = printf(" %% %% %% ");
	printf(">\n3.-<");
	yo = ft_printf(" %% %% %% ");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n4.-<");
	el = printf(" %%  %%  %% ");
	printf(">\n4.-<");
	yo = ft_printf(" %%  %%  %% ");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n5.-<");
	el = printf(" %%   %%   %% ");
	printf(">\n5.-<");
	yo = ft_printf(" %%   %%   %% ");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n6.-<");
	el = printf("%%");
	printf(">\n6.-<");
	yo = ft_printf("%%");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("\n7.-<");
	el = printf("%% %%");
	printf(">\n7.-<");
	yo = ft_printf("%% %%");
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("============== testing ONLY c ====================\n");
	printf("1.-<");
	el = printf("%c", '0');
	printf("><");
	yo = ft_printf("%c", '0');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("2.-<");
	el = printf(" %c ", '0');
	printf("><");
	yo = ft_printf(" %c ", '0');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("3.-<");
	el = printf(" %c", '0' - 256);
	printf("><");
	yo = ft_printf(" %c", '0' - 256);
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("4.-<");
	el = printf("%c ", '0' + 256);
	printf("><");
	yo = ft_printf("%c ", '0' + 256);
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("5.-<");
	el = printf(" %c %c %c ", '0', 0, '1');
	printf("><");
	yo = ft_printf(" %c %c %c ", '0', 0, '1');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("6.-<");
	el = printf(" %c %c %c ", ' ', ' ', ' ');
	printf("><");
	yo = ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("7.-<");
	el = printf(" %c %c %c ", '1', '2', '3');
	printf("><");
	yo = ft_printf(" %c %c %c ", '1', '2', '3');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("8.-<");
	el = printf(" %c %c %c ", '2', '1', 0);
	printf("><");
	yo = ft_printf(" %c %c %c ", '2', '1', 0);
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("9.-<");
	el = printf(" %c %c %c ", 0, '1', '2');
	printf("><");
	yo = ft_printf(" %c %c %c ", 0, '1', '2');
	printf(">EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");
	printf("============== testing s and c ====================\n");
	el = printf("EL %%> Mi nombre es %s y mi letra es %c.\n", test_str, 'L');
	yo = ft_printf("YO %%> Mi nombre es %s y mi letra es %c.\n", test_str, 'L');
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf("EL %%> Mi nombre es %s y mi letra es %c.\n", "Alfonso", 'A');
	yo = ft_printf("YO %%> Mi nombre es %s y mi letra es %c.\n", "Alfonso", 'A');
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("-------------- frontier cases ---------------------\n");
	el = printf("EL %%> @@@ es %s y mi letra es %c.\n", s, 'A');
	yo = ft_printf("YO %%> @@@ es %s y mi letra es %c.\n", s, 'A');
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf("EL %%> NULL es %s y mi letra es %c.\n", s2, 'A');
	yo = ft_printf("YO %%> NULL es %s y mi letra es %c.\n", s2, 'A');
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf("EL %%> NULL es %s y letra null es %c.\n", s2, '\0');
	yo = ft_printf("YO %%> NULL es %s y letra null es %c.\n", s2, '\0');
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("============== testing i           ====================\n");
	num = -2147483647;
	el = printf("%i|%i|%i\n", num, 0, 0x7FFFFFFF);
	yo = ft_printf("%i|%i|%i\n", num, 0, 0x7FFFFFFF);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf("0 is %i\n", 0);
	yo = ft_printf("0 is %i\n", 0);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	num = -2;
	el =    printf("-2 is %i\n", num);
	yo = ft_printf("-2 is %i\n", num);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	num = -2147483647;
	el =    printf("negative %i\n", num);
	yo = ft_printf("negative %i\n", num);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	num = 2147483647;
	el =    printf("positive %i\n", num);
	yo = ft_printf("positive %i\n", num);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	num = 2;
	el =    printf("two is  %i\n", num);
	yo = ft_printf("two is  %i\n", num);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	printf("============== testing u           ====================\n");
	el = printf("-10 is %u\n", -10);
	yo = ft_printf("-10 is %u\n", -10);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	u = 2;
	el =    printf("-2 is %u\n", u);
	yo = ft_printf("-2 is %u\n", u);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	u = -2147483647;
	el =    printf("negative %u\n", u);
	yo = ft_printf("negative %u\n", u);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	u = 2147483647;
	el =    printf("positive %u\n", u);
	yo = ft_printf("positive %u\n", u);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	u = 2;
	el =    printf("two is  %u\n", u);
	yo = ft_printf("two is  %u\n", u);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");
	printf("-------------- frontier cases --------------------\n");
	printf("============== testing p      ====================\n");

	num = -10;
	pint = &num;
	el =    printf("two is  %p\n", pint);
	yo = ft_printf("two is  %p\n", pint);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");



	el = printf(" %p \n", -1);
	yo = ft_printf(" %p \n", -1);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el =printf(" %p \n", 15);
	yo = ft_printf(" %p \n", 15);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	yo = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf(" %p %p \n", INT_MIN, INT_MAX);
	yo = ft_printf(" %p %p \n", INT_MIN, INT_MAX);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");

	el = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	yo = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");



	c = 'a';
	d = 'b';
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	// //uncomment for bonus
	// el = printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&c, d, u, s, num, 0, u, u);
	// yo = ft_printf("ftprint: a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&c, d, u, s, num, 0, u, u);
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%.3d\n", -1234);
	// yo = ft_printf("%.3d\n", -1234);
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%-9sScience!\n", "Aperture");
	// yo = ft_printf("%-9sScience!\n", "Aperture");
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%8p-%8s\n", NULL, s2);
	// yo = ft_printf("%8p-%8s\n", NULL, s2);
	// printf(" EL %d, YO %d\n", el , yo);

	el = printf("%p-%s\n", NULL, s2);
	yo = ft_printf("%p-%s\n", NULL, s2);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");
	el = printf("printf : a%pbc%%de%cfg%uhij%sk%dlm%inop%Xq%xr\n", (void *)&c, d, u, s, num, 0, u, u);
	yo = ft_printf("ftprint: a%pbc%%de%cfg%uhij%sk%dlm%inop%Xq%xr\n", (void *)&c, d, u, s, num, 0, u, u);
	printf("EL %d, YO %d ", el , yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK");
	printf("\033[0m\n");
	printf(" EL %d, YO %d\n", el , yo);
	return (0);
}
