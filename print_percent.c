/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:19:43 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/16 13:58:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_info_resolution *t, va_list arg)
{
	
	check_width(t, arg);
	check_precision(t, arg);
	print_width_before(t, 1);
	write(1, "%", 1);
	t->printed++;
	print_width_after(t, 1);
}