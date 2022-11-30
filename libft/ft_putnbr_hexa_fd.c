/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:08:37 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/30 00:09:19 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hexa_fd(unsigned long int n, int fd, int low0_up1)
{
	long	i;
	char	*str;

	if (!low0_up1)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	i = n;
	if (i >= 16)
		ft_putnbr_hexa_fd(i / 16, fd, low0_up1);
	ft_putchar_fd(str[i % 16], fd);
}
