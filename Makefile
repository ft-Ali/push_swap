NAME		=	push_swap

BONUS		= 	checker

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	.libft

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

C_FILE		=	srcs/check_arg.c srcs/main.c srcs/fill_stack.c srcs/check_arg_utils.c commands/push.c commands/swap.c commands/rotate.c \
				commands/reverse_rotate.c srcs/sort_utils.c srcs/stack_utils.c srcs/sort.c srcs/a_to_b.c  srcs/b_to_a.c 

BONUS_SRC = 	srcs/check_arg.c srcs/fill_stack.c srcs/check_arg_utils.c commands/push.c commands/swap.c commands/rotate.c \
				commands/reverse_rotate.c srcs/sort_utils.c srcs/stack_utils.c srcs/sort.c srcs/a_to_b.c  srcs/b_to_a.c bonus/checker.c 


OBJS		=	$(C_FILE:.c=.o)
OBJS_2		=	$(BONUS_SRC:.c=.o)

.c.o:
	@printf "\r\033[K[push_swap] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

bonus: $(BONUS)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@printf "\r\033[K[push_swap] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS) $(LIBFT_LIB) -o $(NAME) -lm 
	@printf "\r\033[K[push_swap] \033[0;32mDone!\033[0m\n"

$(BONUS): $(LIBFT_LIB) $(OBJS_2)
	@printf "\r\033[K[checker] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS_2) $(LIBFT_LIB) -o $(BONUS) -lm
	@printf "\r\033[K[checker] \033[0;32mDone!\033[0m\n"


clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS) $(OBJS_2)
	@printf "[push_swap] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_PATH)
	@printf "[push_swap] \033[1;31mCleaned all!\033[0m\n"
	@printf "[checker] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re