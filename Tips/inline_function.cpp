#include <stdio.h>

inline void hello(){
    printf("hello!!! \n");
}

class PL{
public:
    double k;
    PL(double a = 10.1){
        k = a;
        printf("PL constructed\n");
    }
    PL(PL*p){
        k = p->k + 1;
        printf("copied! %f\n", k);
    }

    void test();
};

void PL::test(){
    printf("[%f]\n",k);
}

void t(PL p){
    p.test();
}

int main(int argc, char const *argv[])
{
    hello();
    PL p;
    p.test();
    t(p);
    return 0;
}


