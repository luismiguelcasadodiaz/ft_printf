# ft_printf
Program your own printf() and learn about variadic functions

Once this assignment passed, you will be allowed to add your ft_printf() to your libft so you can use it in your school C projects.

|            |             |
|------------|-------------|
|Program name|libftprintf.a|
|Turn in files|Makefile, *.h, */*.h, *.c, */*.c|
|Makefile|NAME, all, clean, fclean, re|
|External functs.|malloc, free, write,va_start, va_arg, va_copy, va_end|
|Libft authorized|Yes|
|Description|Write a library that contains ft_printf(), a function that will mimic the original printf()|



The prototype of ft_printf() is:
int ft_printf(const char *, ...);


### Here are the requirements:
- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
-sing the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.

#### You have to implement the following conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format. • %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

#### Bonus

- Manage any combination of the following flags: ’-0.’ 
- Manage the field minimum width under all conversions.
- Manage all the following flags: ’# +’ (Yes, one of them is a space)


<img width="536" alt="image" src="https://github.com/luismiguelcasadodiaz/ft_printf/assets/19540140/b369eb78-d208-44f9-9a15-5b9809b994a4">


## Variadic Functions
