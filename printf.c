/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:42:32 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/10 18:32:47 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void reconize_type(t_info_resolution *t, char c)
{
	if (c == 'c')
		t->type = 'c';
	if (c == 's')
		t->type = 's';
	if (c == 'p')
		t->type = 'p';
	if (c == 'd')
		t->type = 'd';
	if (c == 'i')
		t->type = 'i';
	if (c == 'u')
		t->type = 'u';
	if (c == 'x')
		t->type = 'x';
	if (c == 'X')
		t->type = 'X';
	if (c == '%')
		t->type = '%';
	t->i++;
//	printf("t->type = %c\n", t->type);
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

// void	reinitialize_table(t_info_resolution *table)
// {
// 	table->flags = 0;
// 	table->width = 0;
// 	table->prec = 0;
// 	table->type = '\0';
// 	printf("table->type = %c\n", table->type);
// }

void	reconize_flags(t_info_resolution *t, const char *s)
{
	if (s[t->i] == '-')
		t->flags = '-';
	if (s[t->i] == '0')
		t->flags = '0';
	if (s[t->i] == '0' || s[t->i] == '-')
		t->i++;
}

void	reconize_width(t_info_resolution *t, const char *s)
{
	int width;
	
	width = 0;
	if (s[t->i] == '*')
	{
		width = -1;
		t->i++;
	}	
	while (s[t->i] >= '0' && s[t->i] <= '9')
		width = width * 10 + s[t->i++] - '0';
	t->width = width;
}

void	reconize_precision(t_info_resolution *t, const char *s)
{
	int precision;

	precision = 0;
	if (s[t->i] == '.')
	{
		t->i++;
		if (s[t->i] == '*')
		{
			precision = -1;
			t->i++;
		}
		while (s[t->i] >= '0' && s[t->i] <= '9')
			precision = precision * 10 + s[t->i++] - '0';
		t->prec = precision;
	}
}

void	reconize_table(t_info_resolution *t, const char *s)
{
//	printf("format[i] avant reconize_flags = %c\n", s[t->i]);
	reconize_flags(t, s);
//	printf("format[i] avant reconize_width = %c\n", s[t->i]);
	reconize_width(t, s);
//	printf("format[i] avant reconize_precision = %c\n", s[t->i]);
	reconize_precision(t, s);
//	printf("format[i] avant reconize_type = %c\n", s[t->i]);
	reconize_type(t, s[t->i]);
//	printf("t->type = %c\n", t->type);
//	t->i++;
}

void	print_noargs(t_info_resolution *t, const char *s)
{
	while (s[(t->i)] != '%' && s[(t->i)])
	{
		write(1, &s[t->i], 1);
		t->printed++;
		(t->i)++;
	}
	if (s[t->i])
		(t->i)++;
	if (s[(t->i)] == '%')
	{
		write(1, &s[t->i], 1);
		t->printed++;
		(t->i)++;
		print_noargs(t, s);
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
		if (table-> == '%')
			print_percent(table);
		asign_type_to_arg(arg, table);
		print_arg(arg, table);
		printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.flags, table.width, table.prec, table.type, table.printed, table.i, format[table.i - 1]);
		/* PRINT AVEC FLAGS*/

	//	reinitialize_table(&table);
	//	printf("flags =  || width =  || prec =  || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.type, table.printed, table.i, format[table.i - 1]);
	}
//	va_end(arg);
	return(table.printed);
}

int main()
{
	int a = 100;
	int b = 5;
	int c = 3;
//	int d;
	setbuf(stdout, NULL);
	ft_printf("%%\n%c%s%p%d%i%u%x%X%9%");
//	printf("Bibli : %-*%", a, b);
	return(0);
}