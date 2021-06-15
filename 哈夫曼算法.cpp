#include<bits/stdc++.h>
const int T = 1000;
using namespace std;
string str;
int a,h[T];
string haf[T];

struct BNode {
	int value,id;
	bool friend operator<(const BNode &m,const BNode &n) {
		if (m.value!=n.value) 
		    return m.value>n.value;
		return m.id>n.id;
	}
};
struct Btree {
	int left;
	int right;
	int value;
}t[T];
priority_queue<BNode>f;

void fetch() {
	for (int i=1;i<=a;i++) {
		string g;
		int f = i;
		while (h[f]) {
			g = (f==t[h[f]].left?'0':'1')+g;
			f = h[f];
		}
		haf[i] = g;
	}
}
void Haf() {
	for (int i=1;i<a;i++) {	
	    int id = i+a;	
		BNode n = f.top();
		f.pop();
		BNode m = f.top();
		f.pop();
	    int value = n.value+m.value;
		t[id].left = n.id;
		t[id].right = m.id;
		t[id].value = value;
		h[n.id] = id;
		h[m.id] = id;
		f.push({value,id});
	}
	fetch();
}
int main() {
	cout<<"�������ʾ�����ڵ���ַ�����"<<endl; 
	cin>>str;
	a = str.length();
    cout<<"��������������ڵ��Ȩ��:"<<endl; 
	for (int i=1;i<=a;i++) {
		int value;
		cin>>value;
		f.push({value,i});
	}
	Haf();
	cout<<"����������Ϊ��"; 
	for (int i=1;i<=a;i++) {
		cout<<str[i-1]<<":";
		cout<<haf[i]<<endl;
	}
	return 0;
}

