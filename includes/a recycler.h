/*
**************************************************************************
************************************* CORE *******************************
**************************************************************************
** shell.c
*/

int					minishell(int argc, char **argv, char **envp);
void				display_prompt(void);
int					ft_enter(char *line, t_var *var);

/*
** loop.c
*/

void				loop(void);

/*
** setup.c
*/

void				setup_env(int ac, char **av, t_env *envp);
t_var				*setup_var(t_var *var);
int					len_line(t_var *var);

/*
** shell.c
*/

void				handle_signal(int signal);
char				**get_path(t_data *data);
char				**split_for_display(char *entry);
int					global_parse(t_data *data);
int					minishell(int ac, char **av, char **env);

/*
** read.c
*/

int					read_entry(t_data *data);

/*
** parse.c
*/

int					is_valid_entry(t_data *data, int z, int tot);
/*
** error.c
*/

void				trial(int i);
void				cmd_not_found(t_data *data);

/*
** free.c
*/

void				free_tab(char ***table);
void				free_tab_content(char ***table);

/*
** get_executable.c
*/

int					ex_exec_core(t_data *data, char **paths);
int					ex_exec(t_data *data);