#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array (optional, not used in main)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *fptr;

    // Open file to store results
    fptr = fopen("selection_sort_results.csv", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Seed random number generator
    srand(time(0));

    // Write CSV header
    fprintf(fptr, "Number of Elements,Time Taken (seconds)\n");

    // Test for different input sizes
    for (int n = 5000; n <= 50000; n += 5000) {

        // Allocate memory
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory not allocated.\n");
            fclose(fptr);
            return 1;
        }

        // Fill array with random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        clock_t start, end;
        double cpu_time_used;

        // Measure time
        start = clock();
        selectionSort(arr, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print result to console
        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

        // Write result to CSV file
        fprintf(fptr, "%d,%f\n", n, cpu_time_used);

        // Free allocated memory
        free(arr);
    }

    // Close file
    fclose(fptr);

    return 0;
}
