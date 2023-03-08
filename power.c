#include <stdio.h>

int _pow_recursion(int x, int y){
    if (y < 0)
    {
        return -1;
    } else if( y == 0){
        return 1;
    }
    y--;

    return x * _pow_recursion(x, y);
}

int main(void){

    int fivepow_neg2 = _pow_recursion(5, -2);
    int fivepow_0 = _pow_recursion(5, 0);
    printf("%d", fivepow_0);
    printf("%d", fivepow_neg2);
    
}