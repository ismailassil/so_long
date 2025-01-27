/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:57:53 by iassil            #+#    #+#             */
/*   Updated: 2024/01/28 15:08:04 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

size_t	ft_strchr__(const char *str);
size_t	ft_strlen_(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_calloc(size_t count, size_t size);
char	*ft_newstr(char **str);
char	*ft_new(char **str);
void	*ft_allocate_read_check(ssize_t *nbyte, int *fd, \
								char **buf, char **line);
#endif