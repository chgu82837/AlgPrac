#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    int m, n;

    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &m, &n);

        int A[2][m][n];

        for(int j = 0; j < 2; j++)
        {
            for (int x = 0; x < m; x++)
            {
                for(int y = 0; y < n; y++)
                {
                    scanf("%d", &A[j][x][y]);
                }
            }
        }

        for (int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                A[0][x][y] = A[1][x][y] * A[0][x][y];
            }
        }


        for (int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                if(y < n - 1)
                    printf("%d ", A[0][x][y]);
                else
                    printf("%d", A[0][x][y]);
            }
            printf("\n");
        }

    }
    return 0;
}
