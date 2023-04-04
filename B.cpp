#include<bits/stdc++.h>

using namespace std;

int main(){ 

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }

    int target ;
    cin>>target;


    int left = 0;
    int right = n-1;

    int mid;

    while (left<=right)
    {
        mid = (left+right)/2;
     //   cout<<mid<<endl;
        if(num[mid]==target)  {
            cout<<mid<<endl;
            return 0;
        }

        else if(num[mid]>=num[left]){
            if(target<=num[mid]  && target>=num[left]){
                right=mid -1;
            }  

            else left=mid+1;
        }

        else{
            if(target>=num[mid]  && target<=num[right]){
                left=mid +1;
            }  

            else right=mid-1;

        }
        //return -1;
        //cout<<"-1"<<endl;

        
    }
    cout<<"-1"<<endl;

  //  return -1;

    




    




   // cout<<4+8;

}