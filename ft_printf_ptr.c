/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:53:14 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/26 01:55:12 by jfruscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long n)
{
	int	ret_len;

	ret_len = 0;
	while (n != 0)
	{
		ret_len++;
		n /= 16;
	}
	return (ret_len);
}

void	ft_rec_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_rec_ptr(n / 16);
		ft_rec_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	ret_len;

	ret_len = 0;
	ret_len += write(1, "0x", 2);
	if (ptr == 0)
		ret_len += write(1, "0", 1);
	else
	{
		ft_rec_ptr(ptr);
		ret_len += ft_ptr_len(ptr);
	}
	return (ret_len);
}
