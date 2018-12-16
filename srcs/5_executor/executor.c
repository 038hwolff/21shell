
#include "shell.h"

static void		cmd_not_found(char *cmd)
{
	ft_printf("%s , 21sh: command not found");
	ft_printf("%s\n", cmd);
	exit_program("");
}

char			**get_path(char **env, char **arg)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	if ((!(path = NULL) && arg[0][0] != '/')
			&& !(ft_strnequ(arg[0], "./", 2)))
	{
		while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
			i++;
		if (!env[i] || !(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			if (!(path[i] = tristrjoin(path[i], "/", arg[0])))
				return (NULL);
			free(tmp);
		}
	}
	return (path ? path : ft_tabdup(&arg[0], 0));
}

int			ex_exec_core(char **env, char **table, char **paths)
{
	int		i;
	int		q;

	i = 0;
//	signal(SIGINT, SIG_DFL);
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			if ((q = execve(paths[i], table, env)) == -1)
				;
			break ;
		}
		i++;
	}
	cmd_not_found(*table);
	return (0);
}

int			exec_noast(char **env, char **table)
{
	int		status;
	char	**paths;
	int		childpid;

	if (!(paths = get_path(env, table)))
	{
		ft_putendl("Error: Path is empty");
		return (0);
	}
	childpid = fork();
	if (childpid == 0)
		ex_exec_core(env, table, paths);
	else
		signal(SIGINT, SIG_IGN);
	wait(&status);
	if (WIFSIGNALED(status))
		ft_putchar('\n');
		// signal(SIGINT, handle_signal);

	childpid = 0;
	return (1);
}

int				ex_exec(char **env, char **arg)
{
	int		i;

	if(SHPRINT)
	{
		i = 0;
		ft_printf("exec :");
		while (arg[i])
		{
			ft_printf(" %s", arg[i]);
			++i;
		}
		ft_printf("\n");
	}
	return (exec_noast(env, arg));
}
