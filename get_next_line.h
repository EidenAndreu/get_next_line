/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:13:49 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/23 22:43:31 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *pending);
char	*ft_pending_trimmed(char *pending);
char	*get_next_line(int fd);

#endif
