#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int N=1e9+7;

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
 void print(int a[],int n){
    for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
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

 
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


   ios_base::sync_with_stdio(0);
   cin.tie(nullptr); cout.tie(nullptr);
  
    int n;
    
    n=5000;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
   radixSort(a,0,n-1);
   print(a,n);


}