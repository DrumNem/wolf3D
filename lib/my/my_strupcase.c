/*
** my_strupcase.c for  in /home/perra_t/rendu/Piscine_C_J06/ex_07
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 17:37:40 2014 tiphaine perra
** Last update Mon Oct 20 20:05:36 2014 tiphaine perra
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - ('a' - 'A');
      i = i + 1;
    }
  return (str);
}
