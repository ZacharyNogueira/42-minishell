/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:35 by znogueir          #+#    #+#             */
/*   Updated: 2022/12/11 01:43:39 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_echo(char **cmd)
{
	int	i;

	i = 0;
	//ft_printf("my echo :\n");
	while (cmd[i])
	{
		ft_printf("%s", cmd[i]);
		if (cmd[i + 1])
			ft_printf(" ");
		i++;
	}
}

int	ft_echo(char **cmd, int newline)
{
	int	i;
	int	j;

	j = 1;
	if (!cmd[j])
		return (ft_printf("\n"), 0);
	while (cmd[j] && cmd[j][0] == '-')
	{
		i = 1;
		while (cmd[j][i] == 'n')
			i++;
		if (cmd[j][i])
			break ;
		else
			newline = 0;
		j++;
	}
	if (newline)
	{
		print_echo(cmd + j);
		return (ft_printf("\n"), 0);
	}
	return (print_echo(cmd + j), 0);
}
