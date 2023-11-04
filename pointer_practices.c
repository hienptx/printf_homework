#include <stdio.h>

void	ft_iterstr(char *str, int *ptr_a, int *b)//or: (*)int ft_iterstr(...)
{	
	int	iter;		
	
	iter = 0;
	while (*str)
	{	
		if (*str == 'a')
		{
			iter++;
			(*b)++;
		}
		str++;
		(*b)++;	
	}
	*ptr_a = iter;		//return(ptr_a); when int *ft_iterstr		
				//return(iter); when int ft_iterstr
}

int	main(void)
{
	int	a = 10;
	int	*ptr_a;
	char	*s;
	int	b;

	b = 0;
	s = "i aaaam here";
	ptr_a = &a;
	ft_iterstr(s, ptr_a, &b);
	
	printf("b = %d\n", b);
	printf("a = %d\n", a);
	printf("&a =%p\n", &a);
	printf("&ptr_a = %p\n", &ptr_a);
	printf("ptr_a = %p\n", ptr_a);
	printf("*ptr_a = %i\n", *ptr_a);
	printf("&(*ptr_a) = %p\n", &(*ptr_a));
}
