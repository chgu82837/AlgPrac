#include <stdio.h>
#include <algorithm>

int main(){
    int m,n,coin,war_cur;
    int dra[20000];
    int war[20000];

    again:
    scanf(" %d %d",&n,&m);
    if(n==0 && m==0)
        return 0;

    for(int i = 0;i < n;i++)
        scanf(" %d",dra+i);
    for(int i = 0;i < m;i++)
        scanf(" %d",war+i);

    std::sort(dra,dra+n);
    std::sort(war,war+m);

    if(n>m)
        goto no_solution;

    // for(int i = 0;i < n;i++)
    //     printf(" %d",dra[i]);
    // putchar('\n');
    // for(int i = 0;i < m;i++)
    //     printf(" %d",war[i]);
    // putchar('\n');

    coin = 0; war_cur = -1;
    for(int i = 0; i < n;i++){
        while(++war_cur < m){
            if(war[war_cur] >= dra[i]){
                coin += war[war_cur];
                goto next_dragon;
            }
        }
        goto no_solution;
        next_dragon:
        continue;
    }

    printf("%d\n",coin);
    goto again;

    no_solution:
    printf("Loowater is doomed!\n");
    goto again;
}
