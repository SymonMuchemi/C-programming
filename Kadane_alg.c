#include <stdio.h>

int max_subarray(int n[]){
    int max = 0;
    int sum = 0;
    int i = 0;

    for (; i < arrayLen; i++){
        sum += n[i];

        if (sum > max){
            max = sum;
        }

        if (sum < 0){
            sum = 0;
        }
    }
    return max;
}

int main(void)
{
    int nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4} ;
    int arrayLen = sizeof(nums) / sizeof(nums[0]);

    printf("%d", max_subarray(nums));
}