/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:32:41 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 12:13:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(arg_info *t, va_list arg)
{
	int c;
	
	check_width(t, arg);
//	check_width_int(t, &c, arg);
	c = va_arg(arg, int);
	print_width_before(t, 1);
	write(1, &c, 1);
	t->printed++;
//	printf("\nprinted = %d\n", t->printed);
	print_width_after(t, 1);
}
