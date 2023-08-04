#include <stdio.h>

void selection_sort(int arr[], int size) 
{
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 6, 1, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
