NAME=trans

all:
	gcc -g *.c -o trans -I libft libft/libft.a

gdb:
	gdb --args ./trans testfile.pas testfile.pas
