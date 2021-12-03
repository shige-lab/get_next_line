NAME = get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = get_next_line.h
BHEADER = get_next_line_bonus.h
SRCS = get_next_line.c get_next_line_utils.c main.c
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(OBJS)
	./$(NAME)
bonus: $(BOBJS)
	$(CC) $(CFLAGS) -I $(BHEADER) -o $(NAME) $(BOBJS)
	./$(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 