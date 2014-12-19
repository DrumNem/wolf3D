/*
** my_str_isalpha.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_10
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 21:28:08 2014 tiphaine perra
** Last update Wed Oct  8 15:44:26 2014 tiphaine perra
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while ((str[i] >= 'A' && str[i] <= 'Z') && (str[i] >= 'a' && str[i] <= 'z')
	 && (str[i] != '\0'))
    {
      i = i + 1;
    }
  if (str[i] == '\0')
    return (1);
  return (0);
}
