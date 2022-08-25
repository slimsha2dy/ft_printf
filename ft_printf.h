/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrusciante <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:50:35 by jfruscia          #+#    #+#             */
/*   Updated: 2022/08/26 02:22:19 by jfruscia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"

int		ft_printf_sub(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

int		ft_printf_type(const char c, va_list ap);

int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(int n);

int		ft_nbr_len(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf_unsigned(unsigned int n);

int		ft_hex_len(unsigned int n);
void	ft_rec_hex(unsigned int n, const char c);
int		ft_printf_hex(unsigned int n, const char c);

int		ft_ptr_len(unsigned long long n);
void	ft_rec_ptr(unsigned long long n);
int		ft_printf_ptr(unsigned long long ptr);

#endif
