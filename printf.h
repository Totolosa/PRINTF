/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/10 18:32:49 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_info_resolution
{
	char flags;
	int width;
	int prec;
	char type;
	int printed;
	int i;
//	const char *format;
}				t_info_resolution;

int ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

#endif