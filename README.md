*Algorithm Lab Assignment*

//heapsort
#include <iostream>
using namespace std;

void MAX_HEAPIFY(int a[], int x, int n)
{
  int l,r,largest,loc;
  l=2*x;
  r=(2*x+1);
  if((l<=n)&&a[l]>a[x])
    largest=l;
  else
    largest=x;
  if((r<=n)&&(a[r]>a[largest]))
    largest=r;
  if(largest!=x)
    {
      loc=a[x];
      a[x]=a[largest];
      a[largest]=loc;
      MAX_HEAPIFY(a, largest,n);
    }
}
void CREATE_MAX_HEAP(int a[], int n)
{
  for(int k = n/2; k >= 1; k--)
    {
      MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(int a[], int n)
{

  CREATE_MAX_HEAP(a,n);
  CREATE_MAX_HEAP(a,n);
  CREATE_MAX_HEAP(a,n);
  int x, temp;
  for (x = n; x >= 2; x--)
    {
      temp = a[x];
      a[x] = a[1];
      a[1] = temp;
      MAX_HEAPIFY(a, 1, x - 1);
    }
}

int main()
{
  int n;
  cout<<"Enter the size of the array:"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the elements in the array:"<<endl;
  for (int x = 1; x <= n; x++)
    {
      cin>>a[x];
    }
  HEAPSORT(a, n);
  cout<<"SORTED FORM:"<<endl;
  for (int x = 1; x <= n; x++)
    {
      cout<<a[x]<<endl;
    }
}

//insertionsort

#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void insertionSort(int arr[], int length)
{
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}

int displayArray( int arr[], int length ) {
    printf("{");
    for( int i=0; i<length; i++ )
        printf("%d, ", arr[i] );
    printf("}\n");
}

int main( int argc, char* argv[] )
{
    int array[10] = { 5, 3, 6, 2, 1, 8, 4, 9, 7, 0 };
    size_t length = sizeof(array)/sizeof(int);
    displayArray( array, length );
    insertionSort( array, length );
    displayArray( array, length );
}


//mergesort

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


//quicksort

#include <iostream>

using namespace std;

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main()
{
    int array[] = {5, 3, 6, 2, 1, 8, 4, 9, 7, 0};
    int n = sizeof(array)/sizeof(array[0]);

    std::cout << "Before Quick Sort :" << std::endl;
    printArray(array, n);

    quickSort(array, 0, n);

    std::cout << "After Quick Sort :" << std::endl;
    printArray(array, n);
    return (0);
}


//selectionsort

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;
const int ARRAY_SIZE = 7;

void selectionSort(int list[], int length);

int main()
{
	int i;
	int arr[] = { 13, 17, 9, 14, 28, 30, 23 };

	cout << "The unsorted list is: ";

	for (i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	selectionSort(arr, ARRAY_SIZE);

	cout << "The sorted list is: ";

	for (i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

void selectionSort(int list[], int length) {
	int index;
	int smallestIndex;
	int location;
	int temp;

	for (index = 0; index < length - 1; index++) {

		smallestIndex = index;
		for (location = index + 1; location < length; location++) {
			if (list[location] < list[smallestIndex]) {
				smallestIndex = location;
			}
		}

		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
	}
}
