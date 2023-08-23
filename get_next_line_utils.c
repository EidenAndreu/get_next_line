/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:14:00 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/23 22:33:06 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_line(char *pending)
{
	int		i;
	char	*str;

	i = 0;
	if (!pending[i])
		return (NULL);
	while (pending[i] && pending[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (pending[i] && pending[i] != '\n')
	{
		str[i] = pending[i];
		i++;
	}
	if (pending[i] == '\n')
	{
		str[i] = pending[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_pending_trimmed(char *pending)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (pending[i] && pending[i] != '\n')
		i++;
	if (!pending[i])
	{
		free(pending);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(pending) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (pending[i])
		str[j++] = pending[i++];
	str[j] = '\0';
	free(pending);
	return (str);
}
