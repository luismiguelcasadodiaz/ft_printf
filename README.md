# ft_printf
Program your own printf() and learn about variadic functions

Once this assignment passed, you will be allowed to add your ft_printf() to your libft so you can use it in your school C projects.

|            |             |
|------------|-------------|
|Program name|libftprintf.a|
|Turn in files|Makefile, all .h and .c required.c|
|Makefile|NAME, all, clean, fclean, re|
|External functs.|malloc, free, write,va_start, va_arg, va_copy, va_end|
|Libft authorized|Yes|
|Description|Write a library that contains ft_printf(), a function that will mimic the original printf()|



The prototype of ft_printf() is:
int ft_printf(const char * , ...);


### Here are the requirements:
- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.  Using the libtool command is forbidden.
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


Variadic functions are functions (e.g. printf) which take a variable number of arguments.

The declaration of a variadic function uses an ellipsis as the last parameter: 
e.g. int printf(const char * format, ...);

Accessing the variadic arguments from the function body uses the following library facilities that are Defined in header <stdarg.h>

The include file <stdarg.h> declares a type (`va_list`) and defines macros [`va_start()`, `va_arg()`, `va_copy()`, and `va_end()`]  for stepping through a list of arguments whose number and types are NOT KNOWN TO THE CALLED FUNCTION.

The called function must declare an object of type `va_list`

va_list arg_ptr;
The va_start(arg_ptr, last) macro must be called first, and it initializes argv. Initializes the arg_ptr pointer for subsequent calls to the other functions. Argument `last` refers to the name of the last parameter before the variable argument list, i.e., the last parameter of which the calling function knows the type. `last` it should not be declared as a register variable, or as a function or an array type.

The va_arg() function retrieves a value of the given var_type from the location given by arg_ptr, and increases arg_ptr to point to the next argument in the list. The va_arg() function can retrieve arguments from the list any number of times within the function. The var_type argument must be one of int, long, decimal, double, struct, union, or pointer, or a typedef of one of these types.

Because it is not always possible for the called function to determine how many arguments there are, the calling function should communicate the number of arguments to the called function. To determine the number of arguments, a function can use a null pointer to signal the end of the list or pass the count of the optional arguments as one of the required arguments.
``` c
#include <stdio.h>
#include <stdarg.h>

void tlog(const char* fmt,...)
{
	int num;
	size_t	counter;
    va_list args;

    va_start(args, fmt);
	num = va_arg(args, int);
	counter = 0;
	while (num)
	{
		counter++;
		printf("%zu.- %d\n", counter, num);
		num = va_arg(args, int);
	}
    va_end(args);
}

int main(void)
{
	void	*null_ptr;

	null_ptr = NULL;
   tlog("logging %d %d %s...\n", 1, 7, 56, 11, 9, null_ptr);
}

```
The printf() function, for instance, can tell how many arguments there are through the format-string argument.

[IBM] (https://www.ibm.com/docs/en/i/7.2?topic=functions-printf-print-formatted-characters)


### End of subject Brainfuck challenge

++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>.>---.++++++++++++.++.+++ +++.--.<<++.>>------.------------.+++++++++++++.<<.>>++++++.------------ .-------. +++++++++++++++++++.<<.>>----------------.+++++.+++++++++.--- ----------.--.+ ++++++++++++++++.--------.+++++++++++++.<<.>>---------- -------------.+++.+++ ++++.---.----.+++++++++++++++++.--------------- --.-.<<.>>+++++.+++++.<<.>-------...

Famous man that directly believed in ???

[help in ](https://www.dcode.fr/brainfuck-language)

