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
        cout<<"��һ���ִ�:"<<endl;
        for(i=1;i<=t;i++) 
		    if(bestresult[i]) 
			    cout<<i<<" ";
        cout << endl;
 		cout<<"�ڶ����ִ�:"<<endl;
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
	cout << "�����뼯װ��ĸ���:";
	cin >> t;
	cout << "�������1�Һ͵�2���ִ�������:";
	cin >> weight1>>weight2;
	cout << "������������������"<<endl;
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
�����뼯װ��ĸ���:5
�������1�Һ͵�2���ִ�������:50 60
������������������
12 5 13 20 17
��һ���ִ�:
1 2 3 4
�ڶ����ִ�:
5
*/ 
