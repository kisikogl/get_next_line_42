/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:21:17 by kisikogl          #+#    #+#             */
/*   Updated: 2022/06/16 17:28:35 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_one_line(int fd, char *line, char *buf);
int		read_until_n(char *buf, char **line_pointer, int fd, int error);
char	*join_string(char *s1, char *s2, int freee);
size_t	len_string(char *s);
char	*until_n(char *buf, int *error);
char	*after_n(char *buf, int freee);
#endif