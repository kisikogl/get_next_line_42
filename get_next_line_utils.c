/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:34:20 by kisikogl          #+#    #+#             */
/*   Updated: 2022/06/18 14:18:23 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len_string(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*join_string(char *s1, char *s2, int freee)
{
	char	*pnt;
	size_t	len;
	size_t	a;

	if (!s1 || !s2)
		return (NULL);
	len = len_string(s1) + len_string(s2);
	pnt = malloc(len + 1);
	if (pnt == NULL)
		return (NULL);
	a = 0;
	while (a < len)
	{
		if (a < len_string(s1))
			pnt[a] = s1[a];
		else
			pnt[a] = s2[a - len_string(s1)];
		a++;
	}
	pnt[a] = '\0';
	free(s1);
	if (freee == 2)
		free(s2);
	return (pnt);
}

char	*until_n(char *buf, int *error)
{
	char	*str;
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
	}
	if (buf[i] == '\n')
		*error = 1;
	else
		*error = 0;
	str = malloc(i + *error + 1);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	if (*error == 1)
		str[i] = '\n';
	str[i + *error] = '\0';
	return (str);
}

char	*after_n(char *buf, int freee)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	while (buf[i++] != '\n' && buf[i] != '\0')
		i = i + i - i;
	if (buf[i] == '\0')
	{
		if (freee == 1)
			free(buf);
		return (NULL);
	}
	str = malloc(BUFFER_SIZE - i + 1);
	str[BUFFER_SIZE - i] = '\0';
	k = 0;
	while (buf[i] != '\0')
	{
		str[k++] = buf[i++];
	}
	str[k] = '\0';
	if (freee == 1)
		free(buf);
	return (str);
}
