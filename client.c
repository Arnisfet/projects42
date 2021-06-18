#include "client.h"

int		g_wait_cont;

void	signal_checker(int signal)
{
	if (signal == SIGUSR1)
		g_wait_cont = 0;
	else
		exit(write(1, "Sent successfully.\n", 19) - 19);
}

char	*double_system(int n)
{
	char	*bin;
	int		count;

	bin = ft_strdup("00000000");
	count = 7;
	while (n)
	{
		bin[count--] = (n % 2) + 48;
		n /= 2;
	}
	return (bin);
}

void	client(char *str, int pid)
{
	int	count;

	count = 0;
	while (str[count])
	{	
		g_wait_cont = 1;
		usleep(10);
		if (str[count++] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(write(1, "Error!\n", 7) - 8);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(write(1, "Error!\n", 7) - 8);
		}
		while (g_wait_cont)
			;
	}
	free(str);
}

int	main(int argc, char const *argv[])
{
	int		pid;

	if (argc != 3)
		return (write(1, "./client [PID_SERVER] [STRING_TO_PASS]\n", 39) - 40);
	signal(SIGUSR2, signal_checker);
	signal(SIGUSR1, signal_checker);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		client(double_system(*argv[2]++), pid);
	client(double_system(*argv[2]), pid);
	return (0);
}
