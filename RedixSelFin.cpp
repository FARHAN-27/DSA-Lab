#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;


using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
void selectionSort(int arr[], int n, int exp) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr[j] / exp) % 10 < (arr[minIndex] / exp) % 10) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void radixSort(int arr[], int n) {
    int maxVal = findMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        selectionSort(arr, n, exp);
    }
}
  
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

void insertion_sort(int arr[], int n) {
    int i, current, j;
    for (i = 1; i < n; i++) {
        current = arr[i];
       

 j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}


int main() {
    int arr[5000];
    srand(time(0));
    for (int i = 0; i < 5000; i++) {
        arr[i] = 10000 + rand() % 90000;
    }
    clock_t start_time = clock();
    radixSort(arr, 5000);
    //sselectionSort(arr, 5000);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Sorted array using radix sort followed by selection sort:" << endl;
    for (int i = 0; i < 5000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << fixed << time_taken << setprecision(5) << " seconds" << endl;
    return 0;
}
