/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other_than_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:14:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/18 14:34:40 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_before(arg_info *t, int len_arg)
{
	int i;
	
	i = -1;
//	printf("\nflags = %c, width = %d, precision = %d, len_Arg = %d\n", t->flags, t->width, t->prec, len_arg);
//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
	if (t->flags == '1')
		while (++i < t->width - len_arg)
		{
			write(1, " ", 1);
			t->printed++;
		}
	if (t->flags == '0')
	{
		if (t->neg == 1 && t->prec == -2)
		{
			write(1, "-", 1);
			t->neg = 0;
			t->printed++;
		}
		while (++i < t->width - len_arg)
		{
			write(1, "0", 1);
			t->printed++;
		}
	}
}

void	print_width_after(arg_info *t, int len_arg)
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

void	print_noargs(arg_info *t, const char *s)
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




