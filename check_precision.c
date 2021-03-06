/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:36:17 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 14:02:15 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_precision(arg_info *t, va_list arg)
{
	if (t->prec == -1)
	{
		t->prec = (int)va_arg(arg, int);
		if (t->prec < 0)
		{
			// if (t->type == 's')
				t->prec = -2;
			// else
			// 	t->prec = 1;
		}
	}
	if (t->prec != -2 && t->flags == '0' && t->type != 's' )
		t->flags = '1';
//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
}

// void		check_precision_str(arg_info *t, char **s, va_list arg)
// {
// 	int next;

// //	printf("\ns = %s, prec = %d\n", *s, t->prec);
// 	next = (int)*s;
// 	if (t->prec == -1)
// 	{
// 		if (next < 0)
// 			t->prec = -2;
// 		else
// 			t->prec = next;
// 		*s = (char*)va_arg(arg, char*);
// 	}
// }
