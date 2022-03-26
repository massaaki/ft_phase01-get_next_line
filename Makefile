all: 
		cc -c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
		cc get_next_line.o get_next_line_utils.o main.c 
		./a.out
		# cc -Wall -Werror -Wextra -c get_next_line.c -o get_next_line.o

clean:
		rm -rf get_next_line.o get_next_line_utils.o

fclean: clean
		rm -rf a.out
