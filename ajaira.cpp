#include <bits/stdc++.h>
using namespace std;

void bucketSort(float a[], int n) {
    int max = INT_MIN;
    for(int i=0; i<n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    int cnt = 0;
    while(max != 0) {
        max /= 10;
        cnt++;
    }
    int p = pow(10, cnt);
    vector<float> v[n];
    for(int i=0; i<n; i++) {
        int index = a[i] * n / p;
        v[index].push_back(a[i]);
    }
    for(int i=0; i<n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    int index=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<v[i].size(); j++) {
            a[index] = v[i][j];
            index++;
        }
    }
}

int main() {
    int n = 6;
    float arr[] = {1.2, 3.5, 3.9, 6.7, 8.7, 4.7};
    bucketSort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
