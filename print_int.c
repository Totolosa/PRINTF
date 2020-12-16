/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:35:37 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/16 19:39:14 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nbr_of_digit(long long n)
{
	int nbr_of_digit;
	long long nbr;

	nbr = n;
	nbr_of_digit = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		nbr_of_digit++;
		nbr /= 10;
	}
	return(nbr_of_digit);
}

int nbr_of_digit_with_precision(t_info_resolution *t, long long nbr)
{
	int res;

	if (nbr == 0 && t->prec == 0)
		return (0);
	res = nbr_of_digit(nbr);
	if (t->prec > res)
		res = t->prec;
	if (nbr < 0)
		res++;
	return (res);
}

void	print_int_with_precision(t_info_resolution *t, long long nbr)
{
	int tmp;
	
	tmp = t->prec;
	if (t->prec == 0 && nbr == 0)
		return ;
	if (nbr < 0 && t->prec != -2)
	{
		write(1, "-", 1);
		t->printed++;
	}
	while (tmp-- > nbr_of_digit(nbr))
	{
		write(1, "0", 1);
		t->printed++;
	}
	if (t->type == 'i' || t->type == 'd' || t->type == 'u')
		ft_putnbr_fd_printf(nbr, 1, t);
	if (t->type == 'x' || t->type == 'X' || t->type == 'p')
		ft_putnbr_base(nbr, "0123456789abcdef", t);
}

void	print_int(t_info_resolution *t, va_list arg)
{
	long long	nbr;
	
	check_width(t, arg);
//	check_width_str(t, &str, arg);
	check_precision(t, arg);
//	check_precision_str(t, &str, arg);
	if (t->type == 'd' || t->type == 'i')
		if ((nbr = (int)va_arg(arg, int)) < 0)
			t->neg = 1;
	if (t->type == 'u' || t->type == 'x' || t->type == 'X')
		nbr = (unsigned int)va_arg(arg, unsigned int);
//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
	print_width_before(t, nbr_of_digit_with_precision(t, nbr));
	print_int_with_precision(t, nbr);
	print_width_after(t, nbr_of_digit_with_precision(t, nbr));
}

