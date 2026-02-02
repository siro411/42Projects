#include<unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int num){
  char c;
  if (num>=10)
      ft_putnbr(num /10);
  ft_putchar(num % 10 + '0');
}

int ft_atoi(char *str){
  int i;
  int res;

  i = 0;
  res = 0;
  while (str[i]>='0' && str[i]<='9'){
    res = res * 10 + str[i]-'0';
    i++;
  }
  return res;
}

int main(int argc, char *argv[]){
  int i;
  int nbr;

 if(argc == 2){
    i = 1;
    nbr = ft_atoi(argv[1]);
   while (i < 10){
    ft_putnbr(i);
    write(1," x ",3);
    ft_putnbr(nbr);
    write(1," = ",3);
    ft_putnbr(i*nbr);
    write(1,"\n",1);
    i++;  
  }
 }
 else
 {
 write(1,"\n",1);
 }
 return (0);
}