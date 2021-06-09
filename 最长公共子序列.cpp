#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int T = 1000;
char a[T],b[T];
int C[T][T];
void display(int i,int j) {
    if (i<=0 || j<=0) return;
    if (a[i] == b[j]) {
        display(i-1,j-1);
        cout<<a[i];
    } else if (C[i-1][j]>C[i][j-1]) {
        display(i-1,j);
    } else {
       display(i,j-1);
    }
}
int main() {
	
	int la,lb;
	cin>>a+1>>b+1;
	la = strlen(a+1);
	lb = strlen(b+1);
	for (int i=1;i<=la;i++) {
		for (int j=1;j<=lb;j++) {
			if (a[i] == b[j]) {
				C[i][j] = C[i-1][j-1] + 1;
			} else {
				C[i][j] = max(C[i-1][j],C[i][j-1]);
			}
		}
	}
	cout<<"length:"<<C[la][lb]<<endl;
	cout<<"公共子序列："; 
    display(la,lb);
	return 0;
}

