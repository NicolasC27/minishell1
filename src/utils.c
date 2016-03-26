/*
** utils.c for utils.c in /home/cheval_8/rendu/PSU_2015_minishell1
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Jan  5 18:11:50 2016 Nicolas Chevalier
** Last update Sun Jan 24 23:27:23 2016 Nicolas Chevalier
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putchar_err(char c)
{
  write(2, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str && str[++i] != '\0')
    my_putchar(str[i]);
}

void		my_putstr_err(char *str)
{
  int		i;

  i = -1;
  while (str && str[++i] != '\0')
    my_putchar_err(str[i]);
}

int		count_list(t_list *tmp, t_list *env)
{
  int		count;

  count = 0;
  while (tmp != env)
    {
      ++count;
      tmp = tmp->next;
    }
  return (count);
}
