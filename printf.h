/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/08 22:32:38 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>

typedef struct	s_info_flags
{
	char type;
	int printed;
	int index;
	const char *format;
}				t_info_flags;

int ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

#endif