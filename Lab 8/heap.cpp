#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // Heapify subtree at root index
    int largest_value = root;
    int left = 2 * root + 1; 
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest_value]) {//check whether left node is larger than root node
        largest_value = left;
    }

    if (right < n && arr[right] > arr[largest_value]) {//check whether right node is larger than root node
        largest_value = right;
    }

    if (largest_value != root) { // make sure that if any swap happen then call heapify method
        swap(arr[root], arr[largest_value]);
        heapify(arr, n, largest_value);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
  
   // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
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
    int number_of_elements;
   cout << "Enter the number of elements you are going to give as input: " ; // get the number of elements in the input
   cin>>number_of_elements;
   int heap_arr[number_of_elements] ;
   cout << "Input array elements as space seperated string like 1 2 3 4 5 then press enter or input elements individualy by type one and press enter and next one "<<endl;
    // get input from user
   for (int i = 0; i < number_of_elements;i++){
    cin >> heap_arr[i]; 
   }
       
    cout << "***************************" <<endl;

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n); // display input array
  
   heapSort(heap_arr, n); // sort array
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n); // display sorted array
}