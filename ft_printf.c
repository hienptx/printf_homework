//else if (*format == 's')
//else if (*format == 'd'
//else if (*format == 'i')
//else if (*format == 'u')
//else if (*format == 'p')
//else if (*format == 'x')
//else if (*format == 'X')

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(const char c, int *p_charcount)
{
	if ((write(1, &c, 1)) == -1)
        	return (-1);
	else
		return ((*p_charcount)++);
}

void	casecheck(const char *format, va_list args, int *p_charcount)
{	
	int     process_input(const char *format, va_list args, int *p_charcount);
	if (*format == 'c')
		ft_putchar(va_arg(args, int), p_charcount);
        else if (*format == '%')
		write(1, "%", 1);
        else
	{
		ft_putchar(*(--format), p_charcount);
        	process_input((++format), args, p_charcount);
	}
}	
	
int	process_input(const char *format, va_list args, int *p_charcount)
{
	while (*format)
	{
		if (*format == '%') // or (*format == % && format++)
		{
			(*p_charcount)++;
			format++;
			casecheck(format, args, p_charcount);	
		}
		else
			ft_putchar(*format, p_charcount);
		format++;
	}
	return(*p_charcount);
}	

int	ft_printf(const char *format, ...)
{
	int	char_count;
	va_list args;
	va_list cpy_args;
	
	char_count = 0;
	va_start (args, format);
	va_copy (cpy_args, args);
	process_input (format, cpy_args, &char_count);

	va_end (cpy_args);
	va_end (args);
	return (char_count);
}

int main()
{
	ft_printf ("int return value = %d\n", ft_printf(" %%\n"));
	ft_printf ("int return value = %d\n", ft_printf(" %%%%%%\n"));
	ft_printf ("int return value = %d\n", ft_printf(" %%c%c\n", 'A'));
	ft_printf ("int return value = %d\n", ft_printf("n\n23\r\\nk\n"));

	printf("write return value = %li\n", write(1, "(null)", 6));
	printf ("int return value = %d\n", printf(" %%\n"));
	printf ("int return value = %d\n", printf(" %%%%%%\n"));		
	printf ("int return value = %d\n", printf(" %%c%c\n", 'A'));
	printf ("int return value = %d\n", printf("n\n23\r\\nk\n"));
}
