/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:27:45 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:05:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		sign *= (-1);
	if (*str == 45 || *str == 43)
		str++;
	if (*str < '0' && *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - 48);
	return (num * sign);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}

int	ft_pow(int n, int j)
{
	int	i;

	if (j == 1)
		return (n);
	if (j == 0)
		return (1);
	i = n;
	while (j-- > 1)
		n = n * i;
	return (n);
}
