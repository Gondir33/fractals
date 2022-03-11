/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:05:52 by marvin            #+#    #+#             */
/*   Updated: 2021/10/18 14:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_param
{
	va_list	arg;
	int		len;
}	t_param;

int		ft_printf(const char *format, ...);
int		ft_print(const char *format, t_param *param);
int		ft_len_hex(unsigned long long n);
char	ft_small_symbol(int n);
char	ft_big_symbol(int n);
char	*ft_itoa_address(unsigned long long n);
char	*ft_itoa_small_hex(unsigned int x);
char	*ft_itoa_big_hex(unsigned int x);
int		ft_uns_count(unsigned int n);
char	*ft_fill_uns_itoa(char *s, unsigned int n, int len);
char	*ft_itoa_uns(unsigned int n);
int		ft_count(int n, int *flag);
char	*ft_fillitoa(char *s, int n, int len);
char	*ft_itoa(int n);
int		ft_parsflag(const char *format, t_param *param, int i);
int		ft_strlen(char *s);
int		ft_printdig(t_param *param, int i);
int		ft_printchar(t_param *param, int i);
int		ft_printstr(t_param *param, int i);
int		ft_printaddress(t_param *param, int i);
int		ft_printuns(t_param *param, int i);
int		ft_printsmallhex(t_param *param, int i);
int		ft_printbighex(t_param *param, int i);

#endif