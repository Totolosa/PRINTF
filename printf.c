/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:42:32 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/08 22:43:30 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void type_conversion(char c, t_info_flags *flags)
{
	if (c == 'c')
		flags->type = 'c';
	if (c == 's')
		flags->type = 's';
	if (c == 'p')
		flags->type = 'p';
	if (c == 'd')
		flags->type = 'd';
	if (c == 'i')
		flags->type = 'i';
	if (c == 'u')
		flags->type = 'u';
	if (c == 'x')
		flags->type = 'x';
	if (c == 'X')
		flags->type = 'X';
}

// void type_conversion(char *str, int i, va_list *arg)
// {
// 	if (str[i] == 'c')
// 		va_arg(arg, char);
// 	if (str[i] == 's')
// 		va_arg(arg, char*);
// 	if (str[i] == 'p')
// 		va_arg(arg, void*);
// 	if (str[i] == 'd')
// 		va_arg(arg, int);
// 	if (str[i] == 'i')
// 		va_arg(arg, int);
// 	if (str[i] == 'u')
// 		va_arg(arg, unsigned int);
// 	if (str[i] == 'x')
// 		va_arg(arg, int);
// 	if (str[i] == 'X')
// 		va_arg(arg, int);
// }


t_info_flags reconize_flags(char c, t_info_flags *flags)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		type_conversion(c, flags);
	return(*flags);
}

//cspdiuxX

// char	*printf_strdup(const char *s)
// {
// 	char	*dest;
// 	int		i;

// 	if ((dest = malloc(sizeof(char) * gnl_strlen(s) + 1)) == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*content_before_arg(char *buff, char c)
// {
// 	int		i;
// 	int		j;
// 	char	*res;

// 	i = 0;
// 	while (buff[i] != c && buff[i])
// 		i++;
// 	if ((res = malloc(sizeof(char) * (i + 1))) == NULL)
// 		return (NULL);
// 	j = -1;
// 	while (++j < i)
// 		res[j] = buff[j];
// 	res[j] = 0;
// 	return (res);
// }

int ft_printf(const char *format, ...)
{
	int i;
	int printed_char;
	t_info_flags flags;
//	va_list arg;

	i = 0;
	printed_char = 0;
//	va_start(args, format);
//	t_info table = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, format};
//	printf("format apres initialisation dans struct = %s", table.format);
	while (format[i])
	{
		while(format[i] != '%')
			i++;
		i++;
		flags = reconize_flags(format[i], &flags);
		printf("type = %c, format[i] = %c\n", flags.type, format[i]);
		

	}
//	va_end(arg);
	return(printed_char);
}

int main()
{
	int a = 1;
	int b = 10;
	int c = 3;
//	int d = 4;
	setbuf(stdout, NULL);
	ft_printf("test\n %d", b);
	printf("Bibli : %d, %10.1d, %d\n", a, b, c);
	return(0);
}