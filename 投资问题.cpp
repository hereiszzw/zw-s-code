#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int n,m,x;
int f[N][N],F[N][N];
int main() {
		cin>>n>>m;
	for (int j=0;j<=m;j++) {
		for (int i=1;i<=n;i++) {
			cin>>f[i][j];
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			for (int k=0;k<=j;k++) {
				F[i][j] = max(F[i][j],F[i-1][j-k] + f[i][k]);
			}
		}
	}
	printf("最大收益 = %d\n",F[n][m]);
	return 0;
}
