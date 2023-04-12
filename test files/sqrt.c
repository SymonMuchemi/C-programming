#include <stdio.h>

int _sqrt_recursive(int n)
{
    int root = 0;
    if (n < 0){
        return -1;
    }
    else{
        if (root * root > n){
            return -1;
        }
        else if (root * root == n)
        {
            return root;
        }
        else{
            root += 1;
            return _sqrt_recursive(n);
        }
    }
}

int main(void){
    int test = _sqrt_recursive(25);
    printf("%d", test);
}