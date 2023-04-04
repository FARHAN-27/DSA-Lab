#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;


using namespace std;

   void merge1(int a[],int d[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;
      
    int LeftArray[n1], RightArray[n2]; 
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];

    int LeftArray1[n1], RightArray1[n2]; 
    for (int i = 0; i < n1; i++)    
    LeftArray1[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray1[j] = a[mid + 1 + j];      
      
    i = 0; 
    j = 0; 
    k = beg; 
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];
             d[k] = LeftArray1[i];   
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];  
            d[k] = RightArray1[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];
        d[k] = LeftArray1[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j]; 
         d[k] = RightArray1[j];     
        j++;    
        k++;    
    }    
}    
  
  
 
void mergeSort1(int a[],int d[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort1(a,d, beg, mid);  
        mergeSort1(a,d, mid + 1, end);  
        merge1(a,d, beg, mid, end);  
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
        mergeSort1(a,d,start,end);
        
     }

    }

int main() {
    int arr[5000];
    srand(time(0));
    for (int i = 0; i < 5000; i++) {
        arr[i] = 10000 + rand() % 90000;
    }
    clock_t start_time = clock();
    radixSort(arr, 0,5000-1);
    //sselectionSort(arr, 5000);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout << "Sorted array using radix sort followed by marge sort:" << endl;
    for (int i = 0; i < 5000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << fixed << time_taken << setprecision(5) << " seconds" << endl;
    return 0;
}
