#include <stdio.h>
#include <stdlib.h>

void MergeSort(int array[], size_t size);
void Merge(int leftArray[], int rightArray[], int array[], size_t leftSize, size_t rightSize);

int main(int argc, char* argv[]) {
    int arr[18] = { 4, 6, 1, 542, 1, 7, 3, 1, 7, 9, 6, 2, 1, 6, 32, 12, 7, 34 };

    MergeSort(arr, sizeof(arr) / sizeof(arr[0]));

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void MergeSort(int array[], size_t size) {
    if(size <= 1) { return; }

    int middle = size / 2;
    int leftArray[middle];
    int rightArray[size - middle];

    int j = 0;

    for(int i = 0; i < size; i++) {
        if(i < middle) {
            leftArray[i] = array[i];
        } else {
            rightArray[j] = array[i];
            j++;
        }
    }

    MergeSort(leftArray, sizeof(leftArray) / sizeof(leftArray[0]));
    MergeSort(rightArray, sizeof(rightArray) / sizeof(rightArray[0]));
    Merge(leftArray, rightArray, array, sizeof(leftArray) / sizeof(leftArray[0]), sizeof(rightArray) / sizeof(rightArray[0]));
}

void Merge(int leftArray[], int rightArray[], int array[], size_t leftSize, size_t rightSize) {
    int i = 0;
    int l = 0;
    int r = 0;

    for(;l < leftSize && r < rightSize; i++) {
        if(leftArray[l] > rightArray[r]) {
            array[i] = leftArray[l];
            l++;
        } else {
            array[i] = rightArray[r];
            r++;
        }
    }

    for(;l < leftSize; i++) {
        array[i] = leftArray[l];
        l++;
    }

    for(;r < rightSize; i++) {
        array[i] = rightArray[r];
        r++;
    }
}