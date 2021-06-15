#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int t = 1000;
int dot,color,side,f,a[t][t],c[t];
int check_ok(int x) {
	for (int i=1;i<=dot;i++) {
		if (!a[x][i]) 
		    continue;
		if (c[i] == c[x]) 
		    return 0;
	}
	return 1;
}

void dfs(int p) {
	if (p>dot) {
		f++;
		for (int i=1;i<=dot;i++) 
			cout<<c[i]<<" ";
		cout<<endl;
		return;
	}
	for (int i=1;i<=color;i++) {
		c[p] = i;
		if (check_ok(p)) 
			dfs(p+1);	
		c[p] = 0;
	}
}

int main() {
	cout<<"请输入顶点数、边数和颜色数："<<endl; 
	cin>>dot>>side>>color;
	int m,n;
	cout<<"请输入相连的节点："<<endl;
	for(int i=0;i<side;i++) {
		cin>>m>>n;
		a[m][n]=a[n][m]=1;
	}
	dfs(1);
	if (f) {
		cout<<"共有 "<<f<<" 种"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}

/*
input:
4 5 3
1 2
1 3
1 4
2 3
2 4
output:
1 2 3 3
1 3 2 2
2 1 3 3
2 3 1 1
3 1 2 2
3 2 1 1
共有 6 种
*/

