/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:32:41 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/14 22:51:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_info_resolution *t, va_list arg)
{
	int c;
	
	c = va_arg(arg, int);
	check_width_int(t, &c, arg);
	print_width_before(t, 1);
	write(1, &c, 1);
	t->printed++;
	print_width_after(t, 1);
}