/*
** my.h for my.h in /home/cheval_8/rendu/PSU_2015_minishell1/includes
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Jan  5 16:32:16 2016 Nicolas Chevalier
// Last update Sun Jan 24 23:29:37 2016 Nicolas Chevalier
*/

#ifndef MY_H_
# define MY_H_

#define BUFF_SIZE 512

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

/*
** my_str_to_wordtab.c
*/
char		**my_str_to_wordtab(char *, char);
/*
** init_listenv.c
*/
t_list		*create_node();
t_list		*init_listenv(char **);
t_list		*add_env(t_list *, char *, char *);
/*
** my_puterror.c
*/
void		my_puterror(char *);
char		my_puterrorcd(char *, char *);
char		my_puterror_execve(char *, char **);
/*
** my_builtin.c
*/
char		my_builtin_exit(char **, t_list *);
char		*check_directory(t_list *, char *);
char		my_builtin_cd(char **, t_list *);
char		my_builtin_env(char **, t_list *);
char		my_builtin_unsetenv(char **, t_list *);
char		my_builtin_setenv(char **, t_list *);
/*
** utils.c
*/
void		my_putchar(char);
void		my_putstr(char *);
int		count_list(t_list *, t_list *);
void		my_free(char **);
void		my_putchar_err(char);
void		my_putstr_err(char *);
/*
** utils_env.c
*/
void		display_env(t_list *);
char		**conv_list(t_list *);
char		*search_env(t_list *, char *);
t_list		*update_env(t_list *, char *, char *);
void		remove_env(t_list *, char *);
/*
** check_command.c
*/
char		*verif_path(char *);
char		*my_find_element(char *, t_list *);
char		check_command(char **, t_list *);
int		my_builtin(char **, t_list *);
/*
** my_exec.c
*/
char		my_execve(char **, t_list *, char *);
char		*recursive_execve(char **, char **, char **, int);
/*
** my_str.c
*/
int		my_strlen(char *);
char		*my_strdup(char *);
char		*my_strcat(char *, char *, int);
int		my_strlen(char *);
char		*my_strdup(char *str);
char		my_strcmp(char *, char *, int);
/*
** my_getnbr.c
*/
int		my_getnbr(char *);
#endif /* !MY_H_ */
