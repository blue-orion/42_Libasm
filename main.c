#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libasm.h"

t_list	*new_node(void *data);

int main(void) {
	char *msg = "Hello";

	printf("ft_strlen test\n");
	printf("'hello'.length = %ld\n\n", ft_strlen(msg));

	printf("ft_strcpy test\n");
	char dst[6];
	ft_strcpy(dst, msg);
	printf("COPY of 'hello': %s\n\n", dst);

	printf("ft_strcmp test\n");
	printf(" compare 'hello', 'hello': %d\n\n", ft_strcmp(dst, msg));

	printf("ft_read & ft_write test\n");
	char	buf[4096];
	int		read_byte = ft_read(1, buf, 4096);
	printf("read_byte = %d\n", read_byte);
	if (read_byte == -1) {
		perror("read error");
	}
	buf[read_byte] = '\0';

	if (ft_write(1, buf, ft_strlen(buf)) == -1) perror("write error");
	write(1, "\n", 1);

	printf("ft_strdup test\n");
	printf("%s\n\n", ft_strdup(buf));

	printf("ft_atoi_base test\n");
	printf("'42' => %d\n", ft_atoi_base("42", "0123456789"));
	printf("'42' => %d\n", ft_atoi_base("   42", "0123456789abcdef"));
	printf("'42' => %d\n\n", ft_atoi_base("42", "01"));

	printf("ft_atoi_base test\n");
	t_list *head = new_node("first");
	head->next = new_node("second");
	head->next->next = new_node("third");

	size_t size = ft_list_size(head);
	printf("List size: %zu\n", size);  // 기대값: 3
	
	ft_list_push_front(&head, "fourth");
	size = ft_list_size(head);
	printf("List size: %zu\n", size);  // 기대값: 4

	// 메모리 정리
	t_list *tmp;
	while (head) {
		tmp = head->next;
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
