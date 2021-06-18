NAME = client server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(NAME)

$(NAME): ft_atoi.o ft_itoa.o ft_strlen.o ft_strdup.o client.o server.o
	gcc $(CFLAGS) ft_strlen.o ft_itoa.o server.o -o server && gcc $(CFLAGS) ft_atoi.o ft_strdup.o ft_strlen.o client.o -o client;

ft_atoi.o: ft_atoi.c
	$(CC) $(CFLAGS) -c ft_atoi.c

ft_itoa.o: ft_itoa.c
	$(CC) $(CFLAGS) -c ft_itoa.c

ft_strdup.o: ft_strdup.c
	$(CC) $(CFLAGS) -c ft_strdup.c

ft_strlen.o: ft_strlen.c
	$(CC) $(CFLAGS) -c ft_strlen.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

clean:
	$(RM) ft_strlen.o ft_itoa.o server.o ft_atoi.o ft_strdup.o client.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re

