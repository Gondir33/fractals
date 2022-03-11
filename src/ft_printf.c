/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:56:11 by marvin            #+#    #+#             */
/*   Updated: 2021/10/18 18:56:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_param	*param;
	int		len;

	param = malloc(sizeof(t_param));
	if (!param)
		return (-1);
	param->len = 0;
	va_start(param->arg, format);
	len = ft_print(format, param);
	va_end(param->arg);
	free(param);
	return (len);
}

int	ft_print(const char *format, t_param *param)
{
	int	i;
	int	totallen;

	i = 0;
	totallen = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_parsflag(format, param, i + 1);
		else
		{
			totallen += write(1, &format[i], 1);
			i++;
		}
		if (i == -1)
			return (-1);
	}
		return (param->len + totallen);
}
