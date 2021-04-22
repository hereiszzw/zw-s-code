#include<bits/stdc++.h>
#include<iostream> 
using namespace std;
const int N = 1000000;
int t,m,k;
int Find(int a[],int left,int right,int k) {
	if (left==right) return a[left];
	int i = left, j = right;
	int m = a[i];
	while (i < j) {
		while (i<j && a[j]>=m){
			j--;
		}
		a[i] = a[j];
		while (i<j && a[i]<=m){
			i++;
		}
		a[j] = a[i];
	}
	a[i] = m;
	int count = i-left+1;
	if (count < k) 
	    return Find(a,i+1,right,k-count);
	return Find(a,left,i,k);
}

int main() {
	cout<<"请输入元素个数t和k的值；"<<endl; 
	cin>>t>>k;
	int a[10000];
	for (int i=1;i<=t;i++) {
		cin>>a[i];
	}
	cout<<Find(a,1,t,k)<<endl;
	return 0;
}
