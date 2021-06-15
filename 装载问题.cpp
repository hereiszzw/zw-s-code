#include <iostream>
using namespace std;
const int n=100;
int t,weight1,weight2,weight[n];
int currentw,bestw,restw; 
int result[n],bestresult[n];
int i;
void Back(int &i)
{
    while(i>1&&result[i]==0)
    {
        --i;
    }
    if(result[i]==1)
    {
        result[i] = 0;
        currentw =currentw+ weight[i];
        i =i+1;
    }
}
void Loading(int weight[])
 {
    while(i<=t)
    {
        if(currentw-weight[i]>=0)
        {
            currentw =currentw- weight[i];
            result[i] = 1;
            i =i+1;
        }
        else
        {
            result[i] = 0;
            i =i+1;
        }
    }
    if(currentw<bestw)
    {
        bestw = currentw;
        for(i=1;i<=t;i++) 
		    bestresult[i]=result[i];
    }
    Back(i);
    if(i==1)
    {
        cout<<"第一艘轮船:"<<endl;
        for(i=1;i<=t;i++) 
		    if(bestresult[i]) 
			    cout<<i<<" ";
        cout << endl;
 		cout<<"第二艘轮船:"<<endl;
        for(i=1;i<=t;i++) 
		    if(0==bestresult[i]) 
			    cout<<i<<" ";
        return;
    }   
    else
        Loading(weight);
 }
 int main()
 {

    i = 1;
	cout << "请输入集装箱的个数:";
	cin >> t;
	cout << "请输入第1艘和第2艘轮船的载重:";
	cin >> weight1>>weight2;
	cout << "请依次输入货物的重量"<<endl;
    currentw = weight1;
    bestw = weight1;
    weight[0] = 0;
    for(i=1;i<=t;i++) 
    {
        cin>>weight[i];
        restw=restw+weight[i];
    }
    i = 1;
    Loading(weight);
    return 0;
 }
/*
请输入集装箱的个数:5
请输入第1艘和第2艘轮船的载重:50 60
请依次输入货物的重量
12 5 13 20 17
第一艘轮船:
1 2 3 4
第二艘轮船:
5
*/ 
