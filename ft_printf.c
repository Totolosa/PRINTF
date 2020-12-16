/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:42:32 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/16 19:15:35 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reinitialize_table(t_info_resolution *table)
{
	table->flags = 0;
	table->width = 0;
	table->prec = 0;
	table->type = 0;
	table->neg = 0;
}

int		print_arg(t_info_resolution *t, va_list arg)
{
	//printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
	if (t->type == 'c')
		print_char(t, arg);
	if (t->type == 's')
		print_str(t, arg);
	if (t->type == 'd' || t->type == 'i' || t->type == 'u' ||
			 t->type == 'x' || t->type == 'X')
		print_int(t, arg);
	// if (t->type == 'u' || t->type == 'x' || t->type == 'X')
	// 	va_arg(arg, unsigned int);
			
	
	// if (t->type == 'p')
	// 	va_arg(arg, void*);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	t_info_resolution table;
	va_list arg;

	va_start(arg, format);
	ft_bzero(&table, sizeof(t_info_resolution));
//	printf("format apres initialisation dans struct = %s", format);
	while (format[(table.i)])
	{
		print_noargs(&table, format);
		if (format[table.i])
		{
			reconize_table(&table, format);
			if (table.type == '%')
				print_percent(&table, arg);
		//	printf("\nAVANT PRINT_ARGS : flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.flags, table.width, table.prec, table.type, table.printed, table.i, format[table.i - 1]);
			if ((print_arg(&table, arg)) == 0)
				return (-1);
		//	printf("\nprinted = %d\n", table.printed);
			reinitialize_table(&table);
		
		}
	//	printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.flags, table.width, table.prec, table.type, table.printed, table.i, format[table.i - 1]);


	//	printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d || format[i - 1] = %c\n", table.flags, table.width, table.prec, table.type, table.printed, table.i, format[table.i - 1]);
	}
	va_end(arg);
	return(table.printed);

	// (void)format;
	// write(1, "0", 1);
	// return (1);
}

