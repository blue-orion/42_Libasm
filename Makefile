NAME = libasm.a

CC = nasm
CFLAGS = -felf64 -g -F dwarf

SRCS =	ft_strlen.s				\
		ft_strcpy.s				\
		ft_strcmp.s				\
		ft_strdup.s				\
		ft_write.s				\
		ft_read.s

BONUS_SRCS =					\
		ft_atoi_base.s			\
		ft_list_size.s			\
		ft_list_push_front.s	\
		ft_list_sort.s			\
		ft_list_remove_if.s

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.s=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.s=.o))

ifdef WITH_BONUS
    OBJ = $(OBJS) $(BONUS_OBJS)
else
    OBJ = $(OBJS)
endif

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR) :
	mkdir -p $@

$(OBJ_DIR)%.o : %.s | $(OBJ_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

bonus :
	make WITH_BONUS=1 all

test: bonus
	@gcc test.c $(NAME) -o $@
	@./test
	@rm -f $@

re: fclean all
