#include "get_next_line_bonus.h"

static size_t	ft_strlen_before_nl(char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			break ;
		length++;
		str++;
	}
	return (length);
}

static int	ft_fill_line(char **memory_str, char **line)
{
	char	*temp_str;
	size_t	length_nl;

	temp_str = ft_strchr(*memory_str, '\n');
	if (temp_str != NULL)
	{
		length_nl = ft_strlen_before_nl(*memory_str);
		*line = ft_substr(*memory_str, 0, length_nl);
		temp_str = ft_strdup(*memory_str + length_nl + 1);
		free(*memory_str);
		*memory_str = temp_str;
		if (**memory_str == '\0')
		{
			free(*memory_str);
			*memory_str = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*memory_str);
		free(*memory_str);
		*memory_str = NULL;
		return (0);
	}
	return (1);
}

static int	ft_return_value(char **memory_str, char **line, int read_count)
{
	if (read_count < 0)
		return (-1);
	else if (read_count == 0 && !*memory_str)
		return (0);
	return (ft_fill_line(memory_str, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*heap[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp_string;
	int			read_count;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1
		|| !line || read(fd, 0, 0) < 0)
		return (-1);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		buffer[read_count] = '\0';
		if (!heap[fd])
			heap[fd] = ft_strdup(buffer);
		else
		{
			temp_string = ft_strjoin(heap[fd], buffer);
			free(heap[fd]);
			heap[fd] = temp_string;
		}
		if (ft_strchr(heap[fd], '\n') != 0)
			break ;
	}
	return (ft_return_value(&heap[fd], line, read_count));
}
