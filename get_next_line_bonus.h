/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massaaki <massaaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:53:22 by massaaki          #+#    #+#             */
/*   Updated: 2022/04/09 15:39:07 by massaaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

struct list
{
	char		*buf;
	int			fd;
	struct list *next;
};

char 		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
void		update_list(struct list **accumulator, int fd);
void		ft_join_accumulator(char **accumulator, char *current_buffer);
void		delete_fd(struct list **accumulator, int fd);
char		*ft_split_n(char **accumulator, char *ptr_n, int file_return);
struct list *ft_initialize(struct list **accumulator, int fd, int *file_return);

#endif