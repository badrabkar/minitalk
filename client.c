/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:24:04 by babkar            #+#    #+#             */
/*   Updated: 2021/12/24 04:15:04 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <string.h>

void	send_to_server(int pid, char *string)
{
	size_t	lenstring;
	int		j;
	size_t	i;

	i = 0;
	lenstring = ft_strlen(string);
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
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || argv[2][0] == '\0')
		exit(0);
	send_to_server(ft_atoi(argv[1]), argv[2]);
	return (0);
}
