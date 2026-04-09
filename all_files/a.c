#include <stdio.h>

void alternate_combine(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        result[k++] = arr1[i++];
        result[k++] = arr2[j++];
    }

    while (i < n1) {
        result[k++] = arr1[i++];
    }

    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    
    int n1 = 3;
    int n2 = 2;

    int result[n1 + n2];

    alternate_combine(arr1, n1, arr2, n2, result);

    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
