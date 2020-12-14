/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:36:17 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/14 22:51:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_precision_str(t_info_resolution *t, char **s, va_list arg)
{
	int next;

//	printf("\ns = %s, prec = %d\n", *s, t->prec);
	next = (int)*s;
	if (t->prec == -1)
	{
		if (next < 0)
			t->prec = -2;
		else
			t->prec = next;
		*s = va_arg(arg, char*);
	}
}