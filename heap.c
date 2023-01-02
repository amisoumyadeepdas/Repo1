#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    printf("[");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("]");

    printf("\n");
}

int main()

{
    int i, x;
    printf("Size of the Array: ");
    scanf("%d", &x);
    printf("\n");

    printf("Enter Array elements =");
    int arr[x];
    for (i = 0; i < x; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    int N = x;

    printf("Actual Array\n");
    printArray(arr, N);

    heapSort(arr, N);

    printf("Sorted Array is\n");
    printArray(arr, N);
}
