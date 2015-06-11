#include <stdio.h>
#include <string>

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
char s[1000] = {0};
char s_t[1000] = {0};

int main(int argc, char const *argv[])
{
    int t = nextInt();
    int k;
    char* c;
    char* ct;
    char* cp;
    // bool nl = false;

    for (int i = 0; i < t; ++i)
    {
        // if(!nl){
        //     nl = true
        // }
        // else{
        //     putchar('\n');
        // }
        scanf(" %s",s);
        // gets(s);
        c = s;
        while(*c){
            if(*c == 'a'){
                k = 1;
                while(*(c+k)){
                    s_t[k] = *(c+k);
                    k++;
                }
                ct = c + 1;
                k--;
                while(k >= 1){
                    // printf("%d .. %d (%c)\n", k,s_t[k],s_t[k]);
                    *(ct++) = s_t[k];
                    k--;
                }

            }
            else if(*c == 'b'){
                k = 1;
                ct = c + 1;
                while(*(ct))
                    ct++;
                k = ct - c - 1;
                for (int j = 1; j <= k; ++j)
                {
                    *(ct++) = *(c + j);
                }
                *ct = 0;
            }
            else if(*c == 'c'){
                // *(c+1) = 0;
                ct = c + 1;
                cp = c + 3;
                k = 0;
                if(*(c+1) != 0 && *(c+2) != 0){
                    while(*cp){
                        *(ct++) = *(cp++);
                    }
                }
                *(ct) = 0;
            }
            // printf(" %d ",*c );
            putchar(*(c++));
        }
        putchar('\n');
    }

    return 0;
}
