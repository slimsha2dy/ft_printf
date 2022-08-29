/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:47:18 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/29 15:57:30 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(const char c, va_list ap)
{
	int			ret_len;

	ret_len = 0;
	if (c == 'c')
		ret_len += ft_printf_char(va_arg(ap, int));
	else if (c == 's')
		ret_len += ft_printf_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ret_len += ft_printf_nbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		ret_len += ft_printf_hex(va_arg(ap, unsigned int), c);
	else if (c == 'u')
		ret_len += ft_printf_unsigned(va_arg(ap, unsigned int));
	else if (c == 'p')
		ret_len += ft_printf_ptr(va_arg(ap, unsigned long long));
	else if (c == '%')
		ret_len += ft_printf_per();
	return (ret_len);
}

int	ft_printf_sub(const char *format, va_list ap)
{
	int	ret_len;
	int	i;

	i = 0;
	ret_len = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret_len += write(1, &format[i++], 1);
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr(TYPE, format[i]))
				ret_len += ft_printf_type(format[i++], ap);
			else
				ret_len = -1;
		}
	}
	return (ret_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_len;

	va_start(ap, format);
	ret_len = ft_printf_sub(format, ap);
	va_end(ap);
	return (ret_len);
}
