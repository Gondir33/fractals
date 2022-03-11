/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:44:22 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 00:44:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parsflag(const char *format, t_param *param, int i)
{
	if (format[i] == '%')
	{
		param->len += write(1, "%", 1);
		return (i + 1);
	}
	else if (format[i] == 'c')
		return (ft_printchar(param, i));
	else if (format[i] == 's')
		return (ft_printstr(param, i));
	else if (format[i] == 'p')
		return (ft_printaddress(param, i));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_printdig(param, i));
	else if (format[i] == 'u')
		return (ft_printuns(param, i));
	else if (format[i] == 'x')
		return (ft_printsmallhex(param, i));
	else if (format[i] == 'X')
		return (ft_printbighex(param, i));
	else
		return (-1);
}
