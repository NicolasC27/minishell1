/*
** main.c for main.c in /home/cheval_8/rendu/PSU_2015_minishell1
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Jan  5 15:30:29 2016 Nicolas Chevalier
** Last update Fri Jan 29 16:07:39 2016 Nicolas Chevalier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"

void		my_prompt(t_list *env, int nb)
{
  char		*user;
  char		*pwd;

  user = search_env(env, "USER");
  pwd = search_env(env, "PWD");
  if (nb == 1)
    my_putstr("\033[1;32mMinishell 1 working... \033[1;0m \n");
  if (user != NULL || pwd != NULL )
    {
      my_putstr("\033[1;31m");
      my_putstr("(");
      if (user)
	my_putstr(user);
      if (pwd)
	{
	  my_putstr("@");
	  my_putstr("\033[1;36m");
	  my_putstr(pwd);
	}
      my_putstr("\033[1;31m");
      my_putstr(")");
    }
  my_putstr("\033[1;31m");
  my_putstr("->");
  my_putstr("\033[1;0m");
}

char		minishell(char *buff, t_list  *env)
{
  char		**tab;

  tab = my_str_to_wordtab(buff, ' ');
  check_command(tab, env);
  my_free(tab);
  return (0);
}

void		my_control_c(int c)
{
  (void)c;
  my_putstr("\033[1;31m");
  my_putstr("\n->");
  my_putstr("\033[1;0m");
}

void		my_signal()
{
  if (signal(SIGINT, my_control_c) == SIG_ERR)
    my_puterror("error: problem wit signal SIGInt.\n");
}

int		main(int argc, char **argv, char **envp)
{
  char		buff[BUFF_SIZE + 1];
  t_list	*env;
  int		fd;

  if (envp[0] == NULL)
    envp[0] = NULL;
  env = init_listenv(envp);
  my_prompt(env, 1);
  while ((fd = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (fd == BUFF_SIZE)
	{
	  my_putstr("Commands too big !\n");
	  my_putstr("\033[1;32mMinishell 1 stopped... \033[1;0m \n");
	  exit (0);
	}
      buff[fd - 1] = '\0';
      minishell(buff, env);
      my_prompt(env, 2);
      my_signal();
    }
  close(fd);
  my_putstr("\n\033[1;32mMinishell 1 stopped... \033[1;0m \n");
  return (0);
}
