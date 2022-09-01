/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:05:11 by merkol            #+#    #+#             */
/*   Updated: 2022/03/01 13:05:54 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*f_strjoin(char *mystr, char *buff);
char	*f_strchr(char *s, int c);
size_t	f_strlen(char *s);

#endif
