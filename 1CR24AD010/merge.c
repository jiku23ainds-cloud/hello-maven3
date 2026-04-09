#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *fptr;
    fptr = fopen("merge_sort_results.csv", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    srand(time(0));
    fprintf(fptr, "Number of Elements,Time Taken (seconds)\n");

    for (int n = 5000; n <= 50000; n += 5000) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
        fprintf(fptr, "%d,%f\n", n, cpu_time_used);

        free(arr);
    }

    fclose(fptr);
    return 0;
}
