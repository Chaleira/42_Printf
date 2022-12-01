/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:08:37 by plopes-c          #+#    #+#             */
/*   Updated: 2022/12/01 18:47:02 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa_fd(unsigned long int n, int fd, int low0_up1)
{
	int		i;
	char	*str;

	i = 0;
	if (!low0_up1)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n >= 16)
		i = ft_putnbr_hexa_fd(n / 16, fd, low0_up1);
	return (i + ft_putchar_fd(str[n % 16], fd));
}
