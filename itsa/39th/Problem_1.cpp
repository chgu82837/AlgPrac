#include <stdlib.h>
#include <stdio.h>

int main()
{
    int t = 0, N = 0;
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &N);
        while(N != 1)
        {
            printf("%d\n", N);

            if( N % 2 == 1)
                N = N * 3 + 1;
            else
                N = N / 2;

        }
        printf("%d\n", N);
    }


    return 0;
}
