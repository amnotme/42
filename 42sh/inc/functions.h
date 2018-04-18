/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:20:50 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/18 00:59:59 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "ft.h"
# include "parse.h"

typedef struct s_shell		t_shell;
typedef struct s_av			t_av;
typedef struct s_process	t_process;
typedef struct s_exec		t_exec;
typedef	t_process			t_proc;

int		*group_process_make_pipes(t_process **group, int *i, int *count);
int		group_process_close_pipes(t_process **group, int *pipes, int count);
char	**add_element_to_char_array(char **array, char *string);
char	**build_child_argv_list(t_shell *sh, char *cmd);
char	**create_char_array_copy(char **src, int extra);
char	**history_array(t_shell *sh);
char	*basename(char *str);
char	*builtin_cd_get_kv(t_shell *sh, char *variable);
char	*builtin_cd_get_path(t_shell *sh, char **argv);
char	*create_kv_string(char *key, char *value);
char	*delete_backslash_in_double_quote(char *str);
char	*dir_slash_exec(char *dir, char *cmd);
char	*file_get_contents(char *filename);
char	*find_command_path(t_shell *sh, char *cmd);
char	*get_type_string(char *str);
char	*history_file_name(t_shell *sh);
char	*history_get_item(t_shell *sh, int index);
char	*kv_array_get_key_value(char **array, char *key);
char	*remove_start_space(char *str);
int		process_execute(t_shell *sh, t_process *p);
int		ast_ambiguous_error(char *msg);
int		ast_main(void);
int		builtin_cd(t_shell *sh, char **argv);
int		builtin_cd_save_cwd(t_shell *sh, char *variable);
int		builtin_cmd_index(char *cmd);
int		builtin_echo(t_shell *sh, char **argv);
int		builtin_env(t_shell *sh, char **argv);
int		builtin_exit(t_shell *sh, char **argv);
int		builtin_help(t_shell *sh, char **argv);
int		builtin_setenv(t_shell *sh, char **argv);
int		builtin_setenv_kv(t_shell *sh, char **argv, int arg_count);
int		builtin_unsetenv(t_shell *sh, char **argv);
int		col_print_cmd(char *s, int j, int cw, int nc);
int		count_char_array(char **array);
int		execute_external_cmd(t_shell *sh, t_process *p);
int		fork_exec_wait(t_shell *sh, t_process *p, char *fullpath);
int		ft_append(char **str, char *buff, int fd, int size);
int		ft_contains_end_line(char *str);
int		ft_copy_and_cut(char **str, char **line, int fd);
int		ft_copy_end_file(char **str, char **line, int fd);
int		get_nbr_redirection(char *str);
int		group_process_execute(t_shell *sh, t_process **group, int i, int ct);
int		group_process_wait(t_process **group);
int		is_end_of_argument(char c);
int		is_valid_executable_file(char *filename);
int		kv_array_get_key_index(char **array, char *key);
int		main(int argc, char **argv, char **envp);
int		mini_parse(t_shell *sh, t_av *av, int *i, int *k);
int		parse_quote(char **word, char *str);
int		parse_quote_double(char **word, char *str);
int		parse_quote_single(char **word, char *str);
int		path_has_executable(char *path, char *cmd);
int		tab_all_commands_longer(t_shell *sh, t_exec **a);
int		tab_all_commands_share_letter(t_exec **a, int index, char c);
int		tab_count_matches(t_shell *sh);
int		tab_max_length(t_exec **array);
int		tab_mini_complete(t_shell *sh, t_exec **a);
int		ast_main3(void);
int		ft_isalnum2(int c);
int		handle_dollar_sign(t_av *av, t_shell *sh, int *i, int *k);
int		handle_strong_quote(t_av *av, int *i, int *k);
int		handle_weak_quote(t_av *av, t_shell *sh, int *i, int *k);
int		is_alphanumeric_string(char *str);
int		is_numeric_string(char *str);
int		string_has_whitespace(char *str);
int		unmatched_quote_error(t_av *av, char quote);
t_av	*init_av_buffers(char *cmd);
t_proc	*process_prepare(t_shell *sh, t_ast *ast);
t_shell	*init_shell(int argc, char **argv, char **envp);
void	execute(t_shell *sh, char *cmd);
void	process_destroy(t_process *p);
void	add_string_to_child_argv(t_av *av, char *str, int *k);
void	add_to_list_of_executables(t_shell *sh, char *cmd);
void	build_list_of_executables(t_shell *sh, char **folders);
void	check_special_keys(t_shell *sh);
void	clean_up(t_shell *sh);
void	cleanup_av_buffers(t_av *av);
void	clear_input_buffers(t_shell *sh);
void	cmd_title(void);
void	col_if_flag_print_newline(int *f);
void	col_print_loop(int cw, int nc, int count, t_exec **a);
void	destroy_char_array(char **array);
void	destroy_list_of_executables(t_shell *sh);
void	display_shell_prompt(void);
void	display_shell_quote_prompt(void);
void	end_of_input(t_shell *sh);
void	execute(t_shell *sh, char *cmd);
void	fatal_error(t_shell *sh);
void	fatal_error_message(t_shell *sh, char *msg);
void	group_fork_exec(t_process **group, int i, int count, int *pipes);
void	group_process_destroy(t_process **group);
void	header_42(void);
void	header_sh(void);
void	history_append_to_file(t_shell *sh);
void	increase_buffer(t_shell *sh);
void	init_input_buffer(t_shell *sh);
void	insert_key_into_buffer(t_shell *sh);
void	key_backspace_function(t_shell *sh);
void	key_ctrl_a_function(t_shell *sh);
void	key_ctrl_e_function(t_shell *sh);
void	key_ctrl_k_function(t_shell *sh);
void	key_ctrl_l_function(t_shell *sh);
void	key_delete_function(t_shell *sh);
void	key_down_arrow_function(t_shell *sh);
void	key_left_arrow_function(t_shell *sh);
void	key_right_arrow_function(t_shell *sh);
void	key_tab_function(t_shell *sh);
void	key_up_arrow_function(t_shell *sh);
void	kv_array_remove_key(char **array, char *key);
void	kv_array_set_key_value(char ***array, char *key, char *value);
void	print_error_ast(void);
void	print_error_lexer(void);
void	raw_read(t_shell *sh);
int		has_paire_quote(t_shell *sh);
void	reprint_input(t_shell *sh);
void	restore_partial_input(t_shell *sh);
void	sigint_handler(int signo);
void	tab_bubble_sort(t_exec **a, int count);
void	tab_print_columns(t_exec **array, int count);
void	tab_remove_duplicates(t_exec **array, int *count);
void	terminal_init(t_shell *sh);
void	termios_restore_settings(t_shell *sh);
void	termios_save_settings(t_shell *sh);
void	ptr_null(t_shell *sh, t_ast **ptr);
void	ptr_not_null(t_shell *sh, t_ast	**ptr, t_process **p, int *ec);
void	main_ptr(t_shell *sh, t_ast	**ptr, t_process **p, int *ec);
void	main_helper(t_shell *sh, int *ec);

#endif
