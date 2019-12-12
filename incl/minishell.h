/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:56:41 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/06 10:47:43 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/incl/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# define CLEAR() ft_printf("\033[H\033[J")

char	**g_envv;
int		ft_pwd(void);
void	free_strptr(char **ptr);
int		ft_strindex(char *str, char c);
char	*ft_strjoinfree(char *s1, char const *s2);
char	*get_binpath(char *cmd);
int		get_envv_len(char	**env);
void	print_evv(char **env);
int		ft_getenvindex(char	*name);
void	init_env(char	**tenvv);
char	*ft_getenv(char	*name);
void	change_env(char *name, char *new);
int		change_dir(char *path);
void	new_env(char **args);
void	remove_env(int i);
void	echo_built(char **args);
void	unset_env(char **args);
void	set_env(char **args);
#endif
