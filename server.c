#include "server.h"

void	my_putstr(char c)
{
	write(1, &c, 1);
}

void	sighandler(int signal, siginfo_t *check_pid, void *unused2)
{
	static int	count;
	static int	symbol;

	(void)unused2;
	if (signal == SIGUSR1)
		symbol += 1 << (7 - count);
	if (++count == 8)
	{
		if (symbol == 0)
		{
			kill(check_pid->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		else
		{
			my_putstr(symbol);
			symbol = 0;
		}
		count = 0;
	}
	usleep(10);
	kill(check_pid->si_pid, SIGUSR1);
}

int	main(int argc, const char *argv[])
{
	char				*pid;
	int					n_pid;
	struct sigaction	signals;

	if (argc != 1)
		return (write(1, "Error!\n", 7) - 8);
	(void)argv;
	n_pid = getpid();
	pid = ft_itoa(n_pid);
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signals.sa_flags = SA_SIGINFO;
	signals.sa_sigaction = sighandler;
	if (sigaction(SIGUSR1, &signals, 0) == -1)
		return (write(1, "Error!\n", 7) - 8);
	if (sigaction(SIGUSR2, &signals, 0) == -1)
		return (write(1, "Error!\n", 7) - 8);
	while (1)
		pause();
}
