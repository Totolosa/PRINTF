/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:39:58 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 12:13:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_str_with_precision(arg_info *t, char* str)
{
	int len_str;

	len_str = ft_strlen(str);
//	printf("\nflags = %c, width = %d, precision = %d\n", t->flags, t->width, t->prec);
	if (!str && (t->prec >= 0 && t->prec < 6))
		return (t->prec);
	if (!str && (t->prec == -2 || t->prec >= 6))
		return (6);
	if (t->prec == -2 || t->prec > len_str)
		return (len_str);
	else
		return (t->prec);
}

static void	print_str_with_precision(arg_info *t, char *str)
{
	int i;

	i = -1;
	if (str == NULL)
	{
		if (t->prec > 6 || t->prec < 0)
			t->prec = 6;
		write(1, "(null)", t->prec);
		t->printed += t->prec;
		return ;
	}
	if (t->prec == -2)
		ft_putstr_printf(str, t);
	while (++i < t->prec && str[i])
	{
		write(1, &str[i], 1);
		t->printed++;
	}
}

void		print_str(arg_info *t, va_list arg)
{
	char	*str;

	check_width(t, arg);
//	check_width_str(t, &str, arg);
	check_precision(t, arg);
//	check_precision_str(t, &str, arg);
	str = (char*)va_arg(arg, char*);
	print_width_before(t, len_str_with_precision(t, str));
	print_str_with_precision(t, str);
	print_width_after(t, len_str_with_precision(t, str));
}
