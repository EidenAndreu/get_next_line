/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:14:32 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/24 16:47:40 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_clean(char *pending)
{
	char	*saved;
	char	*str;
	int		len;

	str = ft_strchr(pending, '\n');
	if (!str)
	{
		saved = NULL;
		return (ft_free(&pending));
	}
	else
		len = (str - pending) + 1;
	if (!pending[len])
		return (ft_free(&pending));
	saved = ft_substr(pending, len, ft_strlen(pending) - len);
	ft_free(&pending);
	if (!saved)
		return (NULL);
	return (saved);
}

char	*ft_get_line(char *pending)
{
	char	*line;
	char	*str;
	int		len;

	str = ft_strchr(pending, '\n');
	len = (str - pending) + 1;
	line = ft_substr(pending, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *pending)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&pending));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			pending = ft_strjoin(pending, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&pending));
	return (pending);
}

char	*get_next_line(int fd)
{
	static char	*pending;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((pending && !ft_strchr(pending, '\n')) || !pending)
		pending = ft_read (fd, pending);
	if (!pending)
		return (NULL);
	line = ft_get_line(pending);
	if (!line)
		return (ft_free(&pending));
	pending = ft_clean(pending);
	return (line);
}

/*
 int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);

		line = get_next_line(fd);
        printf("LINE1: %s", line);
		free(line);
		line = get_next_line(fd);
        printf("LINE2: %s", line);
		free(line);
		line = get_next_line(fd);
        printf("LINE3: %s", line);
    	free(line);

    close(fd);
    return 0;
}
*/
