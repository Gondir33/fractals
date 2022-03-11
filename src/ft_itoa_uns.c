/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:49:01 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 01:49:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_uns_count(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_fill_uns_itoa(char *s, unsigned int n, int len)
{
	s[len] = '\0';
	len--;
	if (n > 0)
	{
		while (len > -1)
		{
			s[len] = n % 10 + 48;
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len > -1)
		{
			s[len] = (n % 10) * (-1) + 48;
			n = n / 10;
			len--;
		}
	}
	return (s);
}

char	*ft_itoa_uns(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_uns_count(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s = ft_fill_uns_itoa(s, n, len);
	return (s);
}
