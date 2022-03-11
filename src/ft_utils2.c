/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:49:45 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 01:49:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printuns(t_param *param, int i)
{
	char			*s;
	unsigned int	n;

	n = va_arg(param->arg, unsigned int);
	s = ft_itoa_uns(n);
	if (!s)
		return (-1);
	param->len += write(1, s, ft_strlen(s));
	free(s);
	return (i + 1);
}

int	ft_printsmallhex(t_param *param, int i)
{
	unsigned int	x;
	char			*s;

	x = va_arg(param->arg, unsigned int);
	if (x == 0)
		param->len += write(1, "0", 1);
	else
	{
		s = ft_itoa_small_hex(x);
		if (!s)
			return (-1);
		param->len += write(1, s, ft_strlen(s));
		free(s);
	}
	return (i + 1);
}

int	ft_printbighex(t_param *param, int i)
{
	unsigned int	x;
	char			*s;

	x = va_arg(param->arg, unsigned int);
	if (x == 0)
		param->len += write(1, "0", 1);
	else
	{
		s = ft_itoa_big_hex(x);
		if (!s)
			return (-1);
		param->len += write(1, s, ft_strlen(s));
		free(s);
	}
	return (i + 1);
}
