/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:48:41 by smazouz           #+#    #+#             */
/*   Updated: 2022/02/27 19:04:30 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*cmd;
	char			**path;
	char			*n_cmd;
	char			**command_path;
	struct s_list	*next;

}	t_list;

typedef struct s_struct
{
	int	out;
	int	in;
}	t_struct;

char	**ft_split(char *s, char c);
char	*ft_strjoin(int size, char **strs);
char	*ft_find_path(char **env, const char *path);
int		check_name(char *str, int *l, const char *path);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
char	**ft_paths(char **path, char *command);
int		ft_size_count(char **path);
char	*ft_command(char *str);
int		ft_permissions(t_list *command_lst);
t_list	*ft_lstnew(char **path, char *command, char *new_cammand);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	pipex(t_list *cmd, char **env, t_struct *list);
void	loop_pipe_(char **env, t_list *cmd, int *p, t_struct *list);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
void	ft_free_tab(char **tab);
void	ft_free_list(t_list **lst);
void	ft_putstr(char *str);
void	ft_malloc_error(int n, t_list **lst, char **path);
int		is_alpha_n(char c);
void	read_from_here_doc(t_list **lst, int fd_in, char *limiter, char **env);
int		check_for_dollar(char *line);
char	*up_line(char *line, char **env);
char	*ft_make_new_line(char *line, char *var, int size, int dollar_number);
char	*rest_of_line(char *line);
int		ft_get_line(char *line);
char	*var_name(char *line);
char	*ft_read(void);
char	*ft_command(char *str);
int		ft_permissions(t_list *cmd);
void	ft_check_commands_permission(t_list **command_lst);
void	ft_parcer(int size, char **array, t_list **cmd, int x);
t_list	*make_list(char **path, int size, char *av[], int x);
#endif