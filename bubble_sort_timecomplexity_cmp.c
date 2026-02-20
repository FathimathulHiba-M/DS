#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  // random numbers
    }
}

int main() {
    srand(time(NULL));

    int step = 10000;
    int maxN = 100000;

    printf("Input Size\tTime Taken (seconds)\n");

    for (int n = step; n <= maxN; n += step) {

        int *arr = (int *)malloc(n * sizeof(int));
        fillRandom(arr, n);

        clock_t start, end;
        double timeTaken;

        start = clock();
        bubbleSort(arr, n);
        end = clock();

        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%lf\n", n, timeTaken);

        free(arr);
    }

    return 0;
}