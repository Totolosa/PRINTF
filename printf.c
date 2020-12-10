/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:42:32 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/09 18:53:58 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void type_conversion(t_info_resolution *table, char c)
{
	if (c == 'c')
		table->type = 'c';
	if (c == 's')
		table->type = 's';
	if (c == 'p')
		table->type = 'p';
	if (c == 'd')
		table->type = 'd';
	if (c == 'i')
		table->type = 'i';
	if (c == 'u')
		table->type = 'u';
	if (c == 'x')
		table->type = 'x';
	if (c == 'X')
		table->type = 'X';
	if (c == '%')
		table->type = '%';
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
//	if (str[i] == '%')
// 		va_arg(arg, int);
// }

void	reinitialize_table(t_info_resolution *table)
{
	table->flags = 0;
	table->width = 0;
	table->prec = 0;
	table->type = '\0';
	printf("table->type = %c\n", table->type);
}

void	reconize_flags(t_info_resolution *t, const char *s)
{
	if (s[t->i] == '-')
		t->flags = '-';
	if (s[t->i] == '0')
		t->flags = '0';
	t->i++;
}

void	reconise_width(t_info_resolution *t, const char *s)
{
	int width;
	
	width = 0;
	if (s[t->i] >= '*')
		t->width = -1;
	while (s[t->i] >= '0' && s[t->i] <= '9')
	{
		width = width * 10 + s[t->i] - '0';
		t->i++;
	}
		
	if (s[t->i] == '0')
		t->flags = '0';
	t->i++;
}

void	reconize_table(t_info_resolution *t, const char *s)
{
	reconize_flags(t, s);

	
	if (s[t->i] == 'c' || s[t->i] == 's' || s[t->i] == 'p' || s[t->i] == 'd'
		|| s[t->i] == 'i' || s[t->i] == 'u' || s[t->i] == 'x' || s[t->i] == 'X'
		|| s[t->i] == '%')
		type_conversion(t, s[t->i]);
	t->i++;
}

void	print_noargs(t_info_resolution *table, const char *format)
{
	while (format[(table->i)] != '%' && format[(table->i)])
	{
		write(1, &format[table->i], 1);
		table->printed++;
		(table->i)++;
	}
	if (format[table->i])
		(table->i)++;
	if (format[(table->i)] == '%')
	{
		write(1, &format[table->i], 1);
		table->printed++;
		(table->i)++;
		print_noargs(table, format);
	}
}

int ft_printf(const char *format, ...)
{
	t_info_resolution table;
//	va_list arg;

//	va_start(args, format);
//	t_info_resolution table = {0, 0, 0, 0, 0, 0};
//	printf("format apres initialisation dans struct = %s", table.format);
	while (format[(table.i)])
	{
		print_noargs(&table, format);
		reconize_table(&table, format);
		printf("flags =  || width =  || prec =  || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.type, table.printed, table.i, format[table.i - 1]);
		/* PRINT AVEC FLAGS*/

	//	reinitialize_table(&table);
	//	printf("flags =  || width =  || prec =  || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.type, table.printed, table.i, format[table.i - 1]);
	}
//	va_end(arg);
	return(table.printed);
}

int main()
{
	int a = 333;
	int b = 9;
	int c = 3;
//	int d;
	setbuf(stdout, NULL);
//	ft_printf("ligne 1\nligne 2 100%%\nPremier appel %%d %uDeuxieme appel %%d %d");
	printf("Bibli : %010d, %10%, %d\n", a, b, c);
	return(0);
}