/*
** my_revstr.c for  in /home/perra_t/rendu/Piscine_C_J06/tests
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Mon Oct  6 18:24:26 2014 tiphaine perra
** Last update Tue Oct  7 15:46:17 2014 tiphaine perra
*/

char	*my_revstr(char *str)
{
  int	i;
  int	a;
  char	c;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  i = i - 1;
  a = 0;
  while (a < i)
    {
      c = str[a];
      str[a] = str[i];
      str[i] = c;
      a = a + 1;
      i = i - 1;
    }
  return (str);
}
