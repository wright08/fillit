/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 08:18:47 by rwright           #+#    #+#             */
/*   Updated: 2019/02/19 21:00:27 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

typedef struct s_list	t_list;
typedef unsigned char	t_byte;

/*
**		[CTYPES]
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
**		[STDLIB]
*/
int		ft_atoi(const char *str);

/*
**		[STRING]
*/
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strcat(char *dst, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/*
**		[LIBFT I/O]
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char *str);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(const char *str, int fd);

/*
**		[LIBFT STRINGS/MEM]
*/
char	*ft_itoa(int n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
int		ft_strequ(const char *s1, const char *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	**ft_strsplit(const char *s, char c);
char	*ft_strsub(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);

/*
**		[LIST]
*/
void	ft_lstadd(t_list **lst, t_list *new);
void	ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(const void *content, size_t content_size);

int		get_next_line(const int fd, char **line);

#endif
