#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>

typedef struct	s_cmd
{
	char			**cmd;
	char			*bin_path;
	int				fd_infile;
	int				fd_outfile;
	struct s_cmd	*next;
}	t_cmd;

typedef struct	s_data
{
	t_cmd	*cmd;
	char	**envp;
}	t_data;

int		set_pipefd(t_cmd *cmd);
void	close_pipes(t_cmd *cmd);
int		exec_cmd(t_data *data);

#endif
