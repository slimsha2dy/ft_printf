/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:50:50 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/26 03:06:31 by jfruscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	int		ret_len;
	char	chr;

	ret_len = 0;
	chr = (char)c;
	ret_len += write(1, &chr, 1);
	return (ret_len);
}

int	ft_printf_str(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_printf_nbr(int n)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	nbr_str = ft_itoa(n);
	ret_len = ft_printf_str(nbr_str);
	free(nbr_str);
	return (ret_len);
}

int	ft_printf_per(void)
{
	write(1, "%", 1);
	return (1);
}
