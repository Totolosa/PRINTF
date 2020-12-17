/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:03:22 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 12:13:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(arg_info *t, va_list arg)
{
	if (t->width == -1)
	{
		t->width = (int)va_arg(arg, int);
		if (t->width < 0)
		{
			t->flags = '-';
			t->width = t->width * -1;
		}
	}
}

// void	check_width_int(arg_info *t, int *c, va_list arg)
// {
// 	if (t->width == -1)
// 	{
// 		if (*c < 0)
// 		{
// 			t->flags = '-';
// 			t->width = *c * -1;
// 		}	
// 		else
// 			t->width = *c;
// 		*c = va_arg(arg, int);
// 	}
// }

// void	check_width_str(arg_info *t, char **s, va_list arg)
// {
// 	int next;

// 	next = (int)*s;
// 	if (t->width == -1)
// 	{
// 		if (next < 0)
// 		{
// 			t->flags = '-';
// 			t->width = next * -1;
// 		}	
// 		else
// 			t->width = next;
// 		*s = (char*)va_arg(arg, char*);
// 	}
// }
