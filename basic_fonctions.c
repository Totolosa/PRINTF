/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:28:00 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/17 16:06:57 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_printf(char *s, arg_info *table)
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

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	(void)s;
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = -1;
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd_printf(long long nbr, int fd, arg_info *t)
{
	long long n;

	n = nbr;
	// if (n == -2147483648)
	// {
	// 	ft_putstr_fd("-2147483648", fd);
	// 	return ;
	// }
	if (n < 0)
		n *= -1;
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
		t->printed++;
	}
	if (n > 9)
	{
		ft_putnbr_fd_printf(n / 10, fd, t);
		ft_putnbr_fd_printf(n % 10, fd, t);
	}
}

void	ft_putnbr_base_printf(long long nbr, char *base, arg_info *t)
{
	long long len_base;
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