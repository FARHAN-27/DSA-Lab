#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
//    freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

    int a1[5000];
    int a2[5];
    int a3[5000];
    int a4[5000];


for (int i = 0; i < 5; i++)
{
    cin>>a1[i];
    a2[i]=a1[i];
    a3[i]=a1[i];
    a4[i]=a1[i];



}
int len = sizeof(a2) / sizeof(a2[0]);



   auto start = high_resolution_clock::now();
 
  
    cout<<"for selection sort = ";
   // selectionSort(a1,5000);
   radixsort(a2, len);
   
    //printArray(arr, n);

    cout<<endl;
     
     
    //  cout<<"for quick sort = ";
    // quicksort(a2,0,4999);

     

    //margeshort(0,5000-1);
 
   
    auto stop = high_resolution_clock::now();
 
    
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

for (int i = 0; i < 5; i++)
{
    cout<<a1[i]<<endl;
}

    
}