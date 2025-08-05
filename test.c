#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"
#define PRINT_HEADER(title) printf(GREEN "==================== %s ====================\n\n" RESET, title)

t_list	*new_node(void *data);
int		compare(void *a, void* b);
void	free_data(void *data);
void	print_list(t_list *head);

int main(void) {
	char	*msg = "hello";
	char	*empty = "";
	char	*very_long = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	PRINT_HEADER("ft_strlen test");
	printf("text: 'hello' | strlen = %ld\n", ft_strlen(msg));
	printf("empty text len = %ld\n", ft_strlen(empty));
	printf("426 len string = %ld\n\n", ft_strlen(very_long));

	PRINT_HEADER("ft_strcpy test");
	char dst[500];
	ft_strcpy(dst, msg);
	printf("COPY of 'hello': %s\n", ft_strcpy(dst, msg));
	printf("COPY of empty: %s\n", ft_strcpy(dst, empty));
	printf("SOURCE of very_long: %s\n", very_long);
	printf("COPY of very_long  : %s\n\n", ft_strcpy(dst, very_long));

	PRINT_HEADER("ft_strcmp test");
	printf("compare empty, empty result   = %d\n", ft_strcmp(empty, empty));
	printf("compare empty, 'hello' result = %d\n", ft_strcmp(empty, msg));
	printf("compare 'hello', empty result = %d\n", ft_strcmp(msg, empty));
	printf("compare 'hello', 426 * a      = %d\n\n", ft_strcmp(msg, very_long));

	int		fd = open("./libasm.h", O_RDONLY);
	char	buf[4096];
	int		read_byte;

	PRINT_HEADER("ft_read test");
	printf("read error test(read from fd -1)\n");
	read_byte = ft_read(-1, buf, 4096);
	if (read_byte == -1) {
		perror("read error");
		printf("\n");
	}
	write(1, "read test from stdin: ", 22);
	read_byte = ft_read(1, buf, 4096);
	printf("read_byte = %d\n\n", read_byte);
	buf[read_byte] = '\0';
	write(1, "read test from libasm.h: ", 25);
	read_byte = ft_read(fd, buf, 4096);
	printf("read_byte = %d\n\n", read_byte);
	buf[read_byte] = '\0';
	close(fd);

	fd = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	PRINT_HEADER("ft_write test");
	printf("Result of read libasm.h\n\n");
	ft_write(1, buf, ft_strlen(buf));
	printf("\n");
	printf("Writing libasm.h to header.text...\n\n");
	ft_write(fd, buf, ft_strlen(buf));
	printf("write error test(write to fd -1)\n");
	if (ft_write(-1, buf, ft_strlen(buf)) == -1)
		perror("write error");
	write(1, "\n", 1);

	PRINT_HEADER("ft_strdup test");
	char	*dup_buffer = ft_strdup(msg);
	printf("Base  : %s\n", msg);
	printf("Result: %s\n\n", dup_buffer);
	free(dup_buffer);
	dup_buffer = ft_strdup(empty);
	printf("Base  : %s\n", empty);
	printf("Result: %s\n\n", dup_buffer);
	free(dup_buffer);
	dup_buffer = ft_strdup(very_long);
	printf("Base  : %s\n", very_long);
	printf("Result: %s\n\n", dup_buffer);
	free(dup_buffer);

	PRINT_HEADER("ft_atoi_base test");
	printf("'42', 10진수 => %d\n", ft_atoi_base("42", "0123456789"));
	printf("'42', 16진수 => %d\n", ft_atoi_base("   42", "0123456789abcdef"));
	printf("'1101', 2진수 => %d\n", ft_atoi_base("1101", "01"));
	printf("error => %d\n\n", ft_atoi_base("1101", "alsdjfoliasdjfviocashdukivlhausdkiofhalksdufhasdkfjklasdhfuioasdhfkjlashdfukiahsdkljhflaukids"));

	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	int *c = malloc(sizeof(int));
	int *d = malloc(sizeof(int));
	*a = 42;
	*b = 21;
	*c = 42;
	*d = 100;

	t_list *head = new_node(d);
	ft_list_push_front(&head, c);
	ft_list_push_front(&head, b);

	PRINT_HEADER("ft_list_size test");
	size_t size = ft_list_size(head);
	printf("List size: %zu, expected: %d\n\n", size, 3);

	PRINT_HEADER("ft_list_push_front test");
	ft_list_push_front(&head, a);
	print_list(head);
	size = ft_list_size(head);
	printf("List size: %zu, expected: %d\n\n", size, 4);

	PRINT_HEADER("ft_list_sort test");
	ft_list_sort(head, compare);
	print_list(head);
	printf("\n");

	PRINT_HEADER("ft_list_remove_if test");
	int target = 42;
	ft_list_remove_if(&head, &target, compare, free_data);
	printf("After remove:\n");
	print_list(head);
	printf("\n");

	while (head)
	{
		t_list	*tmp = head->next;
		free(head->data);
		free(head);
		head = tmp;
	}
	return 0;
}

t_list	*new_node(void *data)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

int		compare(void *a, void* b) {
	int	aa = *(int *)a;
	int	bb = *(int *)b;

	return aa - bb;
}

void free_data(void *data)
{
	printf("freeing data: %d\n", *(int *)data);
	free(data);
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%d -> ", *(int *)head->data);
		head = head->next;
	}
	printf("NULL\n");
}
