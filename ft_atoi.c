#include "client.h"

int	ft_atoi_dop(const char *str, int count)
{
	while ((str[count] == ' ') || (str[count] == '\n') || (str[count] == '\r') \
		|| (str[count] == '\t') || (str[count] == '\v') || (str[count] == '\f'))
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	checkMinus;
	int	count;

	result = 0;
	checkMinus = 0;
	count = ft_atoi_dop(str, 0);
	if (str[count] == '-')
	{
		checkMinus++;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while ((str[count] >= '0' && str[count] <= '9') && str[count] != 0)
	{
		result = (result * 10) + (str[count] - 48);
		count++;
	}
	if (checkMinus == 1)
		return (-result);
	return (result);
}
