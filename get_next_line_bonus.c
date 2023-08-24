/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:43:10 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/24 11:43:17 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *pending)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(pending, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		pending = ft_strjoin(pending, buffer);
	}
	free(buffer);
	return (pending);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pending[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pending[fd] = ft_read(fd, pending[fd]);
	if (!pending[fd])
		return (NULL);
	line = ft_get_line(pending[fd]);
	pending[fd] = (ft_pending_trimmed(pending[fd]));
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
