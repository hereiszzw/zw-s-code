#include <iostream>
using namespace std;
int n,totalTime=0,halfTime,time[100]; 
int recept[100];             //���볤��Ϊn��recept����,��ǻ����Ƿ�������� 
int **best = new int*[100];    //**best��ʾ���α��� ��best�����Ž� 
int **update = new int*[100];   //׷�����飬update����Ƿ��и������Ž� 

print(){
  
		for(int i=0;i<n+1;i++){         //������±�update����Ƿ��и������Ž⣬=1���ʾ�и���=0����
			for(int j=0;j<=halfTime;j++){
				cout<<update[i][j]<<" ";
			}
		    cout<<endl;
	    }  
	    cout<<"-------------------------------------------------------------------"<<endl;
	                                 
		for(int i=0;i<n+1;i++){           /*�൱������������Ž��*/
			for(int j=0;j<=halfTime;j++)
				cout<<best[i][j]<<" ";              
			cout<<endl;
		}	
	
		int x=n,y=halfTime;        /*�����巽��*/ 
		while(x>=0 && y>=0){
			if(update[x][y]==1){    //������µ�һ���Ž��и��� ����˵���н��ո����񣬱��Ϊ0 ��������ǰ�� 
				recept[x-1]=0;          
				y-=time[x-1];           
			}
			x--;                  //��ǰ��һ�������յ�����ʱ�� 
		}
		cout<<"����1��";
		for(int i=0;i<n;i++){	 
			if(recept[i]==0){
				cout<<"task "<<i+1<<" ";
			}
        }
		cout<<endl<<"����2��";
		for(int i=0;i<n;i++){
            if(recept[i]!=0){
				cout<<"task "<<i+1<<" ";
					}
		}
}

beibao(){			
	//���ݵݹ鹫ʽѡ�����Ž�		
	for(int i=1;i<=n;i++){ 
		for(int j=0;j<=halfTime;j++){
			if(time[i-1]<=j){             //�����ǰʱ�乻��������ʱ�� 
				int bt1 = best[i-1][j]; 
				int bt2 = best[i-1][j-time[i-1]]+time[i-1];
				if(bt2>=bt1){
					update[i][j]=1;
					best[i][j] = bt2;      //�������Ž� 
				}else{
					update[i][j]=0;
					best[i][j] = bt1;      //����֮ǰ�����Ž� 
				}
			}else{
				update[i][j]=0;
				best[i][j]=best[i-1][j];      //��ǰʱ�䲻������ʱ�䣬�������Žⲻ�� 
			}
		}
	}	
	cout<<"����1��ʱ����"; 
	cout<<best[n][halfTime]<< endl;
	cout<<"����2��ʱ����";
	cout<<totalTime-best[n][halfTime]<<endl; 
	cout<<"-------------------------------------------------------------------"<<endl;
	print();                               //��� 
}

int main(){	
	cout<<"���������������"<<endl;
	cin>>n;                          	
	cout<<"����������ÿ�������ʱ�䣺"<<endl;
	for(int i=0;i<n;i++) {
		cin>>time[i];               
		totalTime=totalTime+time[i];	        
	}		
	halfTime = totalTime/2;  
	//��ʼ����=1��ʾ����1�����ո����� 
	for(int i=0;i<n;i++){
		recept[i] = 1;        
	}
	//��ʼ����best�����Ž� ����ʼ��Ϊ0 
	for(int i=0;i<n+1;i++){
		best[i] = new int[halfTime+1];  
	}
	for(int i=0;i<n+1;i++)
		for(int j=0;j<=halfTime;j++)
			best[i][j]=0;
			
	//��ʼ��,update׷������ �����Ƿ��б��������Ž⣬��ʼΪ0���������Ϊ1 
	for(int i=0;i<n+1;i++){
		update[i] = new int[halfTime+1];
	}
	for(int i=0;i<n+1;i++)
		for(int j=0;j<=halfTime;j++)
			update[i][j]=0;	
				
	beibao(); //�����������               
	return 0;
}


