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

```c
int ft_printf(const char * , ...);
```
`ft_printf()` returns the number of characters printed (not including the trailing `\0' used to end output to strings). Returns a negative value if an error occurs.

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


## Format Specifications

We see there are 5 tokens in the format specification flags,width, precision, modifier, type

<img width="536" alt="image" src="https://github.com/luismiguelcasadodiaz/ft_printf/assets/19540140/b369eb78-d208-44f9-9a15-5b9809b994a4">

|level    |arg_number|flags|width|precision| modifier| type|
|-----    |----------|-----|-----|---------|---------|-----|
|mandatory|          |     |     |         |         |csp  diuxX %|
|bonus    |          |# 0 - + ' '     |[[:digit:]] *    |         |         |     |
|Exist but<br> not requested <br> in this proyect|[[:digit:]]+$|     |     |.[[:digit:]] * -|hh h l ll L  j t z q v vh hv vl lv vll llv|o DOU eE fF gG aA C S n|


## Variadic Functions


Variadic functions are functions (e.g. printf) which take a variable number of arguments.

The declaration of a variadic function uses an ellipsis as the last parameter: 
e.g. int printf(const char * format, ...);

Accessing the variadic arguments from the function body uses the following library facilities that are Defined in header <stdarg.h>

The include file <stdarg.h> declares a type (`va_list`) and defines macros [`va_start()`, `va_arg()`, `va_copy()`, and `va_end()`]  for stepping through a list of arguments whose number and types are NOT KNOWN TO THE CALLED FUNCTION.

The called function must declare an object of type `va_list`:

```c
va_list arg_ptr;
```

The `va_start(arg_ptr, last)` macro must be called first, and it initializes `arg_ptr`. Initializes the `arg_ptr` pointer for subsequent calls to the other functions. Argument `last` refers to the name of the last parameter before the variable argument list, i.e., the last parameter of which the calling function knows the type. `last` it should not be declared as a register variable, or as a function or an array type.

The `va_arg(arg_ptr, var_type)` function retrieves a value of the given `var_type` from the location given by `arg_ptr`, and increases `arg_ptr` to point to the next argument in the list. The `va_arg()` function can retrieve arguments from the list any number of times within the function. The `var_type` argument must be one of int, long, decimal, double, struct, union, or pointer, or a typedef of one of these types.

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

In this exercise, as we have to implement the conversions of cspdiuxX formatters, the data types to pass to va_arg functions are:

|formatter | data type|
|----------|----------|
|c|int|
|s|char *|
|p|unsigned long long|
|d|int|
|i|int|
|u|unsigned int|
|x|unsigned int|
|X|unsigned int|

A comment about unsigned long long (64 bits) for pointers.

|type|bits|CONSTANT MAX| Value MAX|
|:------------------|:---:|-------:|---------|
|unsigned long long| 64 |ULLONG_MAX|18 446 744 073 709 551 615|
|unsigned long| 32 |ULONG_MAX|4 294 967 295|
|unsigned int| 16 |UINT_MAX|65 535|


Bytes of memory each pointer type can address.

|unsigned int|unsigned long|unsigned long long|unit|
|-------:|------------:|-------------------------:|:------:|
|65 535|4 294 967 295|18 446 744 073 709 551 615| bytes| 
|64|4 194 303|1 801 439 850 9481 983| KBytes|
|-|4 095|17 592 186 044 415| MBytes|
|-|4|17 179 869 183| GBytes|
|-|-|16 777 215| TBytes|
|-|-|16 383| PBytes|
|-|-|16| EBytes|

Considering that de Mac in 42 has 8 GB of memory i selected type long long for the pointers.

## My first approach: Lex

I considered lex like a helper to create a lex analizer for print formated.
After some tests the file generated by lex was not norminette compatible. main yylex() function automatically generated had 240 lines. 
I considered that using this automatic would be using a sledge-hammer to crack a nut.  so i rejected the idea.



The printf() function, for instance, can tell how many arguments there are through the format-string argument.

[IBM] (https://www.ibm.com/docs/en/i/7.2?topic=functions-printf-print-formatted-characters)

## My second approach
A while loops the formatting string, printing all chars differente from `%`. When `%` shows up in function of the next char, it calls to the right function with the right params.

t_printf

	va_start
	ft_write_c
		write
	analiza
		
	%	ft_write_c(37));
			write
	c	ft_write_c(va_arg(args, int)));
			write
	s	ft_write_str(va_arg(args, char *)));
			write
	d	ft_write_dec(va_arg(args, int)));
			ft_write_int_base(int
				ft_wip(int
					write
				ft_win(int
					write
	i	ft_write_int(va_arg(args, int)));
			ft_write_int_base(int
				ft_wip(int
					write
				ft_win(int
					write
	u	ft_write_uns(va_arg(args, unsigned int)));
			ft_write_uns_base(unsigned long long
				ft_wup(unsigned long long
					write
	p	ft_write_ptr(va_arg(args, void *)));
			ft_write_uns_base(unsigned long long
				ft_wup(unsigned long long
					write
	x	ft_write_hex_low(va_arg(args, unsigned int)));
			ft_write_uns_base(unsigned long long
				ft_wup(unsigned long long
					write
	X	ft_write_hex_cap(va_arg(args, unsigned int)));
			ft_write_uns_base(unsigned long long
				ft_wup(unsigned long long
					write
	va_end


To print numeric values i use one base function for integers (`d` and `i` formaters) and one base function for unsigned values (`u`, `p`, `x`, `X`). Both base functions has helper RECURSIVE functions to print values. My challenge here, i solved with the help of [Joan Aresté](https://www.linkedin.com/in/joan-arest%C3%A9-443b79217), was to become aware that i my recursive function were not propagating correctly a error happening in the middle of the recursive stack. 


### End of subject Brainfuck challenge

++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>.>---.++++++++++++.++.+++ +++.--.<<++.>>------.------------.+++++++++++++.<<.>>++++++.------------ .-------. +++++++++++++++++++.<<.>>----------------.+++++.+++++++++.--- ----------.--.+ ++++++++++++++++.--------.+++++++++++++.<<.>>---------- -------------.+++.+++ ++++.---.----.+++++++++++++++++.--------------- --.-.<<.>>+++++.+++++.<<.>-------...

Famous man that directly believed in ???

[help in ](https://www.dcode.fr/brainfuck-language)

