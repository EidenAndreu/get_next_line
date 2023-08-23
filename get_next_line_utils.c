/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:14:00 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/23 13:11:07 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
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
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
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
	j = 0;
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
	while (pending[i])
		str[j++] = pending[i++];
	str[j] = '\0';
	free(pending);
	return (str);
}
