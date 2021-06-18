LIBFT	=	./libft

NAME	=	libftprintf.a

FLAGS	=	-Wall -Werror -Wextra

HEADER	=	includes/ft_printf.h

F	=	sources/

SRCS	=	ft_printf.c\
			$(F)ft_parse_flags.c	$(F)ft_type_dixXu.c\
			$(F)ft_type_pointer.c	$(F)ft_itoa_unsign.c\
			$(F)ft_transl_10to16.c	$(F)ft_type_sc_proc.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	 $(MAKE) -C $(LIBFT)/
	 cp $(LIBFT)/libft.a ./$(NAME)
	 ar rcs $(NAME) $?
.c.o:
	 gcc $(FLAGS) -c $< -o $@

clean:
	 $(MAKE) -C $(LIBFT)/ clean
	 rm -f $(OBJS)

fclean:	clean
	$(MAKE) -C $(LIBFT)/ fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
