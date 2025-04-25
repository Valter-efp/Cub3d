/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:06:03 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:05 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21474/* 83647 */
# endif

# ifndef MULTIPLEFD_LIMT
#  define MULTIPLEFD_LIMIT 4242
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strchr_gnl(char *str, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strndup_gnl(char *s, int len);
char	*dealloc(char *stash, char *buffer);
char	*read_file(int fd, char *stash);
char	*extract_remaining_line(char *stash);
char	*get_next_line(int fd);
int		ft_strclen(char *str, char c);

#endif