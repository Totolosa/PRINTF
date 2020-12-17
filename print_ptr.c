/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:25:06 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 16:32:43 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_printf_ptr(unsigned long long nbr, char *base, arg_info *t)
{
	unsigned long long len_base;
	char tmp;
	
	tmp = 0;
	len_base = ft_strlen(base);
		if (nbr >= 0 && nbr < len_base)
		{
			if (t->type == 'x' || t-> type == 'p'
								|| (t->type == 'X' && nbr < 10))
				write(1, &base[nbr], 1);
			if (t->type == 'X' && nbr >= 10)
			{
				tmp = base[nbr] - 32;
				write(1, &tmp, 1);
			}
			t->printed++;
		}
		if (nbr >= len_base)
		{
			ft_putnbr_base_printf(nbr / len_base, base, t);
			ft_putnbr_base_printf(nbr % len_base, base, t);
		}
}

int nbr_of_digit(arg_info *t, unsigned long long nbr)
{
	int nbr_of_digit;
	int base;

	if (t->type == 'i' || t->type == 'd' || t->type == 'u')
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

int nbr_of_digit_with_precision(arg_info *t, unsigned long long nbr)
{
	int res;

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
	if (nbr < 0 && t->prec != -2)
	{
		write(1, "-", 1);
		t->printed++;
	}
	if (t->type == 'p')
	{
		write(1, "0x", 2);
		t->printed +=2;
	}
	while (tmp-- > n)
	{
		write(1, "0", 1);
		t->printed++;
	}
	if (t->type == 'i' || t->type == 'd' || t->type == 'u')
		ft_putnbr_fd_printf(nbr, 1, t);
	if (t->type == 'x' || t->type == 'X' || t->type == 'p')
		ft_putnbr_base_printf(nbr, "0123456789abcdef", t);
}

void	print_ptr(arg_info *t, va_list arg)
{
	unsigned long long	nbr;
	
	nbr = (unsigned long long)va_arg(arg, unsigned long long);
	printf("\nnbr = %llu\n", nbr);
	// if (t->type == 'p' || t->type == 'c')
	// 	t->prec = 0;
	print_width_before(t, nbr_of_digit_with_precision(t, nbr));
	print_int_with_precision(t, nbr, nbr_of_digit(t, nbr));
//	printf("\ntest\n");
	print_width_after(t, nbr_of_digit_with_precision(t, nbr));
}

