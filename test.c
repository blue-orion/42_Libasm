#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libasm.h"

t_list	*new_node(void *data);
int		compare(void *a, void* b);
void	free_data(void *data);
void	print_list(t_list *head);

int main(void) {
	char *msg = "Hello";

	printf("===== ft_strlen test =====\n");
	printf("'hello'.length = %ld\n\n", ft_strlen(msg));

	printf("===== ft_strcpy test =====\n");
	char dst[6];
	ft_strcpy(dst, msg);
	printf("COPY of 'hello': %s\n\n", dst);

	printf("===== ft_strcmp test =====\n");
	printf("compare 'hello', 'hello': %d\n\n", ft_strcmp(dst, msg));

	char	buf[4096];
	int	read_byte;
	printf("===== ft_read test =====\n");
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

	printf("===== ft_write test =====\n");
	ft_write(1, buf, ft_strlen(buf));
	printf("\n");
	printf("write error test(write to fd -1)\n");
	if (ft_write(-1, buf, ft_strlen(buf)) == -1)
		perror("write error");
	write(1, "\n", 1);

	printf("===== ft_strdup test =====\n");
	char	*dup_buffer = ft_strdup(buf);
	printf("Base String: %s", buf);
	printf("Result: %s\n", dup_buffer);
	free(dup_buffer);

	printf("===== ft_atoi_base test =====\n");
	printf("'42', 10진수 => %d\n", ft_atoi_base("42", "0123456789"));
	printf("'42', 16진수 => %d\n", ft_atoi_base("   42", "0123456789abcdef"));
	printf("'1101', 2진수 => %d\n\n", ft_atoi_base("1101", "01"));

	printf("!==== ft_list function test ====!\n\n");
	// 값 할당
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	int *c = malloc(sizeof(int));
	int *d = malloc(sizeof(int));
	*a = 42;
	*b = 21;
	*c = 42;
	*d = 100;

	// 리스트 생성: d -> c -> b -> a
	t_list *head = new_node(d);
	ft_list_push_front(&head, c);
	ft_list_push_front(&head, b);

	printf("===== ft_list_size test =====\n");
	size_t size = ft_list_size(head);
	printf("List size: %zu, expected: %d\n\n", size, 3);  // 기대값: 3
	
	printf("===== ft_list_push_front test =====\n");
	ft_list_push_front(&head, a);
	print_list(head);
	size = ft_list_size(head);
	printf("List size: %zu, expected: %d\n\n", size, 4);  // 기대값: 4

	printf("===== ft_list_sort test =====\n");
	ft_list_sort(head, compare);
	print_list(head);
	printf("\n");

	printf("===== ft_list_remove_if test =====\n");
	// 삭제 기준 값
	int target = 42;
	ft_list_remove_if(&head, &target, compare, free_data);

	// 삭제 후 출력
	printf("After remove:\n");
	print_list(head);

	// 남은 노드 정리
	while (head)
	{
		t_list	*tmp = head->next;
		free(head->data); // data도 함께 해제
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

// data free 함수
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

