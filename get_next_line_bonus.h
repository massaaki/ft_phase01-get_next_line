/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:53:22 by mmassaak          #+#    #+#             */
/*   Updated: 2022/04/14 23:00:49 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

struct s_list
{
	char			*buf;
	int				fd;
	struct s_list	*next;
};

char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*get_next_line(int fd);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
void			update_list(struct s_list **acc, int fd);
void			ft_join_accumulator(char **acc, char *current_buffer);
void			delete_fd(struct s_list **acc, int fd);
char			*ft_split_n(char **acc, char *ptr_n, int file_return);
struct s_list	*ft_initialize(struct s_list **acc, int fd, int *file_return);

#endif