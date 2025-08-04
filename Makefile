NAME = libasm.a

CC = nasm
CFLAGS = -felf64 -g -F dwarf

SRCS = ft_strlen.s	\
	  ft_strcpy.s	\
	  ft_strcmp.s	\
	  ft_strdup.s	\
	  ft_write.s	\
	  ft_read.s		\
	  ft_atoi_base.s	\
	  ft_list_size.s	\
	  ft_list_push_front.s

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.s=.o))

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR) :
	mkdir -p $@

$(OBJ_DIR)%.o : %.s | $(OBJ_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
