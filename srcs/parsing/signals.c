/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:33:02 by znogueir          #+#    #+#             */
/*   Updated: 2022/12/15 18:42:58 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_in_fork(int sig)
{
	if (sig == SIGINT)
		g_exit = 130;
	else if (sig == SIGQUIT)
		g_exit = 131;
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit = 130;
	}
}

// HEREDOCS
// ft_printf("\nchild\n");
// fd = open("/dev/null", O_RDONLY);
// dup2(fd, 0);
// close(fd);
// write(0, "\0", 1);

// useless :
// void	signal_handler(void)
// {
// 	struct sigaction	s_sig;

// 	s_sig.sa_sigaction = handle_signals;
// 	s_sig.sa_flags = SA_SIGINFO;
// 	sigemptyset(&s_sig.sa_mask);
// 	sigaction(SIGINT, &s_sig, 0);
// 	sigaction(SIGQUIT, &s_sig, 0);
// }
