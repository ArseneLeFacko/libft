/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:11:00 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/29 14:24:00 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define FD_SIZE 256

size_t		ft_gnl_strlen(char const *s);
char		*ft_gnl_strchr_endl(char const *s);
char		*ft_gnl_strncpy(char *dst, char const *src, int n);
char		*ft_gnl_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif