/*
** my_str_islower.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_12
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 22:04:43 2014 tiphaine perra
** Last update Mon Oct 20 20:04:45 2014 tiphaine perra
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while ((str[i] >= 'a' && str[i] <= 'z') && (str[i] != '\0'))
    {
      i = i + 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
