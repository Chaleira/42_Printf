/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:45:09 by plopes-c          #+#    #+#             */
/*   Updated: 2022/12/02 00:01:53 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		checknprint(va_list args, int i, const char *str);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);

#endif
