#include <iostream>
using namespace std;
int n,totalTime=0,halfTime,time[100]; 
int recept[100];             //申请长度为n的recept数组,标记机器是否接收任务 
int **best = new int*[100];    //**best表示整形变量 ，best放最优解 
int **update = new int*[100];   //追踪数组，update标记是否有更新最优解 

print(){
        cout<<"更新最优check表,有为1,无为0\n"; 
		for(int i=0;i<n+1;i++){         //输出更新表，update标记是否有更新最优解，=1则表示有更，=0则无
			for(int j=0;j<=halfTime;j++){
				cout<<update[i][j]<<" ";
			}
		    cout<<endl;
	    }  
	    cout<<"-------------------------------------------------------------------"<<endl;
	                                 
		for(int i=0;i<n+1;i++){           /*相当于输出背包最优解表*/
			for(int j=0;j<=halfTime;j++)
				cout<<best[i][j]<<" ";              
			cout<<endl;
		}	
	
		int x=n,y=halfTime;        /*求解具体方案*/ 
		while(x>=0 && y>=0){
			if(update[x][y]==1){    //如果最新的一个优解有更新 ，则说明有接收该任务，标计为0 ，并逐步向前推 
				recept[x-1]=0;          
				y-=time[x-1];           
			}
			x--;                  //往前推一个被接收的任务时间 
		}
		cout<<"机器1：";
		for(int i=0;i<n;i++){	 
			if(recept[i]==0){
				cout<<"task "<<i+1<<" ";
			}
        }
		cout<<endl<<"机器2：";
		for(int i=0;i<n;i++){
            if(recept[i]!=0){
				cout<<"task "<<i+1<<" ";
					}
		}
}

beibao(){			
	//根据递归公式选择最优解		
	for(int i=1;i<=n;i++){ 
		for(int j=0;j<=halfTime;j++){
			if(time[i-1]<=j){             //如果当前时间够任务所需时间 
				int bt1 = best[i-1][j]; 
				int bt2 = best[i-1][j-time[i-1]]+time[i-1];
				if(bt2>=bt1){
					update[i][j]=1;
					best[i][j] = bt2;      //更新最优解 
				}else{
					update[i][j]=0;
					best[i][j] = bt1;      //延续之前的最优解 
				}
			}else{
				update[i][j]=0;
				best[i][j]=best[i-1][j];      //当前时间不够任务时间，所以最优解不变 
			}
		}
	}	
	cout<<"机器1总时长："; 
	cout<<best[n][halfTime]<< endl;
	cout<<"机器2总时长：";
	cout<<totalTime-best[n][halfTime]<<endl; 
	cout<<"-------------------------------------------------------------------"<<endl;
	print();                               //输出 
}

int main(){	
	cout<<"请输入任务个数："<<endl;
	cin>>n;                          	
	cout<<"请依次输入每个任务的时间："<<endl;
	for(int i=0;i<n;i++) {
		cin>>time[i];               
		totalTime=totalTime+time[i];	        
	}		
	halfTime = totalTime/2;  
	//初始化，=1表示机器1不接收该任务 
	for(int i=0;i<n;i++){
		recept[i] = 1;        
	}
	//初始化，best放最优解 ，初始化为0 
	for(int i=0;i<n+1;i++){
		best[i] = new int[halfTime+1];  
	}
	for(int i=0;i<n+1;i++)
		for(int j=0;j<=halfTime;j++)
			best[i][j]=0;
			
	//初始化,update追加数组 ，放是否有被更新最优解，初始为0，若有则标为1 
	for(int i=0;i<n+1;i++){
		update[i] = new int[halfTime+1];
	}
	for(int i=0;i<n+1;i++)
		for(int j=0;j<=halfTime;j++)
			update[i][j]=0;	
				
	beibao(); //背包问题过程               
	return 0;
}
/*5
1 5 2 10 3
*/ 
