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

/* C++ Program to implement Heap Sort */
