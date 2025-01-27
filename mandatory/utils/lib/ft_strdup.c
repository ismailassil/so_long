/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:16:47 by iassil            #+#    #+#             */
/*   Updated: 2024/02/17 02:24:15 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../_header/so_long.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + 1;
	ptr = (char *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	t_srclen;
	size_t	i;

	i = 0;
	t_srclen = ft_strlen(src);
	if (dstsize < 1)
		return (t_srclen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (t_srclen);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	if ((haystack == NULL || needle == NULL) && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		index = i;
		while (haystack[index] == needle[j] && needle[j] != '\0' && index < len)
		{
			if (index > len)
				return (NULL);
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			index++;
		}
		i++;
	}
	return (0);
}
