/*
** my_strstr.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_04
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 10:26:00 2014 tiphaine perra
** Last update Tue Oct  7 16:54:31 2014 tiphaine perra
*/

int	my_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_ncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      i = i + 1;
    }
  if (i == n)
    return (0);
  return (s1[i] - s2[i]);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	length;

  i = 0;
  length = my_len(to_find);
  while (str[i] != '\0')
    {
      if (my_ncmp(str + i, to_find, length) == 0)
	return (str + i);
      i = i + 1;
    }
  return (0);
}

