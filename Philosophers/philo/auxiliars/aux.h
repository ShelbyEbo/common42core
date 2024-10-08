/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:43:03 by mebo              #+#    #+#             */
/*   Updated: 2024/07/24 13:43:04 by mebo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AUX_H
# define AUX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(char *s);
int		ft_isdigit(int c);

char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *str);

#endif
