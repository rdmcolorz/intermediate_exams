#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     isBlank(char c)
{
    if (c == ' ' || c == '\t' || c == '\0' || c == '\n')
        return (1);
    return (0);
}

int     countWords(char *str)
{
    int count;
    int flag;

    count = 0;
    flag = 0;
    while (*str)
    {
        if (!isBlank(*str) && flag == 0)
        {
            flag = 1;
            count++;
        }
        if (isBlank(*str) && flag == 1)
            flag = 0;
        str++;
    }
    return (count);
}

int     wordLen(char *str)
{
    int count;
    
    count = 0;
    while (!isBlank(*str))
    {
        count++;
        str++;
    }
    return (count);
}

char **ftStringSplit(char *str)
{
    char **arr;
    int wordCount = countWords(str);
    int i = 0;
    int len = 0;
    int j;

    arr = malloc(sizeof(char*) * wordCount + 1);
    arr[wordCount] = 0;

    while (i < wordCount)
    {
        while (isBlank(*str))
            str++;
        j = 0;
        len = wordLen(str);
        arr[i] = malloc(sizeof(char) * len + 1);
        arr[i][len] = '\0';
        while (j < len)
        {
            arr[i][j] = *str;
            j++;
            str++;
        }
        i++;
    }
    return (arr);
}

char     *ftlowercase(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 'a' - 'A';
        str++;
    }
    printf("%s\n", str);
    return (str);
}

int     ftStrcmp(char *sl1, char *sl2)
{
    char *s1;
    char *s2;

    s1 = ftlowercase(sl1);
    s2 = ftlowercase(sl2);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int     main(int ac, char **av)
{
    char **arr;
    char *a = "Helloa";
    char *b = "hellm";
    int i;

    printf("%i\n", ftStrcmp(a, b));
    printf("%i\n", strcmp(a, b));
    if (ac != 2)
        return (0);
    arr = ftStringSplit(av[1]);
    i = 0;
    while (arr[i])
    {
    }
}