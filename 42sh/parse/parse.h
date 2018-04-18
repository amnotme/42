/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:42:37 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/16 00:04:45 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define MEMALLOC(A, B) (A*)ft_memalloc(sizeof(A) * B)

/*
** # include "main_header_path.h"
*/

typedef struct		s_run
{
	int				pipe[2];
	int				last_process_status;
	char			is_pipe;
	char			*input_head;
	char			*command_head;
	char			*command_end;
	char			*stream_end;
	char			***env;
	pid_t			pid;
}					t_run;

/*
** main_struct =
** the general struct that contains relevant information
*/

/*
** run_numbers is the name of the typedef t_run
** as in
** t_run	*run_numbers;
*/

void				run_job(char ***env, char *input_head);
void				run_condition(t_run *run_numbers);
void				run_pipe(t_run *run_numbers);
void				run_stream(t_run *run_numbers);
void				run_command(t_run *run_numbers);
unsigned int		count_word_length(char *word_start);
char				*skip_spaces(char *address);
char				*get_next_word(char *address);
char				*skip_beginning(char *address);
int					redirect_output(t_run *run_numbers);
int					redirect_input(t_run *run_numbers);
int					get_fd(char *file_head, int is_append, int is_write);
int					execute_builtin(int index, char **av, char **env);
void				free_run_numbers(t_run *run_numbers);
void				redirect(t_run *run_numbers);
void				execute(t_run *run_numbers);
int					check_if_condition(char *address);
int					is_word_equal(char *word_head, char *reference);
int					is_conditional(char *word_head);
void				redirect(run_numbers);
int					execute(run_numbers);
void				check_functions(t_run *run_numbers,
						char **av, char ***env, int *status);
int					check_executables(t_run *run_numbers,
						char **av, char ***env, int *status);

#endif
