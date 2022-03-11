/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:45:23 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 01:45:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_small_hex(unsigned int x)
{
	char			*s;
	int				len;

	len = ft_len_hex(x);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = ft_small_symbol(x % 16);
		x = x / 16;
		len--;
	}
	return (s);
}

char	*ft_itoa_big_hex(unsigned int x)
{
	char			*s;
	int				len;

	len = ft_len_hex(x);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = ft_big_symbol(x % 16);
		x = x / 16;
		len--;
	}
	return (s);
}
