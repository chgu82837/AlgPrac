#include <stack>
#include <stdio.h>

int main(){
    std::stack<bool> states;
    states.push(true);
    states.push(false);
    states.push(false);
    states.push(false);
    states.push(true);
    states.push(false);

    printf("%d\n",states.top()); states.pop();
    printf("%d\n",states.top()); states.pop();
    printf("%d\n",states.top()); states.pop();
    printf("%d\n",states.top()); states.pop();
    printf("%d\n",states.top()); states.pop();
    printf("%d\n",states.top()); states.pop();

    return 0;
}
