#include <stdio.h>

// Test data
/*
3
1, 5, 3, 2, 4, 6
4, 3, 3, 5, 6, 2
5, 5, 4, 2, 1, 3

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
int main(int argc, char const *argv[])
{
    int t = nextInt();
    int p,tmp;
    int a[6];
    int picking;
    bool done;
    while(t--){
        picking = 0;
        p = 0;
        done = false;
        // printf(">>>>>\n");
        for (int i = 0; i < 6; ++i)
        {
            a[i] = nextInt();
            tmp = p + a[i];
            

            if(!done){
                if(tmp < 6){
                    p = tmp;
                    picking++;
                }
                else if(tmp > 6){
                    p -= a[i - picking];
                    p += a[i];
                    // if(picking > 0) picking--;
                }
                else if(tmp == 6){
                    printf("The best combination is ");
                    for (int j = i - picking; j <= i; ++j)
                    {
                        printf("%d, ",a[j]);
                    }
                    printf("Complaint=%d\n",i - picking);
                    done = true;
                    // for (; i < 6; ++i)
                    // {
                    //     nextInt();
                    // }
                    // break;
                }
            }
            // printf("got = %d tmp = %d p = %d ,picking = %d\n",a[i],tmp,p,picking);
        }
    }
    return 0;
}

