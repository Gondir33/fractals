/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:17:18 by marvin            #+#    #+#             */
/*   Updated: 2021/10/04 23:17:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_count(int n, int *flag)
{
	int	len;

	len = 0;
	if (n >= 0)
		*flag = 1;
	else
	{
		*flag = -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	while (n < 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_fillitoa(char *s, int n, int len)
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

char	*ft_itoa(int n)
{
	int		len;
	int		flag;
	char	*s;

	len = ft_count(n, &flag);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s = ft_fillitoa(s, n, len);
	if (flag == -1)
		s[0] = '-';
	return (s);
}
