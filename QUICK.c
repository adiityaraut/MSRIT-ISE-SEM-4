#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = low, i = low + 1, j = high;
    while (i <= j) {
        while (i <= j && a[i] <= a[pivot])
            i++;
        while (j >= i && a[j] > a[pivot])
            j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int a[10000], n;
    clock_t start, end;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\nRandomly generated items:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
        printf("%d ", a[i]);
    }
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    printf("\nSorted list of items:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double final = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nAlgorithm time = %f seconds\n", final);
    return 0;
}
