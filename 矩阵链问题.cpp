#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int t = 1000;
int a,b;
vector<int>p;
int m[t][t],s[t][t];
void Matrix() {
	for (int d=1;d<=a;d++) {
		for (int i=1;i<=a-d;i++) {
			int j=i+d;
			for (int k=i;k<j;k++) {
				int temp = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (m[i][j] > temp) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	cout<<"最优解为："<<m[1][a]<<endl;
}
void Print(int l,int r) {
	if (l==r) {
		cout<<"A"<<l;
		return;
	}
	cout<<"(";
	Print(l,s[l][r]);
	Print(s[l][r]+1,r);
	cout<<")";
}

int main() {
	memset(m,inf,sizeof m);
	cin>>a;
	for (int i=0;i<=a;i++) {
		cin>>b;
		p.push_back(b);
		m[i][i] = 0;
	}
	Matrix();
	cout<<"括号化方案为："; 
	Print(1,a);
	return 0;
}

