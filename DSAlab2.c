#include <stdio.h>
#include<string.h>
#define MAX 100

int StringMatch(char [], char [], char [], char []);

int main()
{
    char s[MAX] = {0}, p[MAX] = {0}, r[MAX] = {0}, final[MAX] = {0};
    int found = 0;

    printf("Enter Source String:\n");
    gets(s);
    printf("Enter Pattern String:\n");
    gets(p);    
    printf("Enter Replace String:\n");
    gets(r);
    found = StringMatch(s, p, r, final);

    if (found == 1)
    {
        printf("The final string is: ");
        puts(final);
    }
    else
        printf("Search string not found\n");
    
    return 0;
}

int StringMatch(char s[], char p[], char r[], char f[])
{
    int S, P, R, F, m;
    // S-index src, P-index pattern, R-index replace, F-index final
    int found = 0;
    S = P = F = m = 0;

    while (s[S] != '\0')
    {
        if (s[m++] == p[P++])
        {
            if (p[P] == '\0')
            {
                for (R = 0; r[R] != '\0'; R++, F++)
                    f[F] = r[R];
                
                P = 0;
                S = m;
                found = 1;
            }
        }
        else
        {
            f[F++] = s[S++];
            m = S;
            P = 0;
        }
    }
    return found;
}
