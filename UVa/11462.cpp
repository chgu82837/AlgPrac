#include <stdio.h>

int nextInt()
{
    int result = 0;
    char tmp;
    while(((tmp = getchar()) < '0') || (tmp > '9')) continue;
    result = tmp - '0';
    while(((tmp = getchar()) >= '0') && (tmp <= '9'))
        result = result * 10 + tmp - '0';
    return result;
}

#define max_int_len 30
void printInt(int a)
{
    char buf[max_int_len];
    int len = 0;
    again:
    if(a == 0) goto count_done;
    buf[len++] = a % 10 + '0';
    a /= 10;
    goto again;
    count_done:
    while(len) putchar(buf[--len]);
}

int main()
{
    int n,a;
    int age[101] = {0};
    while((n = nextInt())){
        for(int i=0 ; i < n ; i++){
            age[nextInt()]++;
        }
        a = 0;
        for(int i=1; i <= 100; i++){
            for(int j=0; j < age[i]; j++)
            {
                printInt(i);
                putchar((++a == n) ? '\n' : ' ');
            }
            age[i] = 0;
        }
        // putchar('\n');
    }
    return 0;
}
