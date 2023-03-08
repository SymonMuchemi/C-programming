#include <stdio.h>

unsigned int sumDigits(unsigned int number){
    if (number == 0)
    {
        return 0;
    }

    return (number%10) + sumDigits(number/10);
}

int main(void){
    unsigned int test = 180361;

    printf("Sum of digits in the number %d is %d", test, sumDigits(test));
}