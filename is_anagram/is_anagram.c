
#include <stdio.h>
int     is_anagram(char *a, char *b)
{
    int countA = 0;
    int countB = 0;

    while (*a)
    {
        countA += *a;
        a++;
    }
    while (*b)
    {
        countB += *b;
        b++;
    }
    if (countA == countB)
        return (1);
    return (0);
}

int main()
{
    char *a = "hello";
    char *b = "elloh1";

    printf("%i\n", is_anagram(a, b));
}