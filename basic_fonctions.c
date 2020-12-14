/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:28:00 by tdayde            #+#    #+#             */
/*   Updated: 2020/12/14 22:51:36 by tdayde           ###   ########lyon.fr   */
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

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	if ((dest = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

