#include<bits/stdc++.h>


using namespace std;

double eps = 1e-6;


int binary_search(int arr[],int to_find,int lo,int hi){
    int mid = lo + (hi - lo)/2;

    while(hi>=lo){

    if(arr[mid]==to_find) return mid;

    if(arr[mid]<to_find) lo =  mid +1;

    else hi = mid -1;

}
    return -1;
}

double findSqrt(double jar_berKOrbo,double lo ,double hi){
  
     if (jar_berKOrbo < 0) {
        return nan("");
    }
    double mid;
    while (hi-lo > eps)
    {
        mid = (hi+lo)/2;    
        if(mid*mid>jar_berKOrbo) hi = mid;
         else lo = mid;
    }
    return lo;
}

double multiply(double mid,int nth){
    double ans = 1.0;
    for (int i = 0; i < nth; i++)
    {
        ans = ans * mid;
    }

    return ans;
    
}

double findNthRoot(double jar_berKOrbo,int nth,double lo ,double hi){
         
    
    double mid;
    while (hi-lo > eps)
    {
        mid = (hi+lo)/2;    
        if(multiply(mid,nth)<jar_berKOrbo) lo = mid;
         else hi = mid;
    }
    return lo;
}





int main(){


    cout<<findNthRoot(-8,3,-8,0);

    return 0;


}