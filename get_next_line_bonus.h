/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:56:20 by ybourais          #+#    #+#             */
/*   Updated: 2022/12/25 14:16:07 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 310
# elif (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		ft_len(char *str);
char	*ft_copy(char *s1, char *s2, int n);
char	*ft_str_join(char *s1, char *s2);
int		ft_index_chrch(char *str, int n);
char	*ft_sub_str(char *str, int start, int len);
char	*get_next_line(int fd);
int		ft_index(char *str, int n);

#endif
