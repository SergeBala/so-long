/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:57:44 by sbalasho          #+#    #+#             */
/*   Updated: 2023/02/06 17:25:44 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H 
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h> 
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000

# endif

int		ft_toupper(int ch);
int		ft_tolower(int ch);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_bzero(void *str, size_t n);
int		ft_isalpha(int a);
int		ft_isdigit(char a);
int		ft_isalnum(int a);
int		ft_isprint(int a);
int		ft_isascii(int a);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t numb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_new_strlen(const char *str);
size_t	ft_new_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_new_strjoin(char *s1, char *s2);
char	*ft_new_substr(char *s, unsigned int start, size_t len);
int		is_a_line(char *str);
char	*join_and_free(char *stash, char *buf);
char	*read_untill_line(int fd, char *stash);
char	*get_line(char *stash, int n_pos);
char	*get_tail(char *stash, int n_pos);
char	*get_next_line(int fd);

#endif
