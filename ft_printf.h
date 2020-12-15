/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/15 19:33:23 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_info_resolution
{
	int flags;
	int width;
	int prec;
	char type;
	int printed;
	int i;
}				t_info_resolution;

int		ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

int		print_arg(t_info_resolution *t, va_list arg);
void	print_width_before(t_info_resolution *t, int len_arg);
void	print_width_after(t_info_resolution *t, int len_arg);

void	check_width(t_info_resolution *t, va_list arg);
// void	check_width_str(t_info_resolution *t, char **s, va_list arg);
// void	check_width_int(t_info_resolution *t, int *c, va_list arg);

void	check_precision(t_info_resolution *t, va_list arg);
// void	check_precision_str(t_info_resolution *t, char **s, va_list arg);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_putstr_printf(char *s, t_info_resolution *table);
void	ft_bzero(void *s, size_t n);

void	print_char(t_info_resolution *t, va_list arg);

void	print_percent(t_info_resolution *t, va_list arg);

void	print_str(t_info_resolution *t, va_list arg);

#endif