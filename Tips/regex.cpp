#include <stdio.h>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    if (regex_match ("subject", regex("(sub)(.*)")))
    {
        printf("234234\n");
    }
    printf("123\n");
    return 0;
}
