#include <stdio.h>
#include <string.h>

// Problem here: 
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2925

/* Sample Input:
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3
1 2
0

*/

int nextInt() // unsigned only
{
    int result = 0;
    char tmp;
    while(((tmp = getchar()) < '0') || (tmp > '9')) continue;
    result = tmp - '0';
    while(((tmp = getchar()) >= '0') && (tmp <= '9'))
        result = result * 10 + tmp - '0';
    return result;
}

const char* bin2str(int x)
{
    static char b[sizeof(int) * 8];

    memset(b,0,sizeof(b));

    unsigned int z;
    int i = 0;
    for (z = 1 << (sizeof(int) * 8 - 1); z ; z >>= 1)
        // printf("%d ", z);
        b[i++] = (x & z) ? '1' : '0';

    b[i] = '\0';

    return b;
}

unsigned int P[16];
unsigned int cover[1 << 16];
unsigned int f[1 << 16];

int main(){
    // printf("[%s]\n", bin2str(2 ^ 1));
    int n,m,c = 1;
    while(n = nextInt()){

        // Input
        for (int i = 0; i < n; ++i)
        {
            m = nextInt();
            P[i] = 1 << i;
            while(m--)
                P[i] |= 1 << nextInt();
        }

        // debug input
        // printf("Input P[i]:\n");
        // for (int i = 0; i < n; ++i)
        //     printf("%d [%s]\n", i,bin2str(P[i]));

        // Create cover[S]
        // printf("cover[S]:\n");
        for (int S = 0; S < (1 << n); ++S)
        {
            cover[S] = 0;
            for (int i = 0; i < n; ++i)
                if(S & (1 << i)) cover[S] |= P[i];

            // printf("%3d %s",S,bin2str(S));
            // printf(" [%s]\n",bin2str(cover[S]));
        }

        // Find Max
        // printf("Find Max...\nS   S0:\n");
        memset(f,0,sizeof(f));
        int ALL = (1 << n) - 1;
        int tmp;
        for (int S = 0; S < (1 << n); ++S)
        {
            // printf("%s\n", bin2str(S));
            f[S] = 0;
            for (int S0 = S ; S0 ; S0 = (S0 - 1) & S)
            {
                // printf("    %s", bin2str(S0));
                tmp = f[S ^ S0] + 1;
                // printf(" : %s\n", bin2str(S ^ S0));
                if(cover[S0] == ALL && tmp > f[S]){
                    // printf("        f[%d] = %d\n", S, tmp);
                    f[S] = tmp;
                }
            }
        }

        printf("Case %d: %d\n", c++,f[ALL]);

    }
    return 0;
}
