PUSH_SWAP = push_swap
CHECKER = checker
CC = clang
CFLAGS = -Wall -Werror -Wextra
MAKEFLAGS += --no-print-directory
RED="\033[1;31m"
GRN="\033[1;32m"
YLW="\033[1;33m"
END="\033[0m"

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
			$(PUSH_SWAP_FOLDER)utils_4.c
C_OBJS = $(C_SRCS:.c=.o)
P_OBJS = $(P_SRCS:.c=.o)

all: lib $(PUSH_SWAP)

bonus: $(PUSH_SWAP) $(CHECKER)

lib:
		@echo $(YLW)"[Libft compilation...]"
		@make -C libft/
		@echo $(GRN)"[Libft ready !]"
		@echo $(END)

$(CHECKER): $(C_OBJS)
		@echo $(YLW)"[Checker compilation...]"
		@$(CC) $(C_OBJS) -I libft/ -lft -L libft/ -o $(CHECKER)
		@echo $(GRN)"[Checker ready !]"
		@echo $(END)

$(PUSH_SWAP):  $(P_OBJS)
		@echo $(YLW)"[Push_swap compilation...]"
		@$(CC) $(P_OBJS) -I libft/ -lft -L libft/ -o $(PUSH_SWAP)
		@echo $(GRN)"[push_swap ready !]"
		@echo $(END)

clean:
		@echo $(RED)"[Cleaning PUSH_SWAP and CHECKER objects !]"
		@echo $(END)
		@rm -f $(C_OBJS) $(P_OBJS)

fclean: clean
		@echo $(RED)"[Cleaning PUSH_SWAP and CHECKER binary !]"
		@echo $(END)
		@rm -f $(CHECKER) $(PUSH_SWAP)

cleanlib:
		@echo $(RED)"[Cleaning Libft !]"
		@echo $(END)
		@make fclean -C libft/

re: fclean all

.PHONY: checker push_swap
.SILENT:
