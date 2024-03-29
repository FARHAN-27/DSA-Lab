#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;  
using namespace std;  
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}



void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;


  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;


  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];


  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {

  int max = getMax(array, size);


  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

int main() {
    int arr[5000];
    srand(time(0));
    for (int i = 0; i < 5000; i++) {
        arr[i] = 10000 + rand() % 90000;
    }
    clock_t start_time = clock();
    radixsort(arr, 5000);
    //sselectionSort(arr, 5000);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Sorted array using radix sort followed by counting sort:" << endl;
    for (int i = 0; i < 5000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << fixed << time_taken << setprecision(5) << " seconds" << endl;
    return 0;
}
