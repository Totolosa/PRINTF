/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:14:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/11 23:28:53 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_printf(char *s, t_info_resolution *table)
{
	int i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[++i])
	{
		write(1, &s[i], 1);
		table->printed++;
	}
}



//int		count_nbr_output()

void	print_arg(t_info_resolution *t, va_list arg)
{
	char argc;
	char *argstr;
	void *argp;
	unsigned int argunsint;
	int argint;

	//printf("flags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
	if (t->type == 'c')
		print_char(t, arg);
	if (t->type == 's')
		return(ft_putstr_printf(argstr = va_arg(arg, char*), t));
	
	// if (t->type == 'p')
	// 	va_arg(arg, void*);
	// if (t->type == 'u' || t->type == 'x' || t->type == 'X')
	// 	va_arg(arg, unsigned int);
	// if (t->type == 'd' || t->type == 'i')
	// 	va_arg(arg, int);
}

void	check_width_char(t_info_resolution *t, int *c, va_list arg)
{
	if (t->width == -1)
	{
		if (*c < 0)
		{
			t->flags = '-';
			t->width = *c * -1;
		}	
		else
			t->width = *c;
		*c = va_arg(arg, int);
	}
}

void	print_char(t_info_resolution *t, va_list arg)
{
	int i;
	int c;
	
	i = -1;
	c = va_arg(arg, int);
	check_width_char(t, &c, arg);
	if (t->flags == '0')
		while (++i < t->width - 1)
		{
			write(1, "0", 1);
			t->printed++;
		}
	write(1, &c, 1);
	t->printed++;
	if (t->flags == '-')
		while (++i < t->width - 1)
		{
			write(1, " ", 1);
			t->printed++;
		}
}

// void	print_str(t_info_resolution *t, va_list arg)
// {

// }