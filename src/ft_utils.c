/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:03:49 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 01:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_printdig(t_param *param, int i)
{
	char	*s;
	int		n;

	n = va_arg(param->arg, int);
	s = ft_itoa(n);
	if (!s)
		return (-1);
	param->len += write(1, s, ft_strlen(s));
	free(s);
	return (i + 1);
}

int	ft_printchar(t_param *param, int i)
{
	char	c;

	c = (char)va_arg(param->arg, int);
	param->len += write(1, &c, 1);
	return (i + 1);
}

int	ft_printstr(t_param *param, int i)
{
	char	*s;

	s = va_arg(param->arg, char *);
	if (!s)
		param->len += write(1, "(null)", 6);
	else
		param->len += write(1, s, ft_strlen(s));
	return (i + 1);
}

int	ft_printaddress(t_param *param, int i)
{
	unsigned long long	address;
	char				*s;

	address = va_arg(param->arg, unsigned long long);
	if (address == 0)
		param->len += write(1, "0x0", 3);
	else
	{
		s = ft_itoa_address(address);
		if (!s)
			return (-1);
		param->len += write(1, s, ft_strlen(s));
		free(s);
	}
	return (i + 1);
}
