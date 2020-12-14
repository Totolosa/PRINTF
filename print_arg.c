/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:14:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/14 22:51:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int		count_nbr_output()

int		print_arg(t_info_resolution *t, va_list arg)
{


	//printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
	if (t->type == 'c')
		print_char(t, arg);
	if (t->type == 's')
		print_str(t, arg);
			
	
	// if (t->type == 'p')
	// 	va_arg(arg, void*);
	// if (t->type == 'u' || t->type == 'x' || t->type == 'X')
	// 	va_arg(arg, unsigned int);
	// if (t->type == 'd' || t->type == 'i')
	// 	va_arg(arg, int);
	return (1);
}

void	print_width_before(t_info_resolution *t, int len_arg)
{
	int i;
	
	i = -1;
//	printf("\nflags = %c, width = %d, precision = %d, len_Arg = %d\n", t->flags, t->width, t->prec, len_arg);
	if (t->flags == '1')
		while (++i < t->width - len_arg)
		{
			write(1, " ", 1);
			t->printed++;
		}
	if (t->flags == '0')
		while (++i < t->width - len_arg)
		{
			write(1, "0", 1);
			t->printed++;
		}
}

void	print_width_after(t_info_resolution *t, int len_arg)
{	
	int i;

	i = -1;
	if (t->flags == '-')
		while (++i < t->width - len_arg)
		{
			write(1, " ", 1);
			t->printed++;
		}
}





