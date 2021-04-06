#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

void merge(int f[],int t[],int left,int right) {
    int mid = left+right>>1;
    int L = left,R = mid+1,st=left;
    while (L<=mid && R<=right) {
        if (f[L]<=f[R]) {
            t[st++] = f[L++];
        } else {
            t[st++] = f[R++];
        }
    }
    while (L<=mid) t[st++] = f[L++];
    while (R<=right) t[st++] = f[R++];
    for (int i=left;i<=right;i++) {
        f[i] = t[i];
    }
}

void sort(int f[],int t[],int left,int right) {
    int mid = left+right>>1;
    if (left>=right) return;
    sort(f,t,left,mid);
    sort(f,t,mid+1,right);
    merge(f,t,left,right);
}

void MergeSort(int f[],int length) {
    int t[N]; 
    sort(f,t,1,length);
}


int main() {
    int n,f[N];
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>f[i];
    }
    MergeSort(f,n);
    for (int i=1;i<=n;i++) {
        cout<<f[i]<<" ";
    }
    cout<<endl;
}
/*
8
8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8
*/ 
