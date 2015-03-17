#include <stdio.h>

int main(){
    int l,x[4] = {0};
    scanf(" %d",&l);
    for(int i=0;i<l;i++){
        scanf(" %d %d %d %d",x,x+1,x+2,x+3);
        printf("%d %d %d %d ",x[0],x[1],x[2],x[3]);
        if(((x[0] - x[1]) == (x[1] - x[2])) && ((x[1] - x[2]) == (x[2] - x[3])))
            printf("%d\n",x[3] + (x[1] - x[0]));
        else
            printf("%d\n",x[3] * (x[1] / x[0]));
    }
    return 0;
}
