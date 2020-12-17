/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 16:31:19 by tdayde           ###   ########lyon.fr   */
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
	int neg;
	int printed;
	int i;
}				arg_info;

int		ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
int		print_arg(arg_info *t, va_list arg);

void	reconize_table(arg_info *t, const char *s);

void	print_noargs(arg_info *t, const char *s);
void	print_width_before(arg_info *t, int len_arg);
void	print_width_after(arg_info *t, int len_arg);

void	check_width(arg_info *t, va_list arg);
// void	check_width_str(arg_info *t, char **s, va_list arg);
// void	check_width_int(arg_info *t, int *c, va_list arg);

void	check_precision(arg_info *t, va_list arg);
// void	check_precision_str(arg_info *t, char **s, va_list arg);

size_t	ft_strlen(const char *s);
void	ft_putstr_printf(char *s, arg_info *table);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd_printf(long long n, int fd, arg_info *t);
void	ft_putnbr_base_printf(long long nbr, char *base, arg_info *t);
void	ft_putnbr_base_printf_ptr(unsigned long long nbr, char *base, arg_info *t);

void	print_char(arg_info *t, va_list arg);
void	print_str(arg_info *t, va_list arg);
void	print_percent(arg_info *t, va_list arg);
void	print_int(arg_info *t, va_list arg);
void	print_ptr(arg_info *t, va_list arg);

#endif