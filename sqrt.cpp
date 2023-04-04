#include<bits/stdc++.h>

using namespace std;




int sqrtBinarySearch(int num, int low, int high) {
    if (num == 0 || num == 1) {
        return num;
    }

    int mid = (low + high) / 2;
    int midSquared = mid * mid;

    if (midSquared == num) {
        return mid;
    }

    if (midSquared < num) {
        return sqrtBinarySearch(num, mid + 1, high);
    }

    return sqrtBinarySearch(num, low, mid - 1);
}

int sqrt(int num) {
    return sqrtBinarySearch(num, 0, num);
}

int main(){
    cout<<sqrt(2)<<endl;
}
