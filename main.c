#include <stdio.h>

extern size_t ft_strlen(const char *);
extern char*  ft_strcpy(char *dst, const char *src);
extern int    ft_strcmp(const char *s1, const char *s2);

int main(void) {
  char *msg = "hello";

  printf("ft_strlen test\n");
  printf("'hello'.length = %ld\n\n", ft_strlen(msg));

  printf("ft_strcpy test\n");
  char dst[6];
  ft_strcpy(dst, msg);
  printf("COPY of 'hello': %s\n\n", dst);

  printf("ft_strcmp test\n");
  printf(" compare 'hello', 'hello': %d\n\n", ft_strcmp(dst, msg));
}
