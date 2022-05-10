/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:43:38 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/10 17:42:20 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	exec_cmd(t_data *data, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror("Fork"), 1);
	if (!pid)
	{
		dup2(cmd->fd_infile, STDIN_FILENO); 
		if (cmd->fd_infile > 2)
			close(cmd->fd_infile);
		dup2(cmd->fd_outfile, STDOUT_FILENO); 
		if (cmd->fd_outfile > 2)
			close(cmd->fd_outfile);
		execve(cmd->bin_path, cmd->cmd, data->envp);
	}
	return (pid);
}

