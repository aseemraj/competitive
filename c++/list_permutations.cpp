#include<bits/stdc++.h>
void permute(int n, int d, char* c)
{
    int i;
    if (d != n)
        for (i = 1; i <= n; ++i)
        {
            char s[255];
            if (c == NULL)
                sprintf(s, "%d", i);
            else
                sprintf(s, "%s%d", c, i);
            printf("%s\n", s);
            permute(n, d + 1, s);
        }
}
int main()
{
    printf("Hello. I'm a C program that generates permutations.\n");
    printf("Give a number n.");
    printf("Permutations of the set {1, 2, ..., n} will be printed sorted.\n");
    int ok = 0;
    int n;
    printf("Enter your number (n) > ");
    int r = scanf("%d",&n);
    if (r != EOF && r != 0)
        ok = 1;
    else
    {
        printf("There was an error. Give a correct number.\n");
        return 1;
    }
    permute(n, 0, 0);
    return 0;
}
