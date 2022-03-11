/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:18:39 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 01:18:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_hex(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	ft_small_symbol(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	else
		return ('f');
}

char	ft_big_symbol(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	if (n == 10)
		return ('A');
	if (n == 11)
		return ('B');
	if (n == 12)
		return ('C');
	if (n == 13)
		return ('D');
	if (n == 14)
		return ('E');
	else
		return ('F');
}

char	*ft_itoa_address(unsigned long long n)
{
	int		len;
	char	*s;

	len = ft_len_hex(n);
	s = malloc(len + 3);
	if (!s)
		return (NULL);
	s[len + 2] = 0;
	len--;
	while (len >= 0)
	{
		s[len + 2] = ft_small_symbol(n % 16);
		n = n / 16;
		len--;
	}
	s[0] = '0';
	s[1] = 'x';
	return (s);
}
