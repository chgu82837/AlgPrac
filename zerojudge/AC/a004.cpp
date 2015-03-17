#include <stdio.h>

int main(){
    int y;
    while(scanf(" %d",&y) != EOF){
        if( (!(y % 4) && (y % 100)) || !(y % 400) )
            puts("閏年\n");
        else
            puts("平年\n");
    }
    return 0;
}
