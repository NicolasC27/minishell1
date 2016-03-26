/*
** init_listenv.c for init_listenv.c in /home/cheval_8/rendu/PSU_2015_minishell1
**
** Made by Nicolas Chevalier
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Jan  5 18:55:51 2016 Nicolas Chevalier
** Last update Mon Jan 25 17:35:42 2016 Nicolas Chevalier
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

t_list		*create_node(void)
{
  t_list	*node;

  if ((node = malloc(sizeof(t_list))) == NULL)
    my_puterror("Error with a memory allocation\n");
  node->next = node;
  node->prev = node;
  return (node);
}

t_list		*add_env(t_list *env, char *str, char *str2)
{
  t_list	*tmp;
  int		i;
  int		z;

  z = 0;
  i = 0;
  tmp = create_node();
  if ((tmp->data = malloc(my_strlen(str) + my_strlen(str2) + 2)) == NULL)
    my_puterror("Problem with a memory allocation\n");
  while (str2 && str2[i] != '\0')
    tmp->data[z++] = str2[i++];
  i = 0;
  tmp->data[z++] = '=';
  while (str && str[i] != '\0')
    tmp->data[z++] = str[i++];
  tmp->data[z] = '\0';
  tmp->prev = env->prev;
  tmp->next = env;
  env->prev->next = tmp;
  env->prev = tmp;
  return (env);
}

t_list		*init_listenv(char **env)
{
  t_list	*tmp;
  t_list	*tmp2;
  int		i;
  int		j;

  tmp = create_node();
  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      j = -1;
      tmp2 = create_node();
      if ((tmp2->data = malloc(my_strlen(env[i]) + 1)) == NULL)
	my_puterror("Error with a memory allocation");
      while (env[i][++j] != '\0')
	tmp2->data[j] = env[i][j];
      tmp2->data[j] = '\0';
      tmp2->prev = tmp->prev;
      tmp2->next = tmp;
      tmp->prev->next = tmp2;
      tmp->prev = tmp2;
      i++;
    }
  return (tmp);
}
