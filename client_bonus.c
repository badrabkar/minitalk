/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:59:36 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:14:27 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	sig1handler(int sum);

void	send_to_server_bonus(int pid, char *string)
{
	size_t	lenstring;
	int		j;
	size_t	i;

	i = 0;
	lenstring = ft_strlen_bonus(string);
	while (i <= lenstring)
	{
		j = 0;
		while (j < 8)
		{
			if (((string[i] >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(1000);
		}
		i++;
		signal(SIGUSR1, sig1handler);
	}
}

void	sig1handler(int sum)
{
	if (sum == SIGUSR1)
		write(1, "The signal is received\n", 24);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || argv[2][0] == '\0')
		exit(0);
	send_to_server_bonus(ft_atoi_bonus(argv[1]), argv[2]);
	return (0);
}
