/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:36:17 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/15 19:17:51 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_precision(t_info_resolution *t, va_list arg)
{
	if (t->prec == -1)
	{
		t->prec = (int)va_arg(arg, int);
		if (t->prec < 0)
		{
			if (t->type == 's')
				t->prec = -2;
		}
	}
}

// void		check_precision_str(t_info_resolution *t, char **s, va_list arg)
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
