/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:50:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/01 21:18:17 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
#include "libftprintf.h"
#include <unistd.h>
#include <sys/wait.h>

typedef struct	s_av
{
	char	*in;
	char	*out;
	char	*key;
	char	*val;
}				t_av;


typedef struct	s_shell
{
	int			argc;
	char		**argv;
	char		**envp;
	char		*buffer;
	size_t		bufsize;
	char		**child_argv;
}				t_shell;

int		count_command_arguments(char *str);
char	**add_element_to_char_array(char **array, char *string);
char	**create_char_array_copy(char **src, int extra);
char	*argument_by_index(t_shell *sh, char *str, int index);
char	*create_kv_string(char *key, char *value);
char	*get_word_by_index(char *str, int index);
char	*kv_array_get_key_value(char **array, char *key);
int		count_char_array(char **array);
int		get_word_length(char *str);
int		kv_array_get_key_index(char **array, char *key);
int		main(int argc, char **argv, char **envp);
int		builtin_cmd_index(char *cmd);
t_shell	*init_shell(int argc, char **argv, char **envp);
void	builtin_cd(t_shell *sh);
void	builtin_echo(t_shell *sh);
void	builtin_env(t_shell *sh);
void	builtin_exit(t_shell *sh);
void	builtin_help(t_shell *sh);
void	builtin_setenv(t_shell *sh);
void	builtin_unsetenv(t_shell *sh);
void	clean_up(t_shell *sh);
void	destroy_char_array(char **array);
void	fatal_error(t_shell *sh);
void	fatal_error_message(t_shell *sh, char *msg);
void	get_input(t_shell *sh);
void	increase_buffer(t_shell *sh);
void	kv_array_remove_key(char **array, char *key);
void	kv_array_set_key_value(char ***array, char *key, char *value);

#endif
