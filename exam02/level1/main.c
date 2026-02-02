#include <stdio.h>

void    ft_putstr(char *str);
char    *ft_strcpy(char *s1, char *s2);
int	ft_strlen(char *str);
void	ft_swap(int *a, int *b);

int main(){
    ft_putstr("I want to go home\n");

    char s1[] = "abcd";
    char s2[] = "Hello";
    printf("%s\n",ft_strcpy(s1, s2));

    printf("the length of %s is %d\n",s2, ft_strlen(s2));
    
    int *a;
    int aa = 3,bb = 4;
    a = &aa;
    int *b;
    b = &bb;
    printf("a is %d and b is %d\n", *a, *b);
    ft_swap(a,b);
    printf("after swap, a is %d and b is %d\n", *a, *b);
    return (0);
}