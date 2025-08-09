NAME = libasm.a

CC = nasm
CFLAGS = -felf64 -g -F dwarf

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRCS =	ft_strlen.s				\
		ft_strcpy.s				\
		ft_strcmp.s				\
		ft_strdup.s				\
		ft_write.s				\
		ft_read.s

BONUS_SRCS =					\
		ft_atoi_base_bonus.s			\
		ft_list_size_bonus.s			\
		ft_list_push_front_bonus.s	\
		ft_list_sort_bonus.s			\
		ft_list_remove_if_bonus.s

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.s=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.s=.o))

ifdef WITH_BONUS
    OBJ = $(OBJS) $(BONUS_OBJS)
else
    OBJ = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR) :
	mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.s | $(OBJ_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

bonus :
	make WITH_BONUS=1 all

test: bonus
	@gcc test.c $(NAME) -o $@
	@valgrind ./test
	@rm -f $@

re: fclean all
