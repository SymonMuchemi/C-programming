#include <stdio.h>

unsigned int factorialOf(unsigned int n){

    if(n<=0){
        return 1;
    }
    return n*factorialOf(n-1);
}

int main(void)
{
    unsigned int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
     
    printf("\nThe factorial of %d is %d", number, factorialOf(number));

}