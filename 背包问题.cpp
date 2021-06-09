#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int T = 1000;
int n,m,k;
int w[T];
int v[T];
int C[T];
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>v[i]>>w[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=w[i];j<=m;j++) {
			C[j] = max(C[j],C[j-w[i]]+v[i]);
		}
	}
	cout<<C[m]<<endl;
	return 0;
}
/*
5 10
1 5
2 4
3 3
4 2
5 1
50
*/

