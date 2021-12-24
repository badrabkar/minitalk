/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:01:08 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:06:21 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	sighandler_bonus(int sum, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	context = NULL;
	if (sum == 31)
		sum = 0;
	if (sum == 30)
		sum = 1;
	c += (sum * ft_pow_bonus(2, count++));
	if (count == 8)
	{
		ft_putchar_bonus(c);
		if (c == '\0')
		{
			ft_putchar_bonus('\n');
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_bonus(getpid());
	ft_putchar_bonus('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler_bonus;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
