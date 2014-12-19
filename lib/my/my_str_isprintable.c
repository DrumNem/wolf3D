/*
** my_str_isprintable.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_14
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 22:22:48 2014 tiphaine perra
** Last update Wed Oct  8 15:44:49 2014 tiphaine perra
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  if (str == 0)
    return (0);
  while ((str[i] >= ' ' && str[i] <= '~') && (str[i] != '\0'))
    {
      i = i + 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
