# include "../../includes/shell.h"

void	signal_handler(void(*restart)(int))
{
//	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart);
/*	signal(SIGTSTP, unsetup_term);
	signal(SIGINT, b_exit(data));
	signal(SIGHUP, b_exit(data));
	signal(SIGTERM, b_exit(data));
	signal(SIGSEGV, b_exit(data));
	signal(SIGQUIT, b_exit(data));
	signal(SIGFPE, b_exit(data));
	signal(SIGKILL, b_exit(data));
	signal(SIGALRM, b_exit(data));
	signal(SIGABRT, b_exit(data));
	signal(SIGUSR1, b_exit(data));
	signal(SIGUSR2, b_exit(data));*/
}
