/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:10:45 by adesgran          #+#    #+#             */
/*   Updated: 2022/05/10 17:50:50 by adesgran         ###   ########.fr       */
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
	return (res);
}

t_data	*initdata(char **envp)
{
	t_data	*res;
	char	**cmd1;
	char	**cmd2;

	res = malloc(sizeof(t_data));
	res->envp = envp;
	cmd1 = malloc(sizeof(char *) * 2);
	cmd1[1] = NULL;
	cmd1[0] = ft_strdup("cat");
	//res->cmd = initcmd(cmd1, "/bin/cat", open("infile", O_RDONLY), 1);
	res->cmd = initcmd(cmd1, "/bin/cat", 0, -2);
	cmd2 = malloc(sizeof(char *) * 3);
	cmd2[2] = NULL;
	cmd2[1] = ft_strdup("-c");
	cmd2[0] = ft_strdup("wc");
	res->cmd->next = initcmd(cmd2, "/bin/wc", -2, 1);
	
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
