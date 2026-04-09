#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int found = -1;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                found = arr[i];
                break;
            }
        }
        if(found != -1)
            break;
    }

    if(found != -1)
        printf("First repeating element: %d\n", found);
    else
        printf("No repeating element\n");

    return 0;
}
