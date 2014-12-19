/*
** my_str_to_wordtab.c for word_tab in /home/perra_t/Rendu/Piscine_C_J08/ex_04
**
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
**
** Started on  Fri Oct 10 16:34:40 2014 tiphaine perra
** Last update Mon Oct 20 22:21:12 2014 tiphaine perra
*/

#include <stdlib.h>

int	my_count_word(char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 1;
  if (my_is_alnum(str[0]) == 1)
    count++;
  while (str[i] != '\0')
    {
      if (my_is_alnum(str[i]) == 0 && my_is_alnum(str[i + 1]) == 1)
	count++;
      i++;
    }
  return (count);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	ptr;

  ptr = 0;
  tab = malloc(sizeof(char *) * (my_count_word(str) + 1));
  i = 0;
  if (my_is_alnum(str[0]) == 1)
    tab[ptr++] = str;
  while (str[i] != '\0')
    {
      if (my_is_alnum(str[i]) == 0)
	{
	  str[i] = '\0';
	  if (my_is_alnum(str[i + 1]) == 1)
	    tab[ptr++] = &str[i + 1];
	}
      i++;
    }
  tab[ptr] = NULL;
  return (tab);
}
