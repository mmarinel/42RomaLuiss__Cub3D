/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:42:16 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/04 17:14:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef T_BOOL
#  define T_BOOL

typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;
# endif

//* boolean
int					ft_isalpha(int c);
int					ft_isdigit(int c);
t_bool				ft_isspace(char c);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
t_bool				ft_isdigit_string( const char *string );
int					ft_isprint(int c);
t_bool				ft_str_isempty( const char *str );
t_bool				is_file_type( const char *path_name,
						const char *extension );

//* memory
void				*ft_calloc(size_t count, size_t size);
void				ft_free( void *ptr );
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

//* strings
char				*ft_strcpy(char *buf, char *src, size_t copy_len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *pre, char *post,
						t_bool free_pre, t_bool free_post);
char				**ft_multisplit( const char *str, const char *delimiters );
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
size_t				ft_str_member( const char *str, char c );
char				*ft_string_new( char c, long len );

//* split utils
void				*ft_splitclear(char ***split_ref);
char				**ft_splitcpy(char **buf, char **src, size_t copy_len);
size_t				ft_splitlen(char **split);
char				**ft_splitinit( size_t size );
char				**ft_splitjoin( char **pre, char **post,
						t_bool free_pre, t_bool free_post );
char				*ft_split_merge(char **split, char *const sep,
						t_bool free_split);
void				ft_splitprint( char **split );

//* ASCII manipulations
int					ft_toupper(int c);
int					ft_tolower(int c);

//* Conversions
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_put_nbr_base(long long num, const char *base,
						int base_num);

//* lists and maps
t_list				*ft_lstnew(void *(*clone)(void *), void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfind(t_list *head,
						t_bool(*test)(const void *, const void *),
						const void *to_find
					);
void				*ft_lstfind_cont(t_list *head,
						t_bool(*test)(const void *, const void *),
						const void *to_find
					);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list				*ft_lstmap(
						t_list *lst,
						void *(*f)(void *),
						void (*del)(void *)
						);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list				**ft_lst_get_prevnext(t_list **head,
						t_bool(*criteria)(const void *, const void *),
						const void *info
						);
void				ft_lstadd_in_order(t_list **head,
						t_list *const new_el,
						t_bool(*greater_than)(const void *, const void *)
					);

//* Printing
void				ft_write( int fd, const char *str );
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

//* math
unsigned long long	ft_int_abs(long long nbr);
double				ft_dbl_abs(double nbr);
float				ft_flt_abs(float val);
long long			ft_int_max(long long a, long long b);

#endif