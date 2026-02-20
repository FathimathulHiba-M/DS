
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;   // Sorted array
}

int main() {
    srand(time(NULL));

    int step = 10000;
    int maxN = 100000;

    printf("Input Size\tAverage Time (seconds)\n");

    for (int n = step; n <= maxN; n += step) {

        int *arr = (int *)malloc(n * sizeof(int));
        fillArray(arr, n);

        int trials = 100000;   // repeat to get measurable time
        clock_t start, end;
        double totalTime = 0;

        start = clock();

        for (int i = 0; i < trials; i++) {
            int key = (rand() % n) + 1;  // random number in range
            binarySearch(arr, n, key);
        }

        end = clock();
        totalTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%lf\n", n, totalTime);

        free(arr);
    }

    return 0;
}