/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:35:37 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/18 17:17:41 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int nbr_of_digit(arg_info *t, long long nbr)
{
	int nbr_of_digit;
	int base;

	if (t->type == 'i' || t->type == 'd' || t->type == 'u' || t->type == 'c')
		base = 10;
	if (t->type == 'x' || t->type == 'X' || t->type == 'p')
		base = 16;
	nbr_of_digit = 1;
	if (nbr < 0)
		nbr *= -1;
//	printf("\nnbr = %lld, nbr_of_digit = %d\n", nbr, nbr_of_digit);
	while (nbr / base > 0)
	{
		nbr_of_digit++;
		nbr /= base;
	}
	return(nbr_of_digit);
}

int nbr_of_digit_with_precision(arg_info *t,long long nbr)
{
	int res;

	if (t->type == 'c')
		return (1);
	if (nbr == 0 && t->prec == 0)
		return (0);
	res = nbr_of_digit(t, nbr);
	if (t->prec > res && t->type != 'p' && t->type != 'c')
		res = t->prec;
	if (nbr < 0)
		res++;
	if (t->type == 'p')
		res += 2;
	return (res);
}


void	print_int_with_precision(arg_info *t, long long nbr, int n)
{
	int tmp;
	
	tmp = t->prec;
	if (t->prec == 0 && nbr == 0)
		return ;
	if (t->neg == 1)
	{
		write(1, "-", 1);
		t->printed++;
	}
	while (tmp-- > n)
	{
		write(1, "0", 1);
		t->printed++;
	}
	if (t->type == 'c')
	{
		write(1, &nbr, 1);
		t->printed++;
	}
	if (t->type == 'i' || t->type == 'd' || t->type == 'u')
		ft_putnbr_fd_printf(nbr, 1, t);
	if (t->type == 'x' || t->type == 'X' || t->type == 'p')
		ft_putnbr_base_printf(nbr, "0123456789abcdef", t);
}

void	print_int(arg_info *t, va_list arg)
{
	long long	nbr;
	
	check_width(t, arg);
//	check_width_str(t, &str, arg);
//	if (t->type != 'p')
	check_precision(t, arg);
//	printf("\nflags = %c || width = %d || prec = %d || type = %c || printed = %d || i = %d\n", t->flags, t->width, t->prec, t->type, t->printed, t->i);
//	check_precision_str(t, &str, arg);
	if (t->type == 'd' || t->type == 'i' || t->type == 'c')
		if ((nbr = (int)va_arg(arg, int)) < 0 && t->type != 'c')
			t->neg = 1;
	if (t->type == 'u' || t->type == 'x' || t->type == 'X')
		nbr = (unsigned int)va_arg(arg, unsigned int);
	if (t->type == 'p')
	{
		print_ptr(t, arg);
		return ;
	}
//	printf("\nnbr = %lld\n", nbr);
	// if (t->type == 'p' || t->type == 'c')
	// 	t->prec = 0;
	print_width_before(t, nbr_of_digit_with_precision(t, nbr));
	print_int_with_precision(t, nbr, nbr_of_digit(t, nbr));
//	printf("\ntest\n");
	print_width_after(t, nbr_of_digit_with_precision(t, nbr));
}

