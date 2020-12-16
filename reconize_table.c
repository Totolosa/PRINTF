/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconize_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:51:40 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/16 16:31:35 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reconize_flags(t_info_resolution *t, const char *s)
{
	if (s[t->i] == '0' || s[t->i] == '-')
	{
		if (s[t->i] == '0')
		{
			t->flags = '0';
			t->i++;
		}
	//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
		if (s[t->i] == '-')
		{
			t->flags = '-';
			t->i++;
		}
	}
	else
		t->flags = '1';
	while (s[t->i] == '0')
			t->i++;
}

static void	reconize_width(t_info_resolution *t, const char *s)
{
	int width;
	
	width = 0;
	if (s[t->i] == '*')
	{
		width = -1;
		t->i++;
	}	
	while (s[t->i] >= '0' && s[t->i] <= '9')
		width = width * 10 + s[t->i++] - '0';
	t->width = width;
}

static void	reconize_precision(t_info_resolution *t, const char *s)
{
	int precision;

	precision = 0;
	if (s[t->i] == '.')
	{
		t->i++;
		if (s[t->i] == '*')
		{
			precision = -1;
			t->i++;
		}
		while (s[t->i] >= '0' && s[t->i] <= '9')
			precision = precision * 10 + s[t->i++] - '0';
		t->prec = precision;
	}
	else 
		t->prec = -2;
}

static void	reconize_type(t_info_resolution *t, char c)
{
	if (c == 'c')
		t->type = 'c';
	if (c == 's')
		t->type = 's';
	if (c == 'p')
		t->type = 'p';
	if (c == 'd')
		t->type = 'd';
	if (c == 'i')
		t->type = 'i';
	if (c == 'u')
		t->type = 'u';
	if (c == 'x')
		t->type = 'x';
	if (c == 'X')
		t->type = 'X';
	if (c == '%')
		t->type = '%';
	t->i++;
}

void		reconize_table(t_info_resolution *t, const char *s)
{
//	printf("format[i] avant reconize_flags = %c\n", s[t->i]);
	reconize_flags(t, s);
//	printf("format[i] avant reconize_width = %c, format[i+1] = %c\n", s[t->i], s[t->i+1]);
	reconize_width(t, s);
//	printf("format[i] avant reconize_precision = %c\n", s[t->i]);
	reconize_precision(t, s);
//	printf("format[i] avant reconize_type = %c\n", s[t->i]);
	reconize_type(t, s[t->i]);
//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
//	printf("t->type = %c\n", t->type);
//	t->i++;
}