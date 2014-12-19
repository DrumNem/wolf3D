/*
** my_str_isupper.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_13
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 22:10:18 2014 tiphaine perra
** Last update Mon Oct 20 20:05:07 2014 tiphaine perra
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while ((str[i] >= 'A' && str[i] <= 'Z') && (str[i] != '\0'))
    {
      i = i + 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
