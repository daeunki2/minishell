/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:21:37 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 19:13:14 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_exit_stat = 0;

int	terminate_minishell(void)
{
	clear_env();
	rl_clear_history();
	write(1, "exit\n", 5);
	return (0);
}

void	do_do_the_job(t_token **tokens, t_job **jobs)
{
	t_token	**tmp;

	tmp = get_token_address();
	*tmp = parse_tokens(tokens, free);
	expansion(get_token_address());
	open_file_redir(get_token_address());
	*jobs = extract_jobs(*get_token_address());
	clear_tokens(get_token_address(), free);
	sigaction_set_parent();
	execute_jobs(*jobs);
	clear_jobs(*jobs);
}

t_token	**get_token_address(void)
{
	static t_token	*addr;

	return (&addr);
}

void	do_the_job(t_token *tokens, char *line, t_job *jobs)
{
	tokens = create_tokens(line);
	if (check_tokens(tokens) != 0)
		clear_tokens(&tokens, free);
	else
		do_do_the_job(&tokens, &jobs);
}

int	main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	t_job	*jobs;
	char	*line;
	char	*prompt;

	g_exit_stat = 0;
	init_env_var(envp);
	print_welcome();
	tokens = 0;
	jobs = 0;
	while (argc || argv)
	{
		if (!sigaction_set_prompt())
			write(2, "Error: sigaction_set_failed\n", 28);
		prompt = prompt_line();
		line = readline(prompt);
		free(prompt);
		if (line == NULL)
			return (terminate_minishell());
		if (ft_strlen(line) == 0)
			continue ;
		add_history(line);
		do_the_job(tokens, line, jobs);
	}
	return (0);
}
