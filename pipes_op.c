/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:33:26 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/10 16:37:52 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	close_pipes(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->fd_infile > 2)
			close(cmd->fd_infile);
		if (cmd->fd_outfile > 2)
			close(cmd->fd_outfile);
		cmd = cmd->next;
	}
}

int	set_pipefd(t_cmd *cmd)
{
	int		pipefd[2];
	t_cmd	*cmd_init;

	cmd_init = cmd;
	while (cmd)
	{
		if (cmd->fd_infile == -2)
			cmd->fd_infile = 0;
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
			{
				close_pipes(cmd_init);
				return (1);
			}
			if (cmd->fd_outfile == -2)
				cmd->fd_outfile = pipefd[1];
			if (cmd->next->fd_infile == -2)
				cmd->fd_infile = pipefd[0];
		}
		if (!cmd->next && cmd->outfile == -2)
			cmd->outfile = 1;
		cmd = cmd->next;
	}
	return (0);
}
