/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:12:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/15 07:01:05 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SIZE_MAX 18446744073709551615UL

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Set "lenght" bytes of "b" to zero '/0'.
 * 
 */
void	ft_bzero(void *b, size_t lenght);
/**
 * @brief Run FT function on all STR addresses.
 * 
 */
void	ft_striteri(char *str, void (*ft)(unsigned int, char*));
/**
 * @brief Write CHR on FD archive.
 * 
 */
void	ft_putchar_fd(char chr, int fd);
/**
 * @brief Write STR with a line break on FD archive.
 * 
 */
void	ft_putendl_fd(char *str, int fd);
/**
 * @brief Write NBR on FD archive.
 * 
 */
void	ft_putnbr_fd(int nbr, int fd);
/**
 * @brief Write STR on FD archive.
 * 
 */
void	ft_putstr_fd(char *str, int fd);
/**
 * @brief Add NEW at the beginning if LST.
 * 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Set LEN bytes of DEST to C.
 * 
 */
void	*ft_memset(void *dest, int c, size_t len);
/**
 * @brief Alloc memory of NUMBER elements of SIZE bytes and fill with 0.
 * 
 */
void	*ft_calloc(size_t number, size_t size);
/**
 * @brief Find firts intance of CHR in LEN bytes of BYTE.
 * 
 */
void	*ft_memchr(const void *byte, int chr, size_t len);
/**
 * @brief concatenate LEN bytes from memory area SRC to memory area DEST.
 * 
 */
void	*ft_memmove(void *dest, const void *src, size_t len);
/**
 * @brief copies LEN bytes from memory area SRC to memory area DEST.
 * 
 */
void	*ft_memcpy(void *dst, const void *src, size_t len);
/**
 * @brief put NEW at the end of LST.
 * 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief run DEL in content of LST and free LST
 * 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char chr);
char	*ft_itoa(int nbr);
char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char));
char	*ft_base_converter(unsigned long nbr, char *base);
char	*ft_uitoa(unsigned int nbr);
char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
char	*ft_strnstr(const char *bigStr, const char *littleStr, size_t len);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_smart_isdigit(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_memcmp(const void *byte1, const void *byte2, size_t len);
int		ft_atoi(const char *numstr);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
