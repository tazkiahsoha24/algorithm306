#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void displayArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void merge(int *array, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];
    k--;
    while (k >= 0)
    {
        array[k + low] = temp[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main()
{
    int array[] = {5, 3, 6, 2, 1, 8, 4, 9, 7, 0};
    int n = sizeof(array)/sizeof(array[0]);

    std::cout << "Before Merge Sort :" << std::endl;
    displayArray(array, n);

    mergeSort(array, 0, n - 1);

    std::cout << "After Merge Sort :" << std::endl;
    displayArray(array, n);
    return (0);
}
