#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;       
   int left = 2 * root + 1;  
   int right = 2 * root + 2; 

   // If root is smaller than the left child 
   if (left < n && arr[left] > arr[largest])
      largest = left;

   // If current largest is smaller than the right child
   if (right < n && arr[right] > arr[largest])
      largest = right;

   // If root is  not the largest
   if (largest != root)
   {
      // Swap the root and largest 
      swap(arr[root], arr[largest]);

      //heapify recursion
      heapify(arr, n, largest);
   }   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      
      swap(arr[0], arr[i]);

      //heapify recursion
      heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  
   //modified main function
   int size;
   //enter the size of array
   cout<<"enter number of elements"<<endl;
   cin>>size;
   int heap_arr[size];
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   //enter the spaced group of numbers
   int index=0;
   for (int i = 0; i < size; ++i) {
        cin >> heap_arr[i];
   }
   
  
   heapSort(heap_arr, size);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, size);
}