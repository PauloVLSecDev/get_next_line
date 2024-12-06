/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:43:35 by pvitor-l          #+#    #+#             */
/*   Updated: 2024/12/06 16:06:46 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while(s[len] != '\0')
		len++;
	return (len);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
 
char	*ft_strjoin(const char *s1, const char *s2)
{
	char    *s3;
	size_t  size;
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(size + 1);
	if (!s3)
		return (NULL);
	while(*s1 != '\0')
		s3[i++] = *s1++;
	while(*s2 != '\0')
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
