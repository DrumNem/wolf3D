/*
** my_strcapitalize.c for  in /home/perra_t/rendu/Piscine_C_J06
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Tue Oct  7 19:45:58 2014 tiphaine perra
** Last update Tue Oct  7 21:25:14 2014 tiphaine perra
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + ('a' - 'A');
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z'
	  && (i ==  0 || str[i - 1] == ' ' || str[i - 1] == '+' ||
	      str[i - 1] == '-'))
	str[i] = str[i] - ('a' - 'A');
      i = i + 1;
    }
  return (str);
}
