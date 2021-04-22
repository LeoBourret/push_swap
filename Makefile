PUSH_SWAP = push_swap
CHECKER = checker
CC = clang
CFLAGS = -Wall -Werror -Wextra

CHECKER_FOLDER = ./checker_srcs/
PUSH_SWAP_FOLDER = ./push_swap_srcs/

C_SRCS = $(CHECKER_FOLDER)main.c $(CHECKER_FOLDER)exec.c \
		$(CHECKER_FOLDER)exit.c $(CHECKER_FOLDER)get_next_line.c \
		$(CHECKER_FOLDER)orders.c $(CHECKER_FOLDER)utils.c \
		$(CHECKER_FOLDER)utils_2.c
P_SRCS = $(PUSH_SWAP_FOLDER)exit.c  $(PUSH_SWAP_FOLDER)main.c \
			$(PUSH_SWAP_FOLDER)orders.c $(PUSH_SWAP_FOLDER)solve_five.c \
			$(PUSH_SWAP_FOLDER)solve_ten.c $(PUSH_SWAP_FOLDER)solve_three.c \
			$(PUSH_SWAP_FOLDER)solve_hundred.c $(PUSH_SWAP_FOLDER)utils.c \
			$(PUSH_SWAP_FOLDER)utils_2.c $(PUSH_SWAP_FOLDER)utils_3.c \
			$(PUSH_SWAP_FOLDER)utils_4.c $(PUSH_SWAP_FOLDER)options.c
C_OBJS = $(C_SRCS:.c=.o)
P_OBJS = $(P_SRCS:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

libft:
		make -C libft
		mv ./libft/libft.a .

$(CHECKER): libft $(C_OBJS)
		$(CC) -o $(CHECKER) $(C_OBJS) -L. -lft

$(PUSH_SWAP): libft $(P_OBJS)
		$(CC) -o $(PUSH_SWAP) $(P_OBJS) -L. -lft

clean:
		rm -f $(C_OBJS) $(P_OBJS)
fclean: clean
		rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: checker push_swap
