#include <stdio.h>

int main() 
{
    int c;
    const char* alpha = "abcdefghijklmnopqrstuvwxyz";
    int count[26] = {0};
    while ((c = getchar()) != EOF)
    {
        if ('a' <= c && c <= 'z')
        {
            ++count[c - 'a'];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        printf("%c: %d\t", alpha[i], count[i]);
        for (int j = 0; j < count[i]; ++j) printf("#");
        printf("\n");
    }
    return 0;
}