#include "shell.h"

void	expansion(t_data *data, t_token *tkn)
{
	exp_tilde(&tkn->val, data);
	exp_vars(&tkn->val, data);
}
