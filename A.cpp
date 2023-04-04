#include<bits/stdc++.h>

using namespace std;

int main(){
    


    int n;

    cin>>n;

    int num[n];
    int num2[n];
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
        num2[i]=num[i];
    }
    sort(num2,num2+n);

   // int target=num2[0] ;
   

    int left = 0;
    int right = n-1;

    int mid;

    while (left<right)
    {
        mid = (left+right)/2;
    
        if(num[mid]>num[right])  {
            
            left=mid+1;
            
        }

        else if(num[mid]<num[right]){
             

           right = mid;
        }

    //     else{
    //         num[right];
    //    }
            
    }
  cout<<num[left]<<endl;
    cout<<"the original array is :";

    for (int i = 0; i < n; i++)
    {
        cout<<num2[i]<<" ";
    }
    cout<<endl;

}