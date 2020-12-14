/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:03:22 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/14 22:51:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_int(t_info_resolution *t, int *c, va_list arg)
{
	if (t->width == -1)
	{
		if (*c < 0)
		{
			t->flags = '-';
			t->width = *c * -1;
		}	
		else
			t->width = *c;
		*c = va_arg(arg, int);
	}
}

void	check_width_str(t_info_resolution *t, char **s, va_list arg)
{
	int next;

	next = (int)*s;
	if (t->width == -1)
	{
		if (next < 0)
		{
			t->flags = '-';
			t->width = next * -1;
		}	
		else
			t->width = next;
		*s = va_arg(arg, char*);
	}
}