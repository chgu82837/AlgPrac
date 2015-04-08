#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c,d;
    while(scanf(" %d %d %d",&a,&b,&c) != EOF){
        d = b*b - 4*a*c;
        if(d > 0){
            d = (int) sqrt((float) d);
            printf("Two different roots x1=%d , x2=%d\n",(-b + d) / (2*a),(-b - d) / (2*a));
        }
        else if(d == 0)
            printf("Two same roots x=%d\n",-b / (2*a));
        else
            printf("No real root\n");
    }
    return 0;
}
