/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:59:41 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/26 02:24:07 by jfruscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n)
{
	int	ret_len;

	ret_len = 0;
	while (n != 0)
	{
		ret_len++;
		n = n / 16;
	}
	return (ret_len);
}

void	ft_rec_hex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_rec_hex(n / 16, c);
		ft_rec_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			else if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printf_hex(unsigned int n, const char c)
{
	int	ret_len;

	ret_len = 0;
	if (n == 0)
		ret_len = write(1, "0", 1);
	else
	{
		ft_rec_hex(n, c);
		ret_len = (ft_hex_len(n));
	}
	return (ret_len);
}
