/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:10:45 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/10 17:16:59 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

t_cmd	*initcmd(char **cmd, char *bin_path, int fd_inf, int fd_outf)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	if (!res)
		return (NULL);
	res->cmd = cmd;
	res->bin_path = bin_path;
	res->fd_infile = fd_inf;
	res->fd_outfile = fd_outf;
	res->next = NULL;
}

t_data	*initdata(char **envp)
{
	t_data	*res;
	t_cmd	*cmd;
	char	cmd1[2][20];

	res = malloc(sizeof(t_data));
	res->envp = envp;
	cmd1[1] = NULL;
	cmd1[0] = NULL;
	res->cmd = initcmd(cmd1, "/bin/cat", 0, 1);
	
	return (res);
}


int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac == 1)
	{
		printf("Need Arguments\n");
		exit(EXIT_FAILURE);
	}
	data = initdata(envp);
	if (data->cmd)
		pipex(data);
	else
		printf("Error, no cmd in data\n");


	(void)ac;
	(void)av;
	return (0);
}
