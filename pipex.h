#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

typedef struct	s_cmd
{
	char			**cmd;
	char			*bin_path;
	int				fd_infile;
	int				fd_outfile;
	struct s_cmd	*next;
}	t_cmd;

#endif
