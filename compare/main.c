#include <stdio.h>
#include <time.h>
void selection_sort(int arr[], int size)
{
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++)
        {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
// ----------  Quick Sort ----------
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
// --------------------------------------------

// ---------------- Merge Sort ----------------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// --------------------------------------------------------------

int main()
{
    int sizes[] = {100, 500, 1000, 3000, 5000, 7000, 10000, 20000, 30000, 50000 , 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);



    printf(" Array_Size | Selection_Sort | Quick_Sort | Merge_Sort");
    printf("\n-------------------------------------------------------");

    for (int itt = 0 ; itt < num_sizes ; itt++)
    {
        int arr[sizes[itt]];
        int selection_arr[sizes[itt]];
        int quicksort_arr[sizes[itt]];
        int merg_arr[sizes[itt]];
        srand(time(NULL)); // seed the random number generator
        for (int i = 0; i < sizes[itt]; i++)
        {
            arr[i] = rand() % 100; // generate a random number between 0 and 99

            selection_arr[i] = arr[i];
            quicksort_arr[i] = arr[i];
            merg_arr[i] = arr[i];

        }

        /*
        printf("Unsorted array: ");
        print_list(arr,sizes[itt]);
        */


        clock_t start_time = clock();
        selection_sort(selection_arr, sizes[itt]);
        clock_t end_time = clock();

        double time_taken_selection_sort = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        start_time = clock();
        quicksort(quicksort_arr,0, sizes[itt]-1);
        end_time = clock();

        double time_taken_quick_sort = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        start_time = clock();
        mergeSort(merg_arr, 0, sizes[itt] - 1);
        end_time = clock();

        double time_taken_Merge_sort = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        /*
        printf("Sorted array [Quick Sort Array]: \n");
        print_list(quicksort_arr,sizes[itt]);

        printf("Sorted array [Selection Sort Array]: \n");
        print_list(selection_arr,sizes[itt]);

        */

    // ---------------------------------------------- [Prints] --------------------------------------------------------

        if (sizes[itt]>=1000 && sizes[itt]< 10000)
        {
            printf("\n %d       |",sizes[itt]);
            printf(" [%f]", time_taken_selection_sort);
            printf("     | [%f]", time_taken_quick_sort);
            printf(" | [%f]", time_taken_Merge_sort);
        }
        else if (sizes[itt]>=10000 && sizes[itt]< 100000)
        {
            printf("\n %d      |",sizes[itt]);
            printf(" [%f]", time_taken_selection_sort);
            printf("     | [%f]", time_taken_quick_sort);
            printf(" | [%f]", time_taken_Merge_sort);
        }
        else if (sizes[itt]>=100000 && sizes[itt]< 1000000)
        {
            printf("\n %d     |",sizes[itt]);
            printf(" [%f]", time_taken_selection_sort);
            printf("     | [%f]", time_taken_quick_sort);
            printf(" | [%f]", time_taken_Merge_sort);
        }
        else
        {
            printf("\n %d        |",sizes[itt]);
            printf(" [%f]", time_taken_selection_sort);
            printf("     | [%f]", time_taken_quick_sort);
            printf(" | [%f]", time_taken_Merge_sort);
        }

        // These Conditions are just so the columns are aligned below each other for better visualization

    }
    return 0;
}

void print_list(int arr[],int size)
{
for (int i = 0; i < size; i++)
    {
        printf("%d|", arr[i]);
    }
}

