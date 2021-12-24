/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:21:16 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:07:19 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen_bonus(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_bonus(char c)
{
	write(1, &c, 1);
}

int	ft_atoi_bonus(const char *str)
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

void	ft_putnbr_bonus(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar_bonus(n + 48);
	if (n >= 10)
	{
		ft_putnbr_bonus(n / 10);
		ft_putnbr_bonus(n % 10);
	}
}

int	ft_pow_bonus(int n, int j)
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
