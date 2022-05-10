/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:29:46 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/10 17:51:18 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex(t_data *data)
{
	int		status;
	size_t	i;
	t_cmd	*cmd;

	i = 0;
	cmd = data->cmd;
	set_pipefd(cmd);
	while (cmd)
	{
		i++;
		exec_cmd(data, cmd);
		cmd = cmd->next;
	}
	status = 0;
	while (--i)
		wait(&status);
}
