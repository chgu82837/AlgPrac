#include <stdio.h>

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

#define max_int_len 20 // enough for 64bit uint
void printInt(int a) // unsigned only
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

int stairs(int a){
    if(a <= 2){
        if(a == 1) return 1;
        else return 2;
    }
    return stairs(a - 1) + stairs(a - 2);
}

int main(int argc, char const *argv[])
{
    int t = nextInt();
    for (int i = 0; i < t; ++i)
    {
        printInt(stairs(nextInt()));
        putchar('\n');
    }
    return 0;
}
