/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:55:22 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/26 01:57:42 by jfruscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(unsigned int n)
{
	int	ret_len;

	ret_len = 0;
	while (n != 0)
	{
		ret_len++;
		n /= 10;
	}
	return (ret_len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr_str;
	int		len;

	len = ft_nbr_len(n);
	nbr_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr_str)
		return (0);
	nbr_str[len] = '\0';
	while (n != 0)
	{
		nbr_str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nbr_str);
}

int	ft_printf_unsigned(unsigned int n)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	if (n == 0)
		ret_len += write(1, "0", 1);
	else
	{
		nbr_str = ft_uitoa(n);
		ret_len += ft_printf_str(nbr_str);
		free(nbr_str);
	}
	return (ret_len);
}
