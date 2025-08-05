#ifndef LIBASM_H
# define LIBASM_H

// Mandatory
size_t	ft_strlen(const char *);
char*	ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s);

// Bonus
typedef struct	s_list {
	void			*data;
	struct s_list	*next;
}	t_list;

int		ft_atoi_base(const char *nptr, const char *base);
size_t	ft_list_size(t_list *lst);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_sort(t_list *lst, int (*cmp)());
void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
