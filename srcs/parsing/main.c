/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:10:24 by znogueir          #+#    #+#             */
/*   Updated: 2022/12/15 23:24:10 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_prompt(void)
{
	ft_printf(PROMPT);
}

void	write_error(char *error_msg)
{
	write(2, ERR_PRE, ft_strlen(ERR_PRE));
	write(2, error_msg, ft_strlen(error_msg));
}

int	ft_check_exit(char *line)
{
	if (!ft_strncmp(line, "exit", 4))
	{
		if (line[4] > 32)
			return (1);
		else
		{
			write(1, "bye! 👋\n", 11);
			return (0);
		}
	}
	return (1);
}

t_data	*ft_init(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->quote = 0;
	data->line = NULL;
	data->loc_env = NULL;
	data->cmd = NULL;
	data->cmdtable = NULL;
	data->filelist = NULL;
	data->char_env = NULL;
	set_env(env, data);
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_data		*data;

	(void)ac;
	(void)av;
	data = ft_init(env);
	signal_handler();
	while (1)
	{
		//data->line = readline("minishell$ ");
		//add_history(data->line);
		printf("data->line: %s\n", data->line);
		if (!data->line || check_errors(data->line))
			ft_exit_fork(data, NULL, 0);
		ft_lexer(data);
		if (!ft_parser(data))
		{
			ft_expander(data);
			ft_executor(data, env);
		}
		reset_cmd(data);
		free(data->line);
	}
	free_all(data);
	return (0);
}
