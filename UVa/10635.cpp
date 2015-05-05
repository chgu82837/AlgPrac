#include <stdio.h>
#include <cstring>
#include <algorithm>

// Problem here: 
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1576

const int L = 250 * 250;
unsigned int P[L];
unsigned int Q[L];

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

unsigned int g[L];

// Text book LIS require this
// unsigned int d[L];

int main(){
    int T,n,p,q,Qn,tmp;
    T = nextInt();
    for (int c = 1; c <= T; ++c)
    {
        // input
        n = nextInt();
        n *= n;
        p = nextInt();
        q = nextInt();

        // tranlate P to 1,2,3... and make Q to coorespond to P
        memset(P,0,n * sizeof(int));
        for (int i = 0; i <= p; ++i)
            P[nextInt()] = i + 1;
        Qn = 0;
        for (int i = 0; i <= q; ++i){
            tmp = nextInt();
            if(P[tmp])
                Q[Qn++] = P[tmp];
        }

        // debug for thr translation
        // for (int i = 0; i < n; ++i)
        // {
        //     printf(" %d",P[i] );
        // }
        // putchar('\n');
        // for (int i = 0; i < Qn; ++i)
        // {
        //     printf(" %d",Q[i] );
        // }
        // putchar('\n');

        memset(g,-1,Qn * sizeof(int));

        int ans = 0;
        // For more LIS:
        // http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html
        int gn = 0;
        for (int i = 0; i < Qn; ++i)
        {
            tmp = std::lower_bound(g+1,g+gn+1,Q[i]) - g;
            g[tmp] = Q[i];
            if(tmp > ans)
                ans = gn = tmp;

            // Checkpoint
            // printf("Round %d:\ntmp = %d, ans = %d\ni g\n",i,tmp,ans);
            // for (int j = 0; j < q; ++j)
            // {
            //     printf("%d %u\n",j,g[j]);
            // }
        }

        // Text book LIS
        // int k;
        // for (int i = 0; i < Qn; ++i)
        // {
        //     k = std::lower_bound(g+1,g+n+1,Q[i]) - g;
        //     d[i] = k;
        //     g[k] = Q[i];
        //     ans = std::max(ans,d[i]);

        //     Checkpoint
        //     printf("Round %d:\nk = %d, ans = %d\ni g\n",i,k,ans);
        //     for (int j = 0; j < q; ++j)
        //     {
        //         printf("%d %d\n",j,g[j]);
        //     }
        // }

        printf("Case %d: %d\n",c,ans );
    }
    return 0;
}
