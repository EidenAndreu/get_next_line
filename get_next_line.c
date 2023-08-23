/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:14:32 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/23 22:48:33 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		static char	*pending;

		if (fd < 0 || BUFFER_SIZE <= 0)
			return (0);
		pending = ft_read(fd, pending);
		if (!pending)
			return (NULL);
		line = ft_get_line(pending);
		pending = (ft_pending_trimmed(pending));
		return (line);
}

int	main(void)
{
	int		fd;
	char	buffer[42];
	int		chars_read;

	fd = open("test.txt", O_RDONLY);
	while ((chars_read = read(fd, buffer, 99)))
	{
		buffer[chars_read] = '\0';
		printf("%s\n", buffer);
	}
}
