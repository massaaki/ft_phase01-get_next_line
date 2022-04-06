all: 
		cc -c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=4
		cc get_next_line.o get_next_line_utils.o main.c -g
		./a.out
		# cc -Wall -Werror -Wextra -c get_next_line.c -o get_next_line.o

bonus:
		cc get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=4 \
		main_bonus.c -g
		./a.out
		@rm -rf a.out

clean:
		rm -rf get_next_line.o get_next_line_utils.o

fclean: clean
		rm -rf a.out

norminette:
		norminette get_next_line.h get_next_line_utils.c get_next_line.c
