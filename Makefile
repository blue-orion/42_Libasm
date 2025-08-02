NAME=libasm.a

# COMPILE
all:
	nasm -felf64 ft_strcmp.s
	nasm -felf64 ft_strlen.s
	nasm -felf64 ft_strcpy.s
	gcc main.c ft_strcmp.o ft_strlen.o ft_strcpy.o -o test

