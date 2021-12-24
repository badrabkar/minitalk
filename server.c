/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:34:06 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:05:49 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sighandler(int sum)
{
	static char	c;
	static int	count;

	if (sum == 31)
		sum = 0;
	if (sum == 30)
		sum = 1;
	c += (sum * ft_pow(2, count++));
	if (count == 8)
	{
		ft_putchar(c);
		if (!c)
			ft_putchar('\n');
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR2, sighandler);
	signal(SIGUSR1, sighandler);
	while (1)
		pause();
	return (0);
}
