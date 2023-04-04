#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;


using namespace std;

int partition (int a[],int d[], int start, int end)  
{  
    int pivot = d[end]; 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
     
        if (d[j] < pivot)  
        {  
            i++; 
            int t = d[i];  
            d[i] = d[j];  
            d[j] = t;  
             int t1 = a[i];  
            a[i] = a[j];  
            a[j] = t1; 
        }  
       
    }  
    // cout<<" **"<<a[i]<<endl;
    int t = d[i+1];  
    d[i+1] = d[end];  
    d[end] = t;
     int t1 = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t1;  
    return (i + 1);  
}  
  
 
void quick(int a[],int d[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a,d, start, end);  
       // print(a,end+1);
        //cout<<a[p]<<" * ";
        quick(a,d, start, p - 1);  
        quick(a, d,p + 1, end);  
       
    }  
} 
void radixSort(int a[],int start,int end){
    int n=end-start+1;
    int d[n];
    int max=-INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]>max)
        max=a[i];
    }
    for(int place=1;max/place;place*=10){
        for(int i=0;i<n;i++){
            d[i]=(a[i]/place)%10;
        }
        quick(a,d,start,end);
        
     }

    }

int main() {
    int arr[5000];
    srand(time(0));
    for (int i = 0; i < 5000; i++) {
        arr[i] = 10000 + rand() % 90000;
    }
    clock_t start_time = clock();
    radixSort(arr, 0 ,5000-1);
    //sselectionSort(arr, 5000);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Sorted array using radix sort followed by quick sort:" << endl;
    for (int i = 0; i < 5000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << fixed << time_taken << setprecision(5) << " seconds" << endl;
    return 0;
}
