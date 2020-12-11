/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/11 22:33:59 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_info_resolution
{
	int flags;
	int width;
	int prec;
	char type;
	int printed;
	int i;
//	const char *format;
}				t_info_resolution;

int		ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

void	print_arg(t_info_resolution *t, va_list arg);

size_t	ft_strlen(const char *s);

void	ft_putstr_printf(char *s, t_info_resolution *table);

void	print_char(t_info_resolution *t, va_list arg);

#endif