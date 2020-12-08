/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:42:32 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/08 15:36:58 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int conversion_type(char c)
{
	if (c == 'c')
		
}

void *conversion(char c, char *str, int i)
{
	if(c != '%')
		return (0);
	i++;	
	if (str[i] == )
}

//cspdiuxX

int ft_printf(const char *format, ...)
{
	int printed_char;

	printed_char = 0;
	while (!conversion(format[i], format, i) && format[i])
		i++;


	return(printed_char);
}

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	printf("Bibli : %d, %*d, %d\n", a, b, c, d);
	return(0);
}