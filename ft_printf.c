/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:25:13 by plopes-c          #+#    #+#             */
/*   Updated: 2022/12/01 19:24:39 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

int	checknprint(va_list args, int i, const char *str);

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;
	int			re;

	i = 0;
	re = 0;
	va_start(args, str);
	while (str[i] && str)
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			re++;
		}
		else
			re += checknprint(args, ++i, str);
		i++;
	}
	va_end(args);
	return (re);
}

int	checknprint(va_list args, int i, const char *str)
{
	unsigned long int	p;

	if (str[i] == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(args, unsigned), 1));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (str[i] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (str[i] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (str[i] == '%')
		return (ft_putchar_fd('%', 1));
	if (str[i] == 'x')
		return (ft_putnbr_hexa_fd(va_arg(args, unsigned int), 1, 0));
	if (str[i] == 'X')
		return (ft_putnbr_hexa_fd(va_arg(args, unsigned int), 1, 1));
	if (str[i] == 'p')
	{
		p = va_arg(args, unsigned long int);
		if (!p)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_putnbr_hexa_fd(p, 1, 0));
	}
	return (0);
}

// int	main(void)
// {
// 	ft_printf("%d\n", ft_printf("abcde\n"));
// 	return (0);
// }
