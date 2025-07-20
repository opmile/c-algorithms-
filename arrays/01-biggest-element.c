#include <stdio.h>
#include <stdlib.h>

int biggestElement(int *arr, int len);

int secondBiggestElement(int *arr, int len);

int* pointerBiggestElement(int *arr, int len);

int main() {
    int nums[] = {1, 12, 51, 27, 91, 17};
    int len = sizeof(nums) / sizeof(nums[0]);

    printf("maior elemento: %d\n", biggestElement(nums, len));
    printf("segundo maior elemento: %d\n", secondBiggestElement(nums, len));

    int *ptr = pointerBiggestElement(nums, len);
    *ptr = 92;

    printf("maior elemento: %d\n", biggestElement(nums, len));
    
    return 0;
}

int biggestElement(int *arr, int len) {
    int biggest = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] > biggest) {
            biggest = arr[i];
        }
    }
    return biggest;
}

int* pointerBiggestElement(int *arr, int len) {
    int *biggest = &arr[0];

    for (int i = 0; i < len; i++) {
        if (arr[i] > *biggest) {
            biggest = &arr[i];
        }
    }
    return biggest;
}

int secondBiggestElement(int *arr, int len) {
    int biggest = biggestElement(arr, len);
    int secondBiggest = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] > secondBiggest && arr[i] < biggest) {
            secondBiggest = arr[i];
        }
    }
    return secondBiggest;
}