/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:10:45 by merkol            #+#    #+#             */
/*   Updated: 2022/03/01 13:44:25 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s)
		i++;
	return (i);
}

char	*f_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && c != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*f_strjoin(char *mystr, char *buff)
{
	char	*newstr;
	int		i;
	int		j;

	if (!mystr)
	{
		mystr = malloc(1);
		mystr[0] = '\0';
	}
	newstr = malloc(sizeof(char) * ((f_strlen(mystr) + f_strlen(buff)) + 1));
	i = 0;
	j = 0;
	while (mystr[i] != '\0')
	{
		newstr[i] = mystr[i];
		i++;
	}
	while (buff[j] != '\0')
		newstr[i++] = buff[j++];
	newstr[f_strlen(mystr) + f_strlen(buff)] = '\0';
	free(mystr);
	return (newstr);
}
