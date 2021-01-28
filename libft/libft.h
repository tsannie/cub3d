/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:41:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/28 16:07:27 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define I_MAX 2147483647
# define I_MIN -2147483648
# define BUFFER_SIZE 100

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *memoryblock, int searchedchar,
						size_t size);
int					ft_memcmp(const void *pt1, const void *pt2, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *destination, const void *source,
						size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char	*big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char const *str, char charset);
void				ft_rev_char_tab(char *tab);
void				ft_rev_int_tab(int *tab, int size);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_putunbr_fd(unsigned int n, int fd);
void				ft_putuihex(unsigned int src);
void				ft_putuihexm(unsigned int src);
int					ft_nbcharint(int a);
void				ft_putultoh(unsigned long src);
int					ft_nbcharhex(unsigned long src);
int					ft_nbcharuint(unsigned int a);
int					ft_nbcharuihex(unsigned int src);
void				ft_putstrn_fd(char *s, int n, int fd);
int					ft_minvalue(int a, int b);
int					ft_maxvalue(int a, int b);
int					get_next_line(int fd, char **line);
int					ft_iscolor(int a, int b, int c);
int					ft_ispair(int a);
int					ft_streql(const char *s1, const char *s2);

#endif
